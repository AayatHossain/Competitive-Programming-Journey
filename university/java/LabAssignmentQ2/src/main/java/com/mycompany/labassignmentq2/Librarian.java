/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignmentq2;

/**
 *
 * @author User
 */
public class Librarian extends AbstractUser implements BookHandler {
    String ID;
    String password;
    Librarian(String ID, String password){
        this.ID = ID;
        this.password = password;
    }
    @Override
    void login(){
        System.out.println("Librarian with ID- "+ID+" and password-"+password+" has logged in");
    }
    @Override
    void logout(){
        System.out.println("Librarian with ID- "+ID+" and password-"+password+" has logged out");
    }
    @Override
    void viewProfile(){
        System.out.println("Librarian with ID- "+ID+" and password-"+password+" is viewing profile");
    }
    @Override
    public void borrowBook(String title){
        System.out.println("Sorry, librarians cannot perform this action");
    }
    @Override
    public void returnBook(String title){
        System.out.println("Sorry, librarians cannot perform this action");
    }
    @Override
    public void addBook(String title){
        System.out.println("Librarian with ID- "+ID+" has added the book titled: "+title);
        BookList.books.add(title);
    }
    @Override
    public void removeBook(String title){
        System.out.println("Librarian with ID- "+ID+" has removed the book titled: "+title);
        BookList.books.remove(title);
    }
    @Override
    public void manageBook(String title){
        System.out.println("Librarian with ID- "+ID+" has managed the book titled: "+title);
    }
}
