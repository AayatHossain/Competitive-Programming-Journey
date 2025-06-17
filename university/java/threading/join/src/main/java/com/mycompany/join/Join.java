/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.join;

/**
 *
 * @author User
 */
public class Join {

    public static void main(String[] args) {
        CustomThread ct1 = new CustomThread("One");
        ct1.joinThread();
        System.out.println(ct1.t.isAlive());

        CustomThread ct2 = new CustomThread("two");
        ct2.joinThread();
        System.out.println(ct2.t.isAlive());

        CustomThread ct3 = new CustomThread("Three");
        System.out.println(ct3.t.isAlive());

    }
}
