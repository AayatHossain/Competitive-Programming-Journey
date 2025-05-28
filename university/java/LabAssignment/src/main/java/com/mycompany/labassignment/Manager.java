/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignment;

/**
 *
 * @author User
 */
public class Manager extends Employee {
    int teamSize;
    String department;
    
    Manager(String name, String ID, double salary, int teamSize, String department){
        super(name,ID,salary);
        this.teamSize = teamSize;
        this.department = department;
    }
    @Override
    void work(){
        System.out.println("Manager "+ name+" is managing the "+department+" department, with a team of "+teamSize+" employees");
    }
    @Override
    double calculateBonus(double performanceRating){
       return salary*0.2*performanceRating;
    }
    void evaluateTeamPerformance(){
        System.out.println("Manager "+ name+" is evaluating the performance of the team of the department: "+department);
    }
    void conductTeamMeeting(){
        System.out.println("Manager "+ name+" is conducting a team meeting for the "+department+" department");
    }
}
