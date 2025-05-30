/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quizrush;

/**
 *
 * @author User
 */
class QuizSetter extends User {
    QuizSetter(String username) {
        super(username);
    }

    public void addQuestion(Quiz quiz, Question q) {
        quiz.addQuestion(q);
    }
}
