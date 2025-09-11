package com.example.quickaid.emergency;

import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

import com.example.quickaid.R;

public class sos_contact extends AppCompatActivity {

    private static final int PICK_CONTACT_REQUEST = 1;

    private TextView tvCurrentContact;
    private EditText etContactName, etPhoneNumber;
    private Button btnPickContact, btnSaveContact, btnRemoveContact;


    private static final String PREFS_NAME = "SosContactPrefs";
    private static final String KEY_CONTACT_NAME = "contact_name";
    private static final String KEY_PHONE_NUMBER = "phone_number";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.sos_contact);

        initializeViews();
        setupClickListeners();
        loadSavedContact();
    }

    private void initializeViews() {
        tvCurrentContact = findViewById(R.id.tvCurrentContact);
        etContactName = findViewById(R.id.etContactName);
        etPhoneNumber = findViewById(R.id.etPhoneNumber);
        btnPickContact = findViewById(R.id.btnPickContact);
        btnSaveContact = findViewById(R.id.btnSaveContact);
        btnRemoveContact = findViewById(R.id.btnRemoveContact);
    }

    private void setupClickListeners() {
        btnPickContact.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                pickContactFromPhone();
            }
        });

        btnSaveContact.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                saveEmergencyContact();
            }
        });

        btnRemoveContact.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                removeEmergencyContact();
            }
        });
    }

    private void pickContactFromPhone() {
        Intent intent = new Intent(Intent.ACTION_PICK, ContactsContract.CommonDataKinds.Phone.CONTENT_URI);
        startActivityForResult(intent, PICK_CONTACT_REQUEST);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == PICK_CONTACT_REQUEST && resultCode == RESULT_OK) {
            Uri contactUri = data.getData();
            String[] projection = {
                    ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME,
                    ContactsContract.CommonDataKinds.Phone.NUMBER
            };

            try (Cursor cursor = getContentResolver().query(contactUri, projection, null, null, null)) {
                if (cursor != null && cursor.moveToFirst()) {
                    int nameIndex = cursor.getColumnIndex(ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME);
                    int numberIndex = cursor.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER);

                    String name = cursor.getString(nameIndex);
                    String number = cursor.getString(numberIndex);

                    etContactName.setText(name);
                    etPhoneNumber.setText(number);
                }
            }
        }
    }

    private void saveEmergencyContact() {
        String name = etContactName.getText().toString().trim();
        String phone = etPhoneNumber.getText().toString().trim();

        if (name.isEmpty() || phone.isEmpty()) {
            Toast.makeText(this, "Please enter both name and phone number", Toast.LENGTH_SHORT).show();
            return;
        }


        getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .edit()
                .putString(KEY_CONTACT_NAME, name)
                .putString(KEY_PHONE_NUMBER, phone)
                .apply();


        tvCurrentContact.setText(name + " - " + phone);
        btnRemoveContact.setVisibility(View.VISIBLE);


        etContactName.setText("");
        etPhoneNumber.setText("");

        Toast.makeText(this, "Emergency contact saved successfully", Toast.LENGTH_SHORT).show();
    }

    private void removeEmergencyContact() {

        getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .edit()
                .remove(KEY_CONTACT_NAME)
                .remove(KEY_PHONE_NUMBER)
                .apply();


        tvCurrentContact.setText("No emergency contact set");
        btnRemoveContact.setVisibility(View.GONE);

        Toast.makeText(this, "Emergency contact removed", Toast.LENGTH_SHORT).show();
    }

    private void loadSavedContact() {
        String name = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getString(KEY_CONTACT_NAME, null);
        String phone = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getString(KEY_PHONE_NUMBER, null);

        if (name != null && phone != null) {
            tvCurrentContact.setText(name + " - " + phone);
            btnRemoveContact.setVisibility(View.VISIBLE);
        }
    }


    public static String getEmergencyContactName(AppCompatActivity activity) {
        return activity.getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .getString(KEY_CONTACT_NAME, null);
    }


    public static String getEmergencyPhoneNumber(AppCompatActivity activity) {
        return activity.getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .getString(KEY_PHONE_NUMBER, null);
    }


    public static boolean hasEmergencyContact(AppCompatActivity activity) {
        return getEmergencyContactName(activity) != null &&
                getEmergencyPhoneNumber(activity) != null;
    }
}