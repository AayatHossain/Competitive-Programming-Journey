/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignment;

/**
 *
 * @author User
 */
public class Employee {
    String name;
    String ID;
    double salary;
    
    Employee(String name, String ID, double salary){
        this.name = name;
        this.ID = ID;
        this.salary = salary;
    }
    
    void work(){
        System.out.println("Employee "+name + " is working");
    }
    double calculateBonus(double performanceRating){
       return salary*0.15*performanceRating;
    }
}
