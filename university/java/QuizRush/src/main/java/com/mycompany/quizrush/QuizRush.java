/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.quizrush;

/**
 *
 * @author User
 */
import java.util.*;

public class QuizRush {

    static Scanner scanner = new Scanner(System.in);

    static Map<String, QuizGiver> allUsers = new HashMap<>();

    public static void main(String[] args) {
        System.out.println("🎉 Welcome to QuizRush!");

        while (true) {
            System.out.print("\nType 'exit' to quit, 'play' to play, or 'leaderboard' to view scores: ");
            String input = scanner.nextLine().trim().toLowerCase();

            if (input.equals("exit")) {
                System.out.println("👋 Thanks for playing!");
                break;
            } else if (input.equals("play")) {
                System.out.print("Enter your username: ");
                String name = scanner.nextLine().trim();

                QuizGiver user;
                if (allUsers.containsKey(name)) {
                    user = allUsers.get(name);
                    System.out.println("👋 Welcome back, " + name + "!");
                } else {
                    user = new QuizGiver(name);
                    allUsers.put(name, user);
                    System.out.println("👋 Hello, " + name + "! New user created.");
                }

                Quiz selectedQuiz = chooseGenre();
                runQuiz(selectedQuiz, user);

                // Clear any remaining input
                scanner.nextLine();
            } else if (input.equals("leaderboard")) {
                showLeaderboard();
            } else {
                System.out.println("Invalid input. Please type 'exit' or 'play'.");
            }
        }
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
            case 1:
                return QuestionBank.getMovieQuiz();
            case 2:
                return QuestionBank.getGameQuiz();
            case 3:
                return QuestionBank.getSportsQuiz();
            case 4:
                return QuestionBank.getScienceQuiz();
            case 5:
                return QuestionBank.getHistoryQuiz();
            default:
                System.out.println("Invalid choice. Defaulting to Movie.");
                return QuestionBank.getMovieQuiz();
        }
    }

    // Step 2: Run the Quiz Loop
    static void runQuiz(Quiz quiz, QuizGiver user) {
        System.out.println("🎮 Genre: " + quiz.genre);
        List<Question> quizQuestions = quiz.getRandomQuestions(); // Pick 5

        int correctAnswers = 0;

        for (int i = 0; i < quizQuestions.size(); i++) {
            Question q = quizQuestions.get(i);
            System.out.println("\nQuestion " + (i + 1) + ":");
            q.display();

            long startTime = System.currentTimeMillis();
            int answer = getAnswerWithTimeout(10);
            long duration = (System.currentTimeMillis() - startTime) / 1000;

            if (duration > 10) {
                System.out.println("⏰ Time's up! No point awarded.");
                continue;
            }

            if (q.isCorrect(answer - 1)) {
                System.out.println("✅ Correct!");
                correctAnswers++;
            } else {
                System.out.println("❌ Incorrect.");
            }
        }

        int earnedPoints = correctAnswers * 5;
        user.updateScore(earnedPoints);
        System.out.println("\n🏁 Quiz Over! You scored: " + correctAnswers + "/5");
        System.out.println("⭐ Points Earned: " + earnedPoints);
        user.viewScore();
        user.showLevel();
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

    static void showLeaderboard() {
        System.out.println("\n🏆 Leaderboard:");
        if (allUsers.isEmpty()) {
            System.out.println("No players yet!");
            return;
        }

        allUsers.values().stream()
                .sorted((a, b) -> b.score - a.score)
                .forEach(user -> System.out.println(user.username + " - " + user.score + " points (Level " + user.level + ")"));
    }
}
