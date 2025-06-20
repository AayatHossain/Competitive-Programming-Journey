/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.sync;

/**
 *
 * @author User
 */
class SharedArea {

    String str = "";
    //ekhane synchronized likhleo hobe
    void putSharedArea(String s) {
        str = str + "[" + s;
        try {
            Thread.sleep(1000); // simulate delay
        } catch (InterruptedException e) {
            System.out.println("Interrupted");
        }
        str = str + "] ";
    }

    void show() {
        System.out.println(str);
    }
}

class Caller implements Runnable {

    String msg;
    SharedArea targ;
    Thread t;

    public Caller(SharedArea targ, String s) {
        msg = s;
        this.targ = targ;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        synchronized (targ) {
            targ.putSharedArea(msg);
        }

    }
}

public class Sync {

    public static void main(String args[]) {
        SharedArea target = new SharedArea();
        Caller ob1 = new Caller(target, "Hello");
        Caller ob2 = new Caller(target, "Synchronized");
        Caller ob3 = new Caller(target, "World");

        // wait for threads to finish
        try {
            ob1.t.join();
            ob2.t.join();
            ob3.t.join();
        } catch (InterruptedException e) {
            System.out.println("Interrupted");
        }

        target.show();
    }
}
