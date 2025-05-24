/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prac;

/**
 *
 * @author User
 */
public abstract class Account {
    String accountNum;
    double balance;
    Account(String accountNum, double balance){
        this.accountNum = accountNum;
        this.balance = balance;
    }
    abstract double calculateInterest();
}
