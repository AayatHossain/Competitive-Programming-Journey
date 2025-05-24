/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.prac;

/**
 *
 * @author User
 */



public class Prac {
    
    public static void main(String[] args) {
        SavingsAccount s = new SavingsAccount("457", 10, 5);
        FixedDepositAccount f = new FixedDepositAccount("458", 20, 6, 24);
        System.out.println(s.calculateInterest());
        System.out.println(f.calculateInterest());
        
        System.out.println(s.calculateInterest(10));
        System.out.println(f.calculateInterest(7));
    }
}
