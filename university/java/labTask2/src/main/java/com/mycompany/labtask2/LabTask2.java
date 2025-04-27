/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.labtask2;

/**
 *
 * @author User
 */
abstract class Account {

    String an;
    double balance;
    
    Account(String an, double balance){
        this.an = an; this.balance = balance;
    }

    abstract double calcInt();
}

class Savings extends Account {
    
    double interestRate;
    
    Savings(String an, double balance, double iR){
        super(an, balance);
        this.interestRate = iR;
    }

    @Override
    double calcInt() {
        return balance * interestRate;
    }

    double calcInt(double iR) {
        return balance * iR;
    }
}

class Deposit extends Account {

    double interestRate;
    double depositPeriod;
    
    Deposit(String an, double balance, double iR, double dp){
        super(an, balance);
        this.interestRate = iR;
        this.depositPeriod = dp;
    }

    @Override
    double calcInt() {
        return balance * interestRate * (depositPeriod / 12);
    }

    double calcInt(double iR2) {
        return balance * iR2 * (depositPeriod / 12);
    }
}

public class LabTask2 {

    public static void main(String[] args) {
        Savings s1 = new Savings("2021", 5, 2);
        Deposit d1 = new Deposit("2022", 5, 2, 24);
        
        System.out.println(s1.calcInt());
        System.out.println(s1.calcInt(3));

        System.out.println(d1.calcInt());
        System.out.println(d1.calcInt(3));

        System.out.println("Hello World!");
    }
}
