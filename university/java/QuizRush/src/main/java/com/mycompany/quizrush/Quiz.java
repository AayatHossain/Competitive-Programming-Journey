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
class Quiz {
    String genre;
    List<Question> questions = new ArrayList<>();

    Quiz(String genre) {
        this.genre = genre;
    }

    public void addQuestion(Question q) {
        questions.add(q);
    }

    public List<Question> getRandomQuestions() {
        List<Question> copy = new ArrayList<>(questions);
        Collections.shuffle(copy);
        return copy.subList(0, Math.min(10, copy.size()));
    }
}

class MovieQuiz extends Quiz {
    MovieQuiz() { super("Movie"); }
}

class GameQuiz extends Quiz {
    GameQuiz() { super("Game"); }
}

class SportsQuiz extends Quiz {
    SportsQuiz() { super("Sports"); }
}

class ScienceQuiz extends Quiz {
    ScienceQuiz() { super("Science"); }
}

class HistoryQuiz extends Quiz {
    HistoryQuiz() { super("History"); }
}