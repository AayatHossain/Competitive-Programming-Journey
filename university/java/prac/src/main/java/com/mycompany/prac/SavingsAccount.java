/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prac;

/**
 *
 * @author User
 */
public class SavingsAccount extends Account {
    double interestRate;
    SavingsAccount(String accountNumber, double balance, double interestRate){
        super(accountNumber, balance);
        this.interestRate = interestRate;
    }
    @Override
    double calculateInterest(){
        return interestRate*balance;
    }
    double calculateInterest(double customInterestRate){
        return customInterestRate*balance;
    }
}
