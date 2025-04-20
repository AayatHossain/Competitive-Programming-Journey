/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.inheritance;

/**
 *
 * @author User
 */

class Animal{
    String name;
    Animal(String name){
        this.name = name;
    }
   
}
class Mammal extends Animal{
    String color; int age;
    Mammal(String color, int age, String name){
        super(name); // must be called at first
        this.color = color;
        this.age = age;
        super.name = "asdas";
    }
}

public class Inheritance {

    public static void main(String[] args) {
        Mammal m1 = new Mammal("blue", 5, "Bird");
        System.out.println(m1.name);
        System.out.println(m1.color);
        System.out.println(m1.age);
       
    }
}
