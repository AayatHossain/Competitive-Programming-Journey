/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.inheritancemultilevel;

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
        super(name);
        this.color = color;
        this.age = age;
    }
}
class Human extends Mammal{
    String id; int salary;
    Human(String id, int salary, String color, int age, String name){
        super(color, age, name);
        this.id = id;
        this.salary = salary;
    }
}
public class InheritanceMultilevel {

    public static void main(String[] args) {
        Human h1 = new Human("457", 50000,"Brown", 24, "Aayat");
        Mammal m1 = new Mammal("Yellow", 5, "Bird");
        Animal a1 = new Animal("Crocodile");
        System.out.println(h1.id);
        System.out.println(h1.salary);
        System.out.println(h1.color);
        System.out.println(h1.age);
        System.out.println(h1.name);
        System.out.println("----------------------");
         System.out.println(m1.color);
        System.out.println(m1.age);
        System.out.println(m1.name);
        System.out.println("----------------------");
        System.out.println(a1.name);
        System.out.println("----------------------");
        
//        System.out.println("Hello World!");
    }
}
