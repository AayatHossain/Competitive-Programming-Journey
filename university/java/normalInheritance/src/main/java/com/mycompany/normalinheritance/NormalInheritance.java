/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.normalinheritance;

/**
 *
 * @author User
 */
//no constructor
class CorruptedPerson{
    String name; int age;
}
class Son extends CorruptedPerson{
    int salary;
}

public class NormalInheritance {

    public static void main(String[] args) {
        Son s1 = new Son();
        s1.name = "Aayat";
        System.out.println(s1.name);
    }
}
