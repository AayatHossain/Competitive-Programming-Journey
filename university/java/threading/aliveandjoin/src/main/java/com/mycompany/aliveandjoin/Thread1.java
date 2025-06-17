/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.aliveandjoin;

/**
 *
 * @author User
 */
public class Thread1 implements Runnable{
    Thread t;
    Thread1(String name){
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
