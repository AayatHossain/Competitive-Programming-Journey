/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignment;

/**
 *
 * @author User
 */
public class Director extends Manager {
    int numberOfDepartments;
    
    Director(String name, String ID, double salary, int teamSize, String department, int numberOfDepartments){
        super(name,ID,salary,teamSize,department);
        this.numberOfDepartments = numberOfDepartments;
    }
    
    @Override
    void work(){
        System.out.println("Director "+ name+" is overseeing "+numberOfDepartments+" departments and setting company strategies");
    }
    @Override
    double calculateBonus(double performanceRating){
       return salary*0.25*performanceRating;
    }
    
    void setCompanyStrategy(){
        System.out.println("Director "+name+" is setting the company strategy");
    }
    
    void evaluateManagers(){
        System.out.println("Director "+name+" is evaluating "+numberOfDepartments+" managers");
    }
}
