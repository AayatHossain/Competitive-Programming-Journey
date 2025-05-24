/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prac;

/**
 *
 * @author User
 */
public class FixedDepositAccount extends Account{
    double interestRate;
    double depositPeriod;
    FixedDepositAccount(String accountNumber, double balance, double interestRate, double depositPeriod){
        super(accountNumber, balance);
        this.interestRate = interestRate;
        this.depositPeriod = depositPeriod;
    }
    @Override
    double calculateInterest(){
        return balance*interestRate*(depositPeriod/12);
    }
    double calculateInterest(double customInterestRate){
        return balance*customInterestRate*(depositPeriod/12);
    }
}
