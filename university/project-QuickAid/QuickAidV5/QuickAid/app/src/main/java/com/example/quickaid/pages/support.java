package com.example.quickaid.pages;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.text.Html;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;
import android.Manifest;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import com.example.quickaid.R;

public class support extends AppCompatActivity {

    private static final int REQUEST_CALL_PHONE_PERMISSION = 101;
    private String phoneNumberToCall;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.support);

        // Set up click listeners for all phone numbers
        setupClickListeners();
    }

    private void setupClickListeners() {
        // Police numbers
        setupNumberClickListener(R.id.police1, "100");
        setupNumberClickListener(R.id.police2, "112");
        setupNumberClickListener(R.id.police3, "1090");

        // Fire department numbers
        setupNumberClickListener(R.id.fire1, "101");
        setupNumberClickListener(R.id.fire2, "112");

        // Ambulance numbers
        setupNumberClickListener(R.id.ambulance1, "102");
        setupNumberClickListener(R.id.ambulance2, "108");
        setupNumberClickListener(R.id.ambulance3, "112");

        // Disaster management numbers
        setupNumberClickListener(R.id.disaster1, "1070");
        setupNumberClickListener(R.id.disaster2, "1077");

        // Other important numbers
        setupNumberClickListener(R.id.other1, "1091");
        setupNumberClickListener(R.id.other2, "1098");
        setupNumberClickListener(R.id.other3, "101");
        setupNumberClickListener(R.id.other4, "112");
    }

    private void setupNumberClickListener(int viewId, final String phoneNumber) {
        TextView textView = findViewById(viewId);

        // Get the original text
        String originalText = textView.getText().toString();

        // Add underline to just the phone number part
        String underlinedText = originalText.replace(phoneNumber, "<u>" + phoneNumber + "</u>");

        // Apply the underlined text
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N) {
            textView.setText(Html.fromHtml(underlinedText, Html.FROM_HTML_MODE_LEGACY));
        } else {
            textView.setText(Html.fromHtml(underlinedText));
        }

        textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                makePhoneCall(phoneNumber);
            }
        });
    }

    private void makePhoneCall(String phoneNumber) {
        phoneNumberToCall = phoneNumber;

        // Check if we have permission to make calls
        if (ContextCompat.checkSelfPermission(this,
                Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {

            // Request the permission
            ActivityCompat.requestPermissions(this,
                    new String[]{Manifest.permission.CALL_PHONE},
                    REQUEST_CALL_PHONE_PERMISSION);
        } else {
            // We already have permission, make the call
            startCall(phoneNumber);
        }
    }

    private void startCall(String phoneNumber) {
        Intent intent = new Intent(Intent.ACTION_CALL);
        intent.setData(Uri.parse("tel:" + phoneNumber));
        try {
            startActivity(intent);
        } catch (SecurityException e) {
            Toast.makeText(this, "Call permission denied", Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions,
                                           @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);

        if (requestCode == REQUEST_CALL_PHONE_PERMISSION) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                // Permission granted, make the call
                if (phoneNumberToCall != null) {
                    startCall(phoneNumberToCall);
                }
            } else {
                Toast.makeText(this, "Permission denied to make phone calls", Toast.LENGTH_SHORT).show();
            }
        }
    }
}