/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.threadmain;

/**
 *
 * @author User
 */
public class ThreadMain {

    public static void main(String[] args) {
        Thread t = Thread.currentThread();
        t.setName("Aayat");
        System.out.println(t.getName());
        System.out.println(t.getPriority());
        t.setPriority(10);
        System.out.println(t.getPriority());
        System.out.println(t.isAlive());
        System.out.println(t);

        try {
            for (int i = 0; i < 10; i++) {
                System.out.println(i);
                t.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Crashed");
        }

        System.out.println(t.isAlive());
        
        //extra
        try {
            for (int i = 0; i < 10; i++) {
                System.out.println(i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Crashed");
        }

    }
}
