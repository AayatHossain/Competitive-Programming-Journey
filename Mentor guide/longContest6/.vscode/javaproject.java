class User {
    String username;
    int score;

    User(String username) {
        this.username = username;
        this.score = 0;
    }

    public void viewScore() {
        System.out.println(username + "'s Score: " + score);
    }
}

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
        System.out.println("Level: " + level);
    }
}



















class QuizSetter extends User {
    QuizSetter(String username) {
        super(username);
    }

    public void addQuestion(Quiz quiz, Question q) {
        quiz.addQuestion(q);
    }
}

// Extended setter with admin privilege
class AdminQuizSetter extends QuizSetter {
    AdminQuizSetter(String username) {
        super(username);
    }

    public void deleteQuiz(List<Quiz> allQuizzes, Quiz quiz) {
        allQuizzes.remove(quiz);
        System.out.println("Quiz removed by Admin.");
    }
}












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

// 5 Genre Quizzes (Hierarchical)
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





import java.util.*;

public class QuizRunner {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("🎉 Welcome to QuizRush!");
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        QuizGiver user = new QuizGiver(name);

        Quiz selectedQuiz = chooseGenre();
        runQuiz(selectedQuiz, user);
    }

    // Step 1: Genre Selection
    static Quiz chooseGenre() {
        System.out.println("Choose a genre:");
        System.out.println("1. Movie");
        System.out.println("2. Game");
        System.out.println("3. Sports");
        System.out.println("4. Science");
        System.out.println("5. History");

        int choice = scanner.nextInt();
        scanner.nextLine(); // Clear newline

        switch (choice) {
            case 1: return QuestionBank.getMovieQuiz();
            case 2: return QuestionBank.getGameQuiz();
            case 3: return QuestionBank.getSportsQuiz();
            case 4: return QuestionBank.getScienceQuiz();
            case 5: return QuestionBank.getHistoryQuiz();
            default:
                System.out.println("Invalid choice. Defaulting to Movie.");
                return QuestionBank.getMovieQuiz();
        }
    }

    // Step 2: Run the Quiz Loop
    static void runQuiz(Quiz quiz, QuizGiver user) {
        System.out.println("Genre: " + quiz.genre);
        boolean passed = false;

        while (!passed) {
            List<Question> quizQuestions = quiz.getRandomQuestions();
            int correctAnswers = 0;

            for (int i = 0; i < quizQuestions.size(); i++) {
                Question q = quizQuestions.get(i);
                System.out.println("\nQuestion " + (i + 1) + ":");
                q.display();

                long startTime = System.currentTimeMillis();

                int answer = getAnswerWithTimeout(10);
                long endTime = System.currentTimeMillis();
                long duration = (endTime - startTime) / 1000;

                if (duration > 10) {
                    System.out.println("⏰ Time's up! Restarting quiz...");
                    break;
                }

                if (q.isCorrect(answer - 1)) {
                    System.out.println("✅ Correct!");
                    correctAnswers++;
                } else {
                    System.out.println("❌ Incorrect. Restarting quiz...");
                    break;
                }
            }

            if (correctAnswers == 10) {
                System.out.println("\n🎉 You completed the quiz!");
                user.updateScore(20); // Award 20 points per successful quiz
                user.viewScore();
                user.showLevel();
                passed = true;
            }
        }
    }

    // Input with basic time check (not enforced during blocking input)
    static int getAnswerWithTimeout(int seconds) {
        // WARNING: Java console doesn't natively support strict timeout without threads.
        // This is a simulated version. For strict timing, use threads.
        System.out.print("Enter option (1-4): ");
        try {
            return scanner.nextInt();
        } catch (InputMismatchException e) {
            scanner.nextLine();
            return -1;
        }
    }
}




class QuestionBank {
    public static MovieQuiz getMovieQuiz() {
        MovieQuiz quiz = new MovieQuiz();
        quiz.addQuestion(new Question("Who directed 'Inception'?",
                new String[]{"Christopher Nolan", "James Cameron", "Spielberg", "Tarantino"}, 0));
        quiz.addQuestion(new Question("In 'Titanic', who played Jack?",
                new String[]{"Brad Pitt", "Leonardo DiCaprio", "Tom Cruise", "Matt Damon"}, 1));
        // ... add 18 more movie questions
        return quiz;
    }

    public static GameQuiz getGameQuiz() {
        GameQuiz quiz = new GameQuiz();
        quiz.addQuestion(new Question("What is the highest-selling video game ever?",
                new String[]{"GTA V", "Minecraft", "Fortnite", "Tetris"}, 1));
        // ... add 19 more
        return quiz;
    }

    public static SportsQuiz getSportsQuiz() {
        SportsQuiz quiz = new SportsQuiz();
        quiz.addQuestion(new Question("Who has won the most Olympic gold medals?",
                new String[]{"Usain Bolt", "Michael Phelps", "Simone Biles", "Carl Lewis"}, 1));
        // ... add 19 more
        return quiz;
    }

    public static ScienceQuiz getScienceQuiz() {
        ScienceQuiz quiz = new ScienceQuiz();
        quiz.addQuestion(new Question("H2O is the chemical formula of?",
                new String[]{"Oxygen", "Hydrogen", "Water", "Salt"}, 2));
        // ... add 19 more
        return quiz;
    }

    public static HistoryQuiz getHistoryQuiz() {
        HistoryQuiz quiz = new HistoryQuiz();
        quiz.addQuestion(new Question("Who was the first President of the USA?",
                new String[]{"Abraham Lincoln", "George Washington", "Jefferson", "Adams"}, 1));
        // ... add 19 more
        return quiz;
    }
}
