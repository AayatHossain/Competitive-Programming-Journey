/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.interfacepractice;

/**
 *
 * @author User
 */
public class InterfacePractice {

    public static void main(String[] args) {
        AllBanks b = new AllBanks();
        System.out.println(b.profit(100));
        System.out.println(b.loss(100));
        System.out.println(b.smallProfit(100));
        System.out.println(b.smallLoss(100));
        b.show();
        
    }
}
