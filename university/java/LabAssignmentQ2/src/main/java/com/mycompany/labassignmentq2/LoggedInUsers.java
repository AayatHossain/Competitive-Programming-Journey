/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignmentq2;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author User
 */
class pair{
    String id;
    String password;
    pair(String id, String password){
        this.id = id;
        this.password = password;
    }
    
}
public class LoggedInUsers {
    public static List<pair> users = new ArrayList<>();
    public void addUser(String id, String password){
        pair p = new pair(id, password);
        users.add(p);
    }
    public void removeUser(String id, String password){
        pair p = new pair(id, password);
        for(pair currentUser : users){
            if(currentUser.id==id && currentUser.password==password){
                users.remove(p);
            }
        }
    }
}
