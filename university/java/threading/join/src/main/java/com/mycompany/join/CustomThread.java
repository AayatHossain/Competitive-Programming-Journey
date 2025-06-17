/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.join;

/**
 *
 * @author User
 */
public class CustomThread implements Runnable{
    Thread t;
    CustomThread(String name){
        t = new Thread(this, name);
        t.start();
    }
    @Override
    public void run(){
        try{
            for(int i = 0; i < 10; i++){
                System.out.println(t.getName() + " " + i);
                t.sleep(1000);
            }
        }catch(InterruptedException e){
            System.out.println(e.getMessage());
        }
    }
    
    public void joinThread(){
        try{
            t.join();
        }catch(InterruptedException e){
            System.out.println(e.getMessage());
        }
    }
}
