/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.multithread;

/**
 *
 * @author User
 */
public class MultiThread {

    public static void main(String[] args) {
        CustomThread ct1 = new CustomThread("One");
        CustomThread ct2 = new CustomThread("two");
        CustomThread ct3 = new CustomThread("Three");
        
        try{
            for(int i = 0; i < 10; i++){
                System.out.println("Main Thread "+i);
                Thread.sleep(1000);
            }
        }catch(InterruptedException e){
            System.out.println(e.getMessage());
        }
        System.out.println("Exiting main Thread");
        
//        ct1.isDead();
//        ct2.isDead();
//        ct3.isDead();
    }
}
