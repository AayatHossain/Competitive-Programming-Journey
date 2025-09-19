package com.example.quickaid.login;

import java.util.HashMap;

public class User {
    private String username;
    private String phone;
    private String password;
    private String age;
    private HashMap<String, Boolean> friends;
    private HashMap<String, Boolean> friendRequests;
    private HashMap<String, Boolean> sentRequests;

    private HashMap<String, Object> crimeReports;

    public User() {
        // Default constructor required for Firebase
    }

    public User(String username, String phone, String password, String age) {
        this.username = username;
        this.phone = phone;
        this.password = password;
        this.age = age;
        this.friends = new HashMap<>();
        this.friendRequests = new HashMap<>();
        this.sentRequests = new HashMap<>();
    }

    // Getters and setters
    public String getUsername() { return username; }
    public void setUsername(String username) { this.username = username; }

    public String getPhone() { return phone; }
    public void setPhone(String phone) { this.phone = phone; }

    public String getPassword() { return password; }
    public void setPassword(String password) { this.password = password; }

    public String getAge() { return age; }
    public void setAge(String age) { this.age = age; }

    public HashMap<String, Boolean> getFriends() { return friends; }
    public void setFriends(HashMap<String, Boolean> friends) { this.friends = friends; }

    public HashMap<String, Boolean> getFriendRequests() { return friendRequests; }
    public void setFriendRequests(HashMap<String, Boolean> friendRequests) { this.friendRequests = friendRequests; }

    public HashMap<String, Boolean> getSentRequests() { return sentRequests; }
    public void setSentRequests(HashMap<String, Boolean> sentRequests) { this.sentRequests = sentRequests; }

    public HashMap<String, Object> getCrimeReports() { return crimeReports; }
    public void setCrimeReports(HashMap<String, Object> crimeReports) { this.crimeReports = crimeReports; }
}