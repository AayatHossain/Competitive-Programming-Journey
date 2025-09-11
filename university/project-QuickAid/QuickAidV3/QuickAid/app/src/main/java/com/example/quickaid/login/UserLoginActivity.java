package com.example.quickaid.login;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import com.example.quickaid.R;
import com.example.quickaid.pages.home;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class UserLoginActivity extends AppCompatActivity {

    EditText phoneEt, passwordEt;
    Button loginBtn, guestBtn;
    TextView loginAsAdmin, registerLink;
    DatabaseReference usersRef;

    private SessionManager sessionManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login_user);

        //managing session
        sessionManager = new SessionManager(this);
        if (sessionManager.isLoggedIn()) {
            redirectToHome();
            return;
        }


        phoneEt = findViewById(R.id.phoneEt);
        passwordEt = findViewById(R.id.passwordEt);
        loginBtn = findViewById(R.id.loginBtn);
        loginAsAdmin = findViewById(R.id.loginAsAdmin);
        registerLink = findViewById(R.id.registerLink);
        guestBtn = findViewById(R.id.guest);

        usersRef = FirebaseDatabase.getInstance().getReference("Users");


        loginBtn.setOnClickListener(v -> {
            String phone = phoneEt.getText().toString().trim();
            String password = passwordEt.getText().toString().trim();

            if (TextUtils.isEmpty(phone)) {
                phoneEt.setError("Phone number is required");
                phoneEt.requestFocus();
                return;
            }

            if (TextUtils.isEmpty(password)) {
                passwordEt.setError("Password is required");
                passwordEt.requestFocus();
                return;
            }


            Toast.makeText(this, "Logging in...", Toast.LENGTH_SHORT).show();

            usersRef.child(phone).addListenerForSingleValueEvent(new ValueEventListener() {
                @Override
                public void onDataChange(@NonNull DataSnapshot snapshot) {
                    if (snapshot.exists()) {
                        String storedPass = snapshot.child("password").getValue(String.class);
                        if (password.equals(storedPass)) {
                            String username = snapshot.child("username").getValue(String.class);

                            //save info for session
                            sessionManager.createLoginSession(phone, username);

                            Toast.makeText(UserLoginActivity.this, "User login successful", Toast.LENGTH_SHORT).show();
                            Intent intent = new Intent(UserLoginActivity.this, com.example.quickaid.pages.home.class);
                            intent.putExtra("phone", phone);
                            intent.putExtra("username", username); // pass username
                            startActivity(intent);
                            finish();
                        } else {
                            Toast.makeText(UserLoginActivity.this, "Incorrect password", Toast.LENGTH_SHORT).show();
                        }
                    } else {
                        Toast.makeText(UserLoginActivity.this, "No user found with this phone number", Toast.LENGTH_SHORT).show();
                    }
                }

                @Override
                public void onCancelled(@NonNull DatabaseError error) {
                    Toast.makeText(UserLoginActivity.this, "Error: " + error.getMessage(), Toast.LENGTH_SHORT).show();
                }
            });
        });



        guestBtn.setOnClickListener(v -> {
            sessionManager.createGuestSession();
            Toast.makeText(UserLoginActivity.this, "Continuing as guest", Toast.LENGTH_SHORT).show();
            redirectToHome();
        });

        loginAsAdmin.setOnClickListener(v -> {
            startActivity(new Intent(this, AdminLoginActivity.class));
        });

        registerLink.setOnClickListener(v -> {
            startActivity(new Intent(this, UserRegisterActivity.class));
        });
    }

    private void redirectToHome() {
        Intent intent = new Intent(UserLoginActivity.this, home.class);
        intent.putExtra("username", sessionManager.getUsername());
        if (!sessionManager.isGuest()) {
            intent.putExtra("phone", sessionManager.getPhone());
        }
        startActivity(intent);
        finish();
    }
}