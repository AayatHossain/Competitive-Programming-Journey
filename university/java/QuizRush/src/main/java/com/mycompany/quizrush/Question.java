/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quizrush;

/**
 *
 * @author User
 */
class Question {
    String text;
    String[] options;
    int correctIndex;

    Question(String text, String[] options, int correctIndex) {
        this.text = text;
        this.options = options;
        this.correctIndex = correctIndex;
    }

    public boolean isCorrect(int answer) {
        return answer == correctIndex;
    }

    public void display() {
        System.out.println(text);
        for (int i = 0; i < options.length; i++) {
            System.out.println((i+1) + ". " + options[i]);
        }
    }
}
