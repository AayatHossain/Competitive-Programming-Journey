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

        CustomThread ct2 = new CustomThread("two");
        ct2.joinThread();

        CustomThread ct3 = new CustomThread("Three");

    }
}
