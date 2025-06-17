/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.customthreads;

/**
 *
 * @author User
 */
public class Thread1 implements Runnable {

    Thread t;

    Thread1(String name) {
        t = new Thread(this, name);  
        t.start();
    }
    
    
    //calling start like this also works, but main e t.start likhle error.
//    void init(){
//        t.start();
//    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                System.out.println(t.getName() +" "+ i);
                t.sleep(2000);
            }
        } catch (InterruptedException e) {
            System.out.println(t.getName() + "crashed");
        }
    }
}
