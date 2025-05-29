/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.labassignmentq2;

/**
 *
 * @author User
 */
public class Member extends AbstractUser implements BookHandler {
    String ID;
    String password;
    Member(String ID, String password){
        this.ID = ID;
        this.password = password;
    }
    @Override
    void login(){
        System.out.println("Member with ID- "+ID+" and password-"+password+" has logged in");
    }
    @Override
    void logout(){
        System.out.println("Member with ID- "+ID+" and password-"+password+" has logged out");
    }
    @Override
    void viewProfile(){
        System.out.println("Member with ID- "+ID+" and password-"+password+" is viewing profile");
    }
    @Override
    public void borrowBook(String title){
        System.out.println("Member with ID- "+ID+" has borrowed the book titled: "+title);
        BookList.books.remove(title);
    }
    @Override
    public void returnBook(String title){
        System.out.println("Member with ID- "+ID+" has returned the book titled: "+title);
        BookList.books.add(title);
    }
    @Override
    public void addBook(String title){
        System.out.println("Sorry, members are not eligible for this action");
    }
    @Override
    public void removeBook(String title){
        System.out.println("Sorry, members are not eligible for this action");
    }
    @Override
    public void manageBook(String title){
        System.out.println("Sorry, members are not eligible for this action");
    }
    
}
