/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quizrush;

/**
 *
 * @author User
 */
class User {
    String username;
    int score;

    User(String username) {
        this.username = username;
        this.score = 0;
    }

    public void viewScore() {
        System.out.println(username + "'s total points: " + score);
    }
}
