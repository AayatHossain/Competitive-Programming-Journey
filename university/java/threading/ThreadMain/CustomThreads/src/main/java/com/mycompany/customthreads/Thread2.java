/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.customthreads;

/**
 *
 * @author User
 */
public class Thread2 extends Thread{
    
    Thread2(String name){
       super(name);
       //we can call start here as well
       //start();
    }
    
    @Override
    public void run(){
       try{
           for(int i = 0; i < 10; i++){
               System.out.println(getName() +" "+ i);
               sleep(1000);
           }
       }catch(InterruptedException e){
           System.out.println("Crashed");
       }
    }
}
