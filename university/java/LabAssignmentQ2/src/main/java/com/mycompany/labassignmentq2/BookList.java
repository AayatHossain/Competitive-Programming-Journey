/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignmentq2;

/**
 *
 * @author User
 */
import java.util.*;
public class BookList {
    public static List<String> books = new ArrayList<>();
    public static void showBooks(){
        System.out.print("Books currently available: ");
        for(String book: books){
            System.out.print(book + ", ");
        }
        System.out.println();
    }
}
