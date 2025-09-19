package com.example.quickaid.emergency;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Vibrator;
import android.util.Log;

public class ShakeDetector implements SensorEventListener {

    public interface ShakeListener {
        void onShakeDetected();
    }

    private static final String TAG = "ShakeDetector";
    private static final float SHAKE_THRESHOLD = 1500.0f; // Lowered for better sensitivity
    private static final int SHAKE_SLOP_TIME_MS = 500;
    private static final int SHAKE_COUNT_RESET_TIME_MS = 3000;

    private long mLastShakeTime = 0;
    private long mLastUpdate = 0;
    private float mLastX = 0, mLastY = 0, mLastZ = 0;
    private int mShakeCount = 0;

    private final SensorManager mSensorManager;
    private final Sensor mAccelerometer;
    private final Vibrator mVibrator;
    private final ShakeListener mShakeListener;
    private boolean isEnabled = true;

    public ShakeDetector(Context context, ShakeListener listener) {
        mSensorManager = (SensorManager) context.getSystemService(Context.SENSOR_SERVICE);
        mAccelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        mVibrator = (Vibrator) context.getSystemService(Context.VIBRATOR_SERVICE);
        mShakeListener = listener;

        // Initialize last update time
        mLastUpdate = System.currentTimeMillis();
    }

    public void start() {
        if (mAccelerometer != null) {
            mSensorManager.registerListener(this, mAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);
            Log.d(TAG, "Shake detection started");
        } else {
            Log.e(TAG, "Accelerometer sensor not available");
        }
    }

    public void stop() {
        mSensorManager.unregisterListener(this);
        Log.d(TAG, "Shake detection stopped");
    }

    public void setEnabled(boolean enabled) {
        this.isEnabled = enabled;
    }

    public boolean isEnabled() {
        return isEnabled;
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        if (!isEnabled || event.sensor.getType() != Sensor.TYPE_ACCELEROMETER) {
            return;
        }

        long currentTime = System.currentTimeMillis();
        long timeDifference = currentTime - mLastUpdate;

        if (timeDifference > 100) { // Check every 100ms
            float x = event.values[0];
            float y = event.values[1];
            float z = event.values[2];

            // Calculate movement speed correctly
            float deltaX = Math.abs(x - mLastX);
            float deltaY = Math.abs(y - mLastY);
            float deltaZ = Math.abs(z - mLastZ);

            // Check if device is moving significantly
            if (deltaX + deltaY + deltaZ > 0.5f) {
                float speed = (deltaX + deltaY + deltaZ) / timeDifference * 10000;

                if (speed > SHAKE_THRESHOLD) {
                    long now = System.currentTimeMillis();

                    // Reset shake count if it's been too long
                    if (mLastShakeTime + SHAKE_COUNT_RESET_TIME_MS < now) {
                        mShakeCount = 0;
                    }

                    // Ignore shakes too close together
                    if (mLastShakeTime + SHAKE_SLOP_TIME_MS > now) {
                        return;
                    }

                    mLastShakeTime = now;
                    mShakeCount++;

                    Log.d(TAG, "Shake detected: " + mShakeCount + ", speed: " + speed);

                    // Require 2 shakes within 3 seconds to trigger
                    if (mShakeCount >= 2) {
                        mShakeCount = 0;
                        triggerShake();
                    }
                }
            }

            mLastX = x;
            mLastY = y;
            mLastZ = z;
            mLastUpdate = currentTime;
        }
    }

    private void triggerShake() {
        Log.d(TAG, "Triggering emergency call from shake");

        // Vibrate for feedback
        if (mVibrator != null && mVibrator.hasVibrator()) {
            mVibrator.vibrate(200);
        }

        // Notify listener
        if (mShakeListener != null) {
            mShakeListener.onShakeDetected();
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
        // Not used
    }
}