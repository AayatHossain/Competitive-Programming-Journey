/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quizrush;

import java.util.*;

/**
 *
 * @author User
 */
class AdminQuizSetter extends QuizSetter {
    AdminQuizSetter(String username) {
        super(username);
    }

    public void deleteQuiz(List<Quiz> allQuizzes, Quiz quiz) {
        allQuizzes.remove(quiz);
        System.out.println("Quiz removed by Admin.");
    }
}

