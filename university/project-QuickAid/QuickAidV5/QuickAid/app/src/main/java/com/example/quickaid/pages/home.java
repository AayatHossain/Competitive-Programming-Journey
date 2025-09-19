

package com.example.quickaid.pages;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import androidx.activity.OnBackPressedCallback;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import com.example.quickaid.R;
import com.example.quickaid.crimes.ReportCrimeActivity;
import com.example.quickaid.crimes.ViewCrimeReportsActivity;
import com.example.quickaid.emergency.EmergencyCallHelper;
import com.example.quickaid.emergency.HospitalMapActivity;
import com.example.quickaid.emergency.ShakeDetector;
import com.example.quickaid.emergency.sos_contact;
import com.example.quickaid.login.SessionManager;
import com.example.quickaid.login.UserLoginActivity;
import com.google.android.material.button.MaterialButton;
import com.google.android.material.card.MaterialCardView;

public class home extends AppCompatActivity implements ShakeDetector.ShakeListener{

    private TextView usernameText, welcomeText;
    private MaterialCardView logoutBtn,sos_contact_btn,sosBtn,
            nearby_hospitalbtn, health_trackerbtn, userGuidebtn, supbtn, friendbtn,reportcrimebtn,viewcrimebtn;

    private EmergencyCallHelper emergencyCallHelper;

    private SessionManager sessionManager;

    private ShakeDetector shakeDetector;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.home_design);

        sessionManager = new SessionManager(this);

        // Check if user is logged in
        if (!sessionManager.isLoggedIn()) {
            redirectToLogin();
            return;
        }




        usernameText = findViewById(R.id.usernameText);
        welcomeText = findViewById(R.id.welcomeText);
        logoutBtn = findViewById(R.id.logoutBtn);
        sos_contact_btn = findViewById(R.id.sos_contact_btn);
        sosBtn = findViewById(R.id.sos);
        nearby_hospitalbtn = findViewById((R.id.nearby_hospitals));
        health_trackerbtn = findViewById(R.id.tracker);
        userGuidebtn = findViewById(R.id.userGuide);
        supbtn = findViewById(R.id.hotlines);
        friendbtn = findViewById(R.id.friends);
        reportcrimebtn = findViewById(R.id.reportCrime);
        viewcrimebtn = findViewById(R.id.viewCrime);



        emergencyCallHelper = new EmergencyCallHelper(this);
        shakeDetector = new ShakeDetector(this, this);


        String username = sessionManager.getUsername();
        usernameText.setText("User: " + username);
        welcomeText.setText("Welcome, " + username + "!");



//        Intent intent = getIntent();
//        if (intent != null && intent.hasExtra("username")) {
//            String username = intent.getStringExtra("username");
//            usernameText.setText("User: " + username);
//            welcomeText.setText("Welcome, " + username + "!");
//        }



        logoutBtn.setOnClickListener(v -> {
            sessionManager.logout();
            Intent loginIntent = new Intent(home.this, UserLoginActivity.class);
            loginIntent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivity(loginIntent);
            finish();
        });


        sos_contact_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(home.this, sos_contact.class);
                startActivity(intent);
            }
        });

        sosBtn.setOnClickListener(v -> emergencyCallHelper.makeEmergencyCall());



        nearby_hospitalbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(home.this, HospitalMapActivity.class);
                startActivity(intent);
            }
        });

        health_trackerbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(home.this, health_trackers.class);
                startActivity(intent);
            }
        });

        userGuidebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(home.this, guide.class);
                startActivity(intent);
            }
        });

        supbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(home.this, support.class);
                startActivity(intent);
            }
        });


        friendbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(home.this, Friend.class);
                startActivity(intent);
            }
        });



        reportcrimebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(home.this, ReportCrimeActivity.class);
                startActivity(intent);
            }
        });


        viewcrimebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(home.this, ViewCrimeReportsActivity.class);
                startActivity(intent);
            }
        });






        setupBackPressedHandler();
    }


    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        emergencyCallHelper.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }


    private void setupBackPressedHandler() {
        getOnBackPressedDispatcher().addCallback(this, new OnBackPressedCallback(true) {
            @Override
            public void handleOnBackPressed() {

                moveTaskToBack(true);
            }
        });
    }

    private void redirectToLogin() {
        Intent loginIntent = new Intent(home.this, UserLoginActivity.class);
        loginIntent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
        startActivity(loginIntent);
        finish();
    }

    @Override
    protected void onResume() {
        super.onResume();
        // Start shake detection when activity is visible
        if (shakeDetector != null) {
            shakeDetector.start();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        // Stop shake detection when activity is not visible
        if (shakeDetector != null) {
            shakeDetector.stop();
        }
    }

    @Override
    public void onShakeDetected() {
        // This method is called when shake is detected
        emergencyCallHelper.makeEmergencyCall();
    }


    // @Override
    // public void onBackPressed() {

    //     moveTaskToBack(true);
    // }
}