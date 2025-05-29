/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.labassignmentq2;


/**
 *
 * @author User
 */
public class LabAssignmentQ2 {
    public static void main(String[] args) {
        Librarian Omar = new Librarian("000","123");
        
        Omar.login();
        Omar.viewProfile();
        Omar.addBook("A");
        Omar.addBook("B");
        Omar.addBook("C");
        Omar.removeBook("C");
        Omar.borrowBook("A");
        Omar.returnBook("A");
        Omar.manageBook("A");
        Omar.logout();
        
        BookList.showBooks();
        
        Member Tasin = new Member("001","456");
        Tasin.login();
        Tasin.viewProfile();
        Tasin.borrowBook("A");
        
        BookList.showBooks();
        
        Tasin.returnBook("A");
        Tasin.addBook("D");
        Tasin.removeBook("A");
        Tasin.manageBook("A");
        Tasin.logout();
        
        Member Kayes = new Member("002","789");
        Member Aoyon = new Member("003","987");
        Kayes.login();
        Aoyon.login();
        
        LoggedInUsers.printAllUsers();
        
        Kayes.logout();
        
        Librarian Tamim = new Librarian("004","654");
        Librarian Nouman = new Librarian("005","321");
        Librarian Rakin = new Librarian("006","000");
        Tamim.login();
        Nouman.login();
        Rakin.login();
        
        LoggedInUsers.printAllUsers();

    }
}
