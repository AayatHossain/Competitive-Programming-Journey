/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.priority;

/**
 *
 * @author User
 */
public class Priority {



    // Inner class implementing Runnable
    static class Clicker implements Runnable {

        long click = 0;  // Counter
        Thread t;       // Thread instance
        private volatile boolean running = true;  // Flag for controlling thread

        // Constructor to create a thread with a specific priority
        public Clicker(int priority) {
            t = new Thread(this);       // Create a new Thread
            t.setPriority(priority);    // Set thread priority
        }

        // Run method for the thread
        public void run() {
            while (running) {
                click++;  // Count clicks while running is true
            }
        }

        // Start the thread
        public void start() {
            t.start();
        }

        // Stop the thread
        public void stop() {
            running = false;
        }
    }

    // Main method
    public static void main(String[] args) {

        // Create two threads with different priorities
        Clicker high = new Clicker(Thread.NORM_PRIORITY + 2);  // Priority 7
        Clicker low = new Clicker(Thread.NORM_PRIORITY - 2);   // Priority 3

        // Start both threads
        low.start();
        high.start();

        // Let both threads run for 10 seconds
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        // Stop both threads
        low.stop();
        high.stop();

        // Wait for both threads to finish
        try {
            low.t.join();
            high.t.join();
        } catch (InterruptedException e) {
            System.out.println("InterruptedException caught.");
        }

        // Print the number of iterations (clicks)
        System.out.println("Low-priority thread: " + low.click);
        System.out.println("High-priority thread: " + high.click);
    }
}
