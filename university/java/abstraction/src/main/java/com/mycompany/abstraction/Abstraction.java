/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.abstraction;

/**
 *
 * @author User
 */


abstract class SeniorDeveloper{
    final String companyName = "ABC";   //fixed
    int netWorth;//can change
    abstract double calcAvg(double a, double b);
    void printSeries(int n){
        for(int i = 0; i <= n; i++){
            System.out.print(i+" ");
        }
    }
}
class JuniorDeveloper extends SeniorDeveloper{
    @Override
    double calcAvg(double a, double b){
        return (a+b)/2;
    }
    super.netWorth = 500;
}


public class Abstraction {

    public static void main(String[] args) {
        JuniorDeveloper j1 = new JuniorDeveloper();
        int a = j1.calcAvg(5, 4);
        System.out.println(a);
        System.out.println(j1.netWorth);
        j1.printSeries();
    }
}
