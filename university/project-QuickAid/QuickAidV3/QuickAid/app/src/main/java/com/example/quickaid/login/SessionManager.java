package com.example.quickaid.login;

import android.content.Context;
import android.content.SharedPreferences;

public class SessionManager {
    private static final String PREF_NAME = "QuickAidSession";
    private static final String KEY_IS_LOGGED_IN = "isLoggedIn";
    private static final String KEY_PHONE = "phone";
    private static final String KEY_USERNAME = "username";
    private static final String KEY_IS_GUEST = "isGuest";

    private SharedPreferences pref;
    private SharedPreferences.Editor editor;
    private Context context;

    public SessionManager(Context context) {
        this.context = context;
        pref = context.getSharedPreferences(PREF_NAME, Context.MODE_PRIVATE);
        editor = pref.edit();
    }

    public void createLoginSession(String phone, String username) {
        editor.putBoolean(KEY_IS_LOGGED_IN, true);
        editor.putBoolean(KEY_IS_GUEST, false);
        editor.putString(KEY_PHONE, phone);
        editor.putString(KEY_USERNAME, username);
        editor.commit();
    }

    public void createGuestSession() {
        editor.putBoolean(KEY_IS_LOGGED_IN, true);
        editor.putBoolean(KEY_IS_GUEST, true);
        editor.putString(KEY_USERNAME, "Guest User");
        editor.commit();
    }

    public boolean isLoggedIn() {
        return pref.getBoolean(KEY_IS_LOGGED_IN, false);
    }

    public boolean isGuest() {
        return pref.getBoolean(KEY_IS_GUEST, false);
    }

    public String getPhone() {
        return pref.getString(KEY_PHONE, "");
    }

    public String getUsername() {
        return pref.getString(KEY_USERNAME, "");
    }

    public void logout() {
        editor.clear();
        editor.commit();
    }
}