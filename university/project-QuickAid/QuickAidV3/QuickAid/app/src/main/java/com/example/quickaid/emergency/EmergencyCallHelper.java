package com.example.quickaid.emergency;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.widget.Toast;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import com.example.quickaid.emergency.sos_contact;

public class EmergencyCallHelper {

    private static final int PERMISSION_REQUEST_CALL_PHONE = 101;
    private final AppCompatActivity activity;

    public EmergencyCallHelper(AppCompatActivity activity) {
        this.activity = activity;
    }


    public void makeEmergencyCall() {

        if (!sos_contact.hasEmergencyContact(activity)) {
            Toast.makeText(activity, "No emergency contact saved. Please set up emergency contact first.", Toast.LENGTH_LONG).show();


            Intent intent = new Intent(activity, sos_contact.class);
            activity.startActivity(intent);
            return;
        }


        String phoneNumber = sos_contact.getEmergencyPhoneNumber(activity);

        if (phoneNumber == null || phoneNumber.isEmpty()) {
            Toast.makeText(activity, "No emergency number found", Toast.LENGTH_SHORT).show();
            return;
        }


        if (ContextCompat.checkSelfPermission(activity, android.Manifest.permission.CALL_PHONE)
                != PackageManager.PERMISSION_GRANTED) {


            ActivityCompat.requestPermissions(activity,
                    new String[]{android.Manifest.permission.CALL_PHONE},
                    PERMISSION_REQUEST_CALL_PHONE);
        } else {

            initiatePhoneCall(phoneNumber);
        }
    }


    private void initiatePhoneCall(String phoneNumber) {
        try {
            Intent callIntent = new Intent(Intent.ACTION_CALL);
            callIntent.setData(Uri.parse("tel:" + phoneNumber));
            activity.startActivity(callIntent);


            String contactName = sos_contact.getEmergencyContactName(activity);
            String message = "Calling " + (contactName != null ? contactName : "emergency contact");
            Toast.makeText(activity, message, Toast.LENGTH_SHORT).show();

        } catch (SecurityException e) {
            Toast.makeText(activity, "Permission denied for making calls", Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
            Toast.makeText(activity, "Failed to make call: " + e.getMessage(), Toast.LENGTH_SHORT).show();
        }
    }


    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if (requestCode == PERMISSION_REQUEST_CALL_PHONE) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                String phoneNumber = sos_contact.getEmergencyPhoneNumber(activity);
                if (phoneNumber != null) {
                    initiatePhoneCall(phoneNumber);
                }
            } else {
                Toast.makeText(activity, "Permission denied. Cannot make emergency call.", Toast.LENGTH_SHORT).show();
            }
        }
    }
}