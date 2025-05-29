/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignmentq2;

import java.util.*;

/**
 *
 * @author User
 */
public class LoggedInUsers {
    public static HashMap<String, String> users = new HashMap<>();

    public static void addUser(String id, String password) {
        users.put(id, password);
        
    }

    public static void removeUser(String id, String password) {
        if (password.equals(users.get(id))) {
            users.remove(id);
            
        }
    }

    public static void printAllUsers() {
        if (users.isEmpty()) {
            System.out.println("No users are currently logged in.");
            return;
        }
    
        System.out.println("Logged-in users:");
        for (Map.Entry<String, String> entry : users.entrySet()) {
            System.out.println("ID: " + entry.getKey() + ", Password: " + entry.getValue());
        }
    }
}
