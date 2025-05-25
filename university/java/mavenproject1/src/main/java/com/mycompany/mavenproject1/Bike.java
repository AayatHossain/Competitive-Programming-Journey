/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenproject1;

/**
 *
 * @author User
 */
public class Bike extends Vehicle implements RiderInterface{
    Bike(int id, int model, int cap){
        super(id, model, cap);
    }
    @Override
    public void start_ride(){
        System.out.println("Bike started");
    }
    @Override
    public void end_ride(){
        System.out.println("Bike stopped");
    }
    
    
}
