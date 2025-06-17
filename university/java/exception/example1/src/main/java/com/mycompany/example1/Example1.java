/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.example1;

/**
 *
 * @author User
 */


class CustomException extends Exception{
    CustomException(String msg){
        super(msg);
    }
}

public class Example1 {

    static int add(int a, int b) throws ClassNotFoundException {
        if (a == 5) {
            throw new ClassNotFoundException("Class not found");
        }
        return a + b;
    }
    static int multiply(int a, int b) throws CustomException{
        if(a==5){
            throw new CustomException("Custom Exception occured");
        }
        return a*b;
    }

    public static void main(String[] args) {
        //system throw
        try {
            System.out.println(10 / 0);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        //developer throw
        try {
            int res = add(5, 3);
            System.out.println(res);
        } catch (ClassNotFoundException e) {
            System.out.println(e.getMessage());

        }
        //custom exception with inheritance
        try{
            int res = multiply(5,10);
            System.out.println(res);
        }catch(CustomException e){
            System.out.println(e.getMessage());
        }
    }
}
