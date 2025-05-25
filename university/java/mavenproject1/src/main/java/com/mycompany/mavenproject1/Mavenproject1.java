/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.mavenproject1;

/**
 *
 * @author User
 */
public class Mavenproject1 {

    public static void main(String[] args) {
        Car c = new Car(1,2,3);
        Bike b = new Bike(4,5,6);
        PremiumCar p = new PremiumCar(7,8,9);
        ContractDriver d = new ContractDriver(10,"Aayat",11);
        
        c.car_info();
        c.start_ride();
        c.end_ride();
        
        b.start_ride();
        b.end_ride();
        
        p.luxury_features();
        
        d.calculate_payment();
        
      
    }
}
