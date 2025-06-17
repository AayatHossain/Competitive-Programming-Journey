/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.customthreads;

/**
 *
 * @author User
 */
public class CustomThreads {

    public static void main(String[] args) {
        Thread1 ct1 = new Thread1("Thread1");

        //also works
//       ct1.init();
        //error
//        ct1.start();

        Thread2 ct2 = new Thread2("Thread2");
//        System.out.println(ct2.getName());
        ct2.start();
        
        
        //run each thread first, then run together to see the 
        //simultaneous process

    }
}
