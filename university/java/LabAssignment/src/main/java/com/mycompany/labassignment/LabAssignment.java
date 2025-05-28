/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.labassignment;

/**
 *
 * @author User
 */
public class LabAssignment {

    public static void main(String[] args) {
        Employee e = new Employee("Omar", "2023", 10000);
        Manager m = new Manager("Tasin", "2024", 20000,5,"A");
        Director d = new Director("Kayes", "2025", 30000,10,"B", 5);
        
        System.out.println("Employee details:");       
        e.work();
        System.out.println(e.calculateBonus(0.5));
        
        System.out.println();
        System.out.println("Manager details:");
        m.work();
        System.out.println(m.calculateBonus(0.6));
        m.evaluateTeamPerformance();
        m.conductTeamMeeting();
        
        System.out.println();
        System.out.println("Director details:");
        d.work();
        System.out.println(d.calculateBonus(0.7));
        d.setCompanyStrategy();
        d.evaluateManagers();
        
    }
}
