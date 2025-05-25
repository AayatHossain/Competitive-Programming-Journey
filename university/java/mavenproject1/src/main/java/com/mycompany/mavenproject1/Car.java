/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenproject1;

/**
 *
 * @author User
 */
public class Car extends Vehicle implements RiderInterface{
    Car(int id, int model, int cap){
        super(id, model, cap);
    }
    void car_info(){
        System.out.println(vehicle_id);
        System.out.println(model);
        System.out.println(capacity);
    }
    @Override
    public void start_ride(){
        System.out.println("Car started");
    }
    @Override
    public void end_ride(){
        System.out.println("Car stopped");
    }
}
