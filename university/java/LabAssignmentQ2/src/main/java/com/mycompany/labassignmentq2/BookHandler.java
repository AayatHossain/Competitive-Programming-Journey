/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.mycompany.labassignmentq2;

/**
 *
 * @author User
 */
public interface BookHandler {
    void borrowBook(String title);
    void returnBook(String title);
    void addBook(String title);
    void removeBook(String title);
    void manageBook(String title);
}
