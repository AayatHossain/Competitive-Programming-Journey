/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenproject1;

/**
 *
 * @author User
 */
public class ContractDriver extends Driver implements PaymentHandler{
    ContractDriver(int driver_id, String name, int rating){
        super(driver_id,name,rating);
    }
    @Override
    public void calculate_payment(){
        System.out.println("Payment Calculated");
    }
}
