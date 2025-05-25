/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.interfacepractice;

/**
 *
 * @author User
 */
public class AllBanks implements SmallBank,Bank {
    @Override
    public int profit(int money){
        return money + 100;
    }
    @Override
    public int loss(int money){
        return money - 100;
    }
    @Override
    public int smallProfit(int money){
        return money + 10;
    }
    @Override
    public int smallLoss(int money){
        return money - 10;
    }
    void show(){
        System.out.println(money);
        System.out.println(name);
        System.out.println(smallMoney);
    }
}
