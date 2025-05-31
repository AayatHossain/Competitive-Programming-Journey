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

        movieQuizSetter.addQuestion(quiz, new Question("What animal do the guys find in their hotel bathroom in 'The Hangover'?",
                new String[]{"A llama", "A tiger", "A kangaroo", "A raccoon"}, 1));

        movieQuizSetter.addQuestion(quiz, new Question("What does Ron Burgundy say he's 'kind of a big deal' for in 'Anchorman'?",
                new String[]{"His hair", "His voice", "His suits", "His mustache"}, 1));
        movieQuizSetter.addQuestion(quiz, new Question("In 'Zoolander', what can't Derek Zoolander do?",
                new String[]{"Turn right", "Turn left", "Wink", "Smile"}, 1));

        movieQuizSetter.addQuestion(quiz, new Question("What does Deadpool say is his biggest weakness?",
                new String[]{"Kryptonite", "Bullets", "Babies' hands", "Love"}, 2));

        movieQuizSetter.addQuestion(quiz, new Question("In 'Superbad', what fake name does McLovin use on his ID?",
                new String[]{"Jackie Chan", "Muhammad Lee", "McLovin", "Vin Diesel"}, 2));

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

        gameQuizSetter.addQuestion(quiz, new Question("Which game features 'Ezio Auditore' as a protagonist?",
                new String[]{"Assassin's Creed", "God of War", "The Witcher", "Dark Souls"}, 0));
        gameQuizSetter.addQuestion(quiz, new Question("What is the name of the virtual reality headset by Meta?",
                new String[]{"Oculus Rift", "HTC Vive", "PlayStation VR", "Valve Index"}, 0));
        gameQuizSetter.addQuestion(quiz, new Question("Which game popularized the battle royale genre?",
                new String[]{"PUBG", "Fortnite", "Apex Legends", "Call of Duty: Warzone"}, 0));
        gameQuizSetter.addQuestion(quiz, new Question("What year was 'The Legend of Zelda: Ocarina of Time' released?",
                new String[]{"1996", "1998", "2000", "2002"}, 1));
        gameQuizSetter.addQuestion(quiz, new Question("Which character says 'Hadouken!' in Street Fighter?",
                new String[]{"Ryu", "Ken", "Chun-Li", "Dhalsim"}, 0));

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

        sportsQuizSetter.addQuestion(quiz, new Question("What is the diameter of a basketball hoop in inches?",
                new String[]{"16", "18", "20", "22"}, 1));
        sportsQuizSetter.addQuestion(quiz, new Question("Which tennis player has the most Grand Slam titles?",
                new String[]{"Roger Federer", "Rafael Nadal", "Novak Djokovic", "Pete Sampras"}, 2));
        sportsQuizSetter.addQuestion(quiz, new Question("In baseball, how many strikes make an out?",
                new String[]{"2", "3", "4", "5"}, 1));
        sportsQuizSetter.addQuestion(quiz, new Question("Which country won the first ever FIFA World Cup in 1930?",
                new String[]{"Brazil", "Uruguay", "Argentina", "Italy"}, 1));
        sportsQuizSetter.addQuestion(quiz, new Question("What is the maximum score in a single frame of bowling?",
                new String[]{"20", "30", "40", "50"}, 1));

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

        scienceQuizSetter.addQuestion(quiz, new Question("What is the atomic number of Oxygen?",
                new String[]{"6", "7", "8", "9"}, 2));
        scienceQuizSetter.addQuestion(quiz, new Question("Which scientist developed the theory of relativity?",
                new String[]{"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Stephen Hawking"}, 1));
        scienceQuizSetter.addQuestion(quiz, new Question("What is the hardest natural substance on Earth?",
                new String[]{"Gold", "Iron", "Diamond", "Graphite"}, 2));
        scienceQuizSetter.addQuestion(quiz, new Question("Which planet has the most moons in our solar system?",
                new String[]{"Earth", "Jupiter", "Saturn", "Mars"}, 2));
        scienceQuizSetter.addQuestion(quiz, new Question("What is the chemical symbol for gold?",
                new String[]{"Go", "Gd", "Au", "Ag"}, 2));

        return quiz;
    }

    public static HistoryQuiz getHistoryQuiz() {
        HistoryQuiz quiz = new HistoryQuiz();
        QuizSetter historyQuizSetter = new QuizSetter("historyQuizSetter");

        historyQuizSetter.addQuestion(quiz, new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("In which year did World War II end?",
                new String[]{"1943", "1945", "1947", "1950"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("Which ancient civilization built the pyramids?",
                new String[]{"Greeks", "Romans", "Egyptians", "Mayans"}, 2));
        historyQuizSetter.addQuestion(quiz, new Question("Who wrote the Declaration of Independence?",
                new String[]{"Benjamin Franklin", "John Adams", "Thomas Jefferson", "George Washington"}, 2));
        historyQuizSetter.addQuestion(quiz, new Question("Which empire was ruled by Genghis Khan?",
                new String[]{"Ottoman", "Mongol", "British", "Roman"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("When did the Berlin Wall fall?",
                new String[]{"1987", "1989", "1991", "1993"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("Who was the first female Prime Minister of UK?",
                new String[]{"Theresa May", "Margaret Thatcher", "Angela Merkel", "Indira Gandhi"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("Which country was the first to land on the moon?",
                new String[]{"Russia", "China", "USA", "Japan"}, 2));
        historyQuizSetter.addQuestion(quiz, new Question("When did the French Revolution begin?",
                new String[]{"1776", "1789", "1799", "1804"}, 1));
        historyQuizSetter.addQuestion(quiz, new Question("Who discovered America in 1492?",
                new String[]{"Vasco da Gama", "Christopher Columbus", "Ferdinand Magellan", "James Cook"}, 1));

        return quiz;
    }
}
