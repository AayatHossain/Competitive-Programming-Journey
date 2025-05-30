package com.mycompany.quizrush;

class QuestionBank {

    public static MovieQuiz getMovieQuiz() {
        MovieQuiz quiz = new MovieQuiz();
        QuizSetter movieQuizSetter = new QuizSetter("movieQuizSetter");

        movieQuizSetter.addQuestion(quiz, new Question("Who directed 'Inception'?",
                new String[]{"Christopher Nolan", "James Cameron", "Spielberg", "Tarantino"}, 0));
        movieQuizSetter.addQuestion(quiz, new Question("In 'Titanic', who played Jack?",
                new String[]{"Brad Pitt", "Leonardo DiCaprio", "Tom Cruise", "Matt Damon"}, 1));
        movieQuizSetter.addQuestion(quiz, new Question("Which movie won Best Picture in 2020?",
                new String[]{"Joker", "Parasite", "1917", "Ford v Ferrari"}, 1));
        movieQuizSetter.addQuestion(quiz, new Question("Which film features a character named 'Forrest'?",
                new String[]{"Cast Away", "Saving Private Ryan", "Forrest Gump", "Green Mile"}, 2));
        movieQuizSetter.addQuestion(quiz, new Question("Which director is known for 'Pulp Fiction'?",
                new String[]{"Tarantino", "Scorsese", "Kubrick", "Nolan"}, 0));

        return quiz;
    }

    public static GameQuiz getGameQuiz() {
        GameQuiz quiz = new GameQuiz();
        QuizSetter gameQuizSetter = new QuizSetter("gameQuizSetter");

        gameQuizSetter.addQuestion(quiz, new Question("What is the highest-selling video game ever?",
                new String[]{"GTA V", "Minecraft", "Fortnite", "Tetris"}, 1));
        gameQuizSetter.addQuestion(quiz, new Question("Which company makes the PlayStation?",
                new String[]{"Sony", "Microsoft", "Nintendo", "Sega"}, 0));
        gameQuizSetter.addQuestion(quiz, new Question("What game is known for the 'Creeper' mob?",
                new String[]{"Minecraft", "Roblox", "Terraria", "Fortnite"}, 0));
        gameQuizSetter.addQuestion(quiz, new Question("Who is the main character of the Halo series?",
                new String[]{"Master Chief", "Commander Shepard", "Doomguy", "Marcus Fenix"}, 0));
        gameQuizSetter.addQuestion(quiz, new Question("What genre is FIFA 23?",
                new String[]{"Action", "Puzzle", "Sports", "Adventure"}, 2));

        return quiz;
    }

    public static SportsQuiz getSportsQuiz() {
        SportsQuiz quiz = new SportsQuiz();
        QuizSetter sportsQuizSetter = new QuizSetter("sportsQuizSetter");

        sportsQuizSetter.addQuestion(quiz, new Question("Who has won the most Olympic gold medals?",
                new String[]{"Usain Bolt", "Michael Phelps", "Simone Biles", "Carl Lewis"}, 1));
        sportsQuizSetter.addQuestion(quiz, new Question("Which country has won the most FIFA World Cups?",
                new String[]{"Germany", "Brazil", "Italy", "Argentina"}, 1));
        sportsQuizSetter.addQuestion(quiz, new Question("How many players are on a basketball team on court?",
                new String[]{"5", "6", "7", "8"}, 0));
        sportsQuizSetter.addQuestion(quiz, new Question("Who is known as the King of Cricket?",
                new String[]{"Sachin Tendulkar", "Virat Kohli", "Ricky Ponting", "Brian Lara"}, 0));
        sportsQuizSetter.addQuestion(quiz, new Question("Which sport uses a shuttlecock?",
                new String[]{"Tennis", "Squash", "Badminton", "Table Tennis"}, 2));

        return quiz;
    }

    public static ScienceQuiz getScienceQuiz() {
        ScienceQuiz quiz = new ScienceQuiz();
        QuizSetter scienceQuizSetter = new QuizSetter("scienceQuizSetter");

        scienceQuizSetter.addQuestion(quiz, new Question("H2O is the chemical formula of?",
                new String[]{"Oxygen", "Hydrogen", "Water", "Salt"}, 2));
        scienceQuizSetter.addQuestion(quiz, new Question("What planet is known as the Red Planet?",
                new String[]{"Earth", "Mars", "Jupiter", "Venus"}, 1));
        scienceQuizSetter.addQuestion(quiz, new Question("What gas do plants absorb from the atmosphere?",
                new String[]{"Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen"}, 2));
        scienceQuizSetter.addQuestion(quiz, new Question("What is the boiling point of water in Celsius?",
                new String[]{"90°C", "95°C", "100°C", "105°C"}, 2));
        scienceQuizSetter.addQuestion(quiz, new Question("Which organ pumps blood in the human body?",
                new String[]{"Brain", "Heart", "Lungs", "Liver"}, 1));

        return quiz;
    }

    public static HistoryQuiz getHistoryQuiz() {
        HistoryQuiz quiz = new HistoryQuiz();
        QuizSetter historyQuizSetter = new QuizSetter("historyQuizSetter");

        historyQuizSetter.addQuestion(quiz, new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("When did World War II end?",
                new String[]{"1942", "1945", "1948", "1950"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("Where were the ancient pyramids built?",
                new String[]{"Mexico", "China", "Egypt", "India"}, 2));
        historyQuizSetter.addQuestion(quiz, new Question("Who discovered America?",
                new String[]{"Columbus", "Magellan", "Vasco da Gama", "Amerigo Vespucci"}, 0));
        historyQuizSetter.addQuestion(quiz, new Question("What wall fell in 1989?",
                new String[]{"China Wall", "Berlin Wall", "Great Wall", "Vietnam Wall"}, 1));

        return quiz;
    }
}
