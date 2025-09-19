//
package com.example.quickaid.login;

import androidx.appcompat.app.AppCompatActivity;

//
//
//
public class AdminLoginActivity extends AppCompatActivity {
//    EditText phoneEt, passwordEt;
//    Button loginBtn;
//    DatabaseReference adminRef;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_admin_login);
//
//        phoneEt = findViewById(R.id.phoneEt);
//        passwordEt = findViewById(R.id.passwordEt);
//        loginBtn = findViewById(R.id.loginBtn);
//
//        adminRef = FirebaseDatabase.getInstance().getReference("Admins");
//
//        loginBtn.setOnClickListener(v -> {
//            String phone = phoneEt.getText().toString();
//            String password = passwordEt.getText().toString();
//
//            adminRef.child(phone).get().addOnCompleteListener(task -> {
//                if(task.isSuccessful() && task.getResult().exists()) {
//                    String storedPass = task.getResult().child("password").getValue(String.class);
//                    if(password.equals(storedPass)) {
//                        Toast.makeText(this, "Admin login successful", Toast.LENGTH_SHORT).show();
//                        // open Admin Dashboard Activity
//                    } else {
//                        Toast.makeText(this, "Incorrect password", Toast.LENGTH_SHORT).show();
//                    }
//                } else {
//                    Toast.makeText(this, "Admin not found", Toast.LENGTH_SHORT).show();
//                }
//            });
//        });
//    }
}
