package com.example.quickaid.login;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import com.example.quickaid.R;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import java.util.HashMap;

public class UserRegisterActivity extends AppCompatActivity {

    EditText usernameEt, phoneEt, passwordEt, ageEt;
    Button registerBtn;
    DatabaseReference usersRef;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.user_register);

        usernameEt = findViewById(R.id.usernameEt);
        phoneEt = findViewById(R.id.phoneEt);
        passwordEt = findViewById(R.id.passwordEt);
        ageEt = findViewById(R.id.ageEt);
        registerBtn = findViewById(R.id.registerBtn);

        usersRef = FirebaseDatabase.getInstance().getReference("Users");

        registerBtn.setOnClickListener(v -> {
            String username = usernameEt.getText().toString().trim();
            String phone = phoneEt.getText().toString().trim();
            String password = passwordEt.getText().toString().trim();
            String age = ageEt.getText().toString().trim();

            if (TextUtils.isEmpty(username)) {
                usernameEt.setError("Username is required");
                usernameEt.requestFocus();
                return;
            }

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

            if (password.length() < 6) {
                passwordEt.setError("Password should be at least 6 characters");
                passwordEt.requestFocus();
                return;
            }

            if (TextUtils.isEmpty(age)) {
                ageEt.setError("Age is required");
                ageEt.requestFocus();
                return;
            }

            Toast.makeText(this, "Registering...", Toast.LENGTH_SHORT).show();

            HashMap<String, Object> userMap = new HashMap<>();
            userMap.put("username", username);
            userMap.put("phone", phone);
            userMap.put("password", password);
            userMap.put("age", age);

            usersRef.child(phone).setValue(userMap)
                    .addOnCompleteListener(task -> {
                        if (task.isSuccessful()) {
                            Toast.makeText(UserRegisterActivity.this, "Registration completed", Toast.LENGTH_SHORT).show();
                            Intent intent = new Intent(UserRegisterActivity.this, UserLoginActivity.class);
                            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_NEW_TASK);
                            startActivity(intent);
                            finish();
                        } else {
                            Toast.makeText(UserRegisterActivity.this, "Registration failed: " + task.getException().getMessage(), Toast.LENGTH_LONG).show();
                        }
                    })
                    .addOnFailureListener(e -> {
                        Toast.makeText(UserRegisterActivity.this, "Error: " + e.getMessage(), Toast.LENGTH_LONG).show();
                    });
        });
    }
}
