/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quizrush;

/**
 *
 * @author User
 */
class QuizGiver extends User {
    int level;

    QuizGiver(String username) {
        super(username);
        this.level = 1;
    }

    public void updateScore(int points) {
        this.score += points;
        updateLevel();
    }

    private void updateLevel() {
        if (score >= 100) level = 5;
        else if (score >= 75) level = 4;
        else if (score >= 50) level = 3;
        else if (score >= 25) level = 2;
    }

    public void showLevel() {
        System.out.println(username + "'s current level: " + level);
    }
}
