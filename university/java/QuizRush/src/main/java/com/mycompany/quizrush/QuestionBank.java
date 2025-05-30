/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quizrush;

/**
 *
 * @author User
 */
class QuestionBank {
    public static MovieQuiz getMovieQuiz() {
        MovieQuiz quiz = new MovieQuiz();
        quiz.addQuestion(new Question("Who directed 'Inception'?",
                new String[]{"Christopher Nolan", "James Cameron", "Spielberg", "Tarantino"}, 0));
        quiz.addQuestion(new Question("In 'Titanic', who played Jack?",
                new String[]{"Brad Pitt", "Leonardo DiCaprio", "Tom Cruise", "Matt Damon"}, 1));
        quiz.addQuestion(new Question("In 'Titanic', who played Jack?",
                new String[]{"Brad Pitt", "Leonardo DiCaprio", "Tom Cruise", "Matt Damon"}, 1));
        quiz.addQuestion(new Question("In 'Titanic', who played Jack?",
                new String[]{"Brad Pitt", "Leonardo DiCaprio", "Tom Cruise", "Matt Damon"}, 1));
        quiz.addQuestion(new Question("In 'Titanic', who played Jack?",
                new String[]{"Brad Pitt", "Leonardo DiCaprio", "Tom Cruise", "Matt Damon"}, 1));
       
        return quiz;
    }

    public static GameQuiz getGameQuiz() {
        GameQuiz quiz = new GameQuiz();
        quiz.addQuestion(new Question("What is the highest-selling video game ever?",
                new String[]{"GTA V", "Minecraft", "Fortnite", "Tetris"}, 1));
        quiz.addQuestion(new Question("What is the highest-selling video game ever?",
                new String[]{"GTA V", "Minecraft", "Fortnite", "Tetris"}, 1));
        quiz.addQuestion(new Question("What is the highest-selling video game ever?",
                new String[]{"GTA V", "Minecraft", "Fortnite", "Tetris"}, 1));
        quiz.addQuestion(new Question("What is the highest-selling video game ever?",
                new String[]{"GTA V", "Minecraft", "Fortnite", "Tetris"}, 1));
        quiz.addQuestion(new Question("What is the highest-selling video game ever?",
                new String[]{"GTA V", "Minecraft", "Fortnite", "Tetris"}, 1));
       
        return quiz;
    }

    public static SportsQuiz getSportsQuiz() {
        SportsQuiz quiz = new SportsQuiz();
        quiz.addQuestion(new Question("Who has won the most Olympic gold medals?",
                new String[]{"Usain Bolt", "Michael Phelps", "Simone Biles", "Carl Lewis"}, 1));
        quiz.addQuestion(new Question("Who has won the most Olympic gold medals?",
                new String[]{"Usain Bolt", "Michael Phelps", "Simone Biles", "Carl Lewis"}, 1));
        quiz.addQuestion(new Question("Who has won the most Olympic gold medals?",
                new String[]{"Usain Bolt", "Michael Phelps", "Simone Biles", "Carl Lewis"}, 1));
        quiz.addQuestion(new Question("Who has won the most Olympic gold medals?",
                new String[]{"Usain Bolt", "Michael Phelps", "Simone Biles", "Carl Lewis"}, 1));
        quiz.addQuestion(new Question("Who has won the most Olympic gold medals?",
                new String[]{"Usain Bolt", "Michael Phelps", "Simone Biles", "Carl Lewis"}, 1));
       
        return quiz;
    }

    public static ScienceQuiz getScienceQuiz() {
        ScienceQuiz quiz = new ScienceQuiz();
        quiz.addQuestion(new Question("H2O is the chemical formula of?",
                new String[]{"Oxygen", "Hydrogen", "Water", "Salt"}, 2));
        quiz.addQuestion(new Question("H2O is the chemical formula of?",
                new String[]{"Oxygen", "Hydrogen", "Water", "Salt"}, 2));
        quiz.addQuestion(new Question("H2O is the chemical formula of?",
                new String[]{"Oxygen", "Hydrogen", "Water", "Salt"}, 2));
        quiz.addQuestion(new Question("H2O is the chemical formula of?",
                new String[]{"Oxygen", "Hydrogen", "Water", "Salt"}, 2));
        quiz.addQuestion(new Question("H2O is the chemical formula of?",
                new String[]{"Oxygen", "Hydrogen", "Water", "Salt"}, 2));
       
        return quiz;
    }

    public static HistoryQuiz getHistoryQuiz() {
        HistoryQuiz quiz = new HistoryQuiz();
        quiz.addQuestion(new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
        quiz.addQuestion(new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
        quiz.addQuestion(new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
        quiz.addQuestion(new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
        quiz.addQuestion(new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
       
        return quiz;
    }
}

