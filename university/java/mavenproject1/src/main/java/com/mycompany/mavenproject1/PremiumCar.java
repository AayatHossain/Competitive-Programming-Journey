/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenproject1;

/**
 *
 * @author User
 */
public class PremiumCar extends Car {
     PremiumCar(int id, int model, int cap){
        super(id, model, cap);
    }
    void luxury_features(){
        System.out.println("Luxury");
    }
}
