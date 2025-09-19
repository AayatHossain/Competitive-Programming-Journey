package com.example.quickaid.crimes;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import com.example.quickaid.R;
import com.example.quickaid.login.SessionManager;
import com.example.quickaid.crimes.CrimeReport;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import java.util.HashMap;

public class ReportCrimeActivity extends AppCompatActivity {

    private EditText descriptionEt, placeEt, timeEt;
    private Button submitBtn;
    private DatabaseReference crimeReportsRef, usersRef;
    private SessionManager sessionManager;
    private String currentUserPhone, currentUserName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_report_crime);

        sessionManager = new SessionManager(this);
        crimeReportsRef = FirebaseDatabase.getInstance().getReference("CrimeReports");
        usersRef = FirebaseDatabase.getInstance().getReference("Users");

        // Get current user info
        currentUserPhone = sessionManager.getPhone();
        currentUserName = sessionManager.getUsername();

        if (currentUserPhone == null || currentUserPhone.isEmpty()) {
            Toast.makeText(this, "User not logged in", Toast.LENGTH_SHORT).show();
            finish();
            return;
        }

        initializeViews();
    }

    private void initializeViews() {
        descriptionEt = findViewById(R.id.descriptionEt);
        placeEt = findViewById(R.id.placeEt);
        timeEt = findViewById(R.id.timeEt);
        submitBtn = findViewById(R.id.submitBtn);

        submitBtn.setOnClickListener(v -> submitCrimeReport());
    }

    private void submitCrimeReport() {
        String description = descriptionEt.getText().toString().trim();
        String place = placeEt.getText().toString().trim();
        String time = timeEt.getText().toString().trim();

        if (description.isEmpty()) {
            descriptionEt.setError("Description is required");
            descriptionEt.requestFocus();
            return;
        }

        if (place.isEmpty()) {
            placeEt.setError("Place is required");
            placeEt.requestFocus();
            return;
        }

        if (time.isEmpty()) {
            timeEt.setError("Time is required");
            timeEt.requestFocus();
            return;
        }

        // Create crime report
        CrimeReport crimeReport = new CrimeReport(description, place, time, currentUserPhone, currentUserName);

        // Generate unique key for the report
        String reportKey = crimeReportsRef.push().getKey();

        if (reportKey != null) {
            // Save to global crime reports
            crimeReportsRef.child(reportKey).setValue(crimeReport.toMap())
                    .addOnSuccessListener(aVoid -> {
                        // Also store in user's personal report history
                        //users - {user1} - crimereports - reportkey te set korbo crimereport1
                        usersRef.child(currentUserPhone).child("myCrimeReports").child(reportKey)
                                .setValue(crimeReport.toMap());

                        Toast.makeText(ReportCrimeActivity.this, "Crime report submitted to all users", Toast.LENGTH_SHORT).show();
                        finish();
                    })
                    .addOnFailureListener(e -> {
                        Toast.makeText(ReportCrimeActivity.this, "Failed to submit report: " + e.getMessage(), Toast.LENGTH_SHORT).show();
                    });
        }
    }
}