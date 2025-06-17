/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.aliveandjoin;

/**
 *
 * @author User
 */
public class Aliveandjoin {

    public static void main(String[] args) {
        Thread1 ct1 = new Thread1("One");
        Thread1 ct2 = new Thread1("Two");
        Thread1 ct3 = new Thread1("Three");
        try{
            ct1.t.join();
            ct2.t.join();
            ct3.t.join();
        }catch(InterruptedException e){
            System.out.println("Crashed");
        }
        System.out.println(ct1.t.isAlive());
        System.out.println(ct2.t.isAlive());
        System.out.println(ct3.t.isAlive());
        
    }
}
