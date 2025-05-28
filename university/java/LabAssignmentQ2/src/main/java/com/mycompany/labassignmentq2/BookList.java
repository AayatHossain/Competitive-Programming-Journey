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
    List<String> books;
  
    BookList(String... initialBooks) {
        books = new ArrayList<>();
        for (String book : initialBooks) {
            books.add(book);
        }
    }
    void add(String s){
        books.add(s);
    }
    void remove(String s){
        books.remove(s);
    }
    void manage(String s){
        if(books.contains(s)){
            System.out.println("Managing book: "+s);
        }
    }
    void showBooks(){
        for(String s: books){
            System.out.print(s+" ");
        }
    }
}
