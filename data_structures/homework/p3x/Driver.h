//
// Created by KJohnson on 10/06/2020.
// Lab 3 in CPSC 5910 03 at Seattle University
// Fall 2020
//

#include "Book.h"
#include "Member.h"
#include "Rating.h"

#ifndef P3_DRIVER_H
#define P3_DRIVER_H

/**
 * A class of static methods to control and display the user interface
 * to a user of the recommendation application
 */
class Driver {
public:
    /**
     * Method for the opening screen when a user is not logged in
     * @return integer choice from the opening menu
     */
    static int openingScreen();

    /**
     * Driver of the beginning of the program, displays opening menu
     * and controls choices
     * @param b Book object containing book data
     * @param m Member object containing member data
     * @param r rating object containing rating data
     */
    static void initialDriver(Book &b, Member &m, Rating &r);

    /**
     * Driver of the program to take over once a user is logged in
     * displays logged in menu and controls choices
     * @param b Book object containing book data
     * @param m Member object containing member data
     * @param r rating object containing rating data
     * @param memberId the member id of the logged in user
     * @param the choice made from the logged in menu
     */
    static void loggedInDriver(Book &b, Member &m, Rating &r,
                               int memberId, int choice);

    /**
     * Displays the menu for a logged in user lets them make a choice
     * of options
     * @param b Book object containing book data
     * @param m Member object containing member data
     * @param r rating object containing rating data
     * @return integer choice made from the menu
     */
    static int loggedInScreen(Book &b, Member &m, Rating &r);

    /**
     * Method that asks a user for their member id and logs them in
     * @param m Member object containing member data
     * @return the member id of the logged in member
     */
    static int memberLogin(Member &m);

    /**
     * Logs a user out
     * @param m Member object containing member data
     * @param memberId of the user to be logged out
     */
    static void memberLogout(Member &m, int memberId);

    /**
     * Method than asks for info of a new member and adds them to the
     * member object
     * @param m Member object containing member data
     */
    static void addMember(Member &m);

    /**
     * Method than asks for info of a new book and adds it to the
     * book object
     * @param b Book object containing book data
     */
    static void addBook(Book &b);

    /**
     * Method that displays all of a user's book ratings
     * @param b Book object containing book data
     * @param m Member object containing member data
     * @param r rating object containing rating data
     * @param memberId of the user who's ratings will be displayed
     */
    static void displayUserRatings(Book &b, Member &m,
                                   Rating &r, int memberId);

    /**
     * Method to find a user's most similar member, display their name,
     * and display the most similar member's liked and really liked books
     * @param b Book object containing book data
     * @param m Member object containing member data
     * @param r rating object containing rating data
     * @param memberId of the user who's recommendations are to be found
     */
    static void displayRecommendations(Book &b, Member &m,
                                       Rating &r, int memberId);

    /**
     * Method to allow a user to rate or re-rate a book
     * @param b Book object containing book data
     * @param m Member object containing member data
     * @param r rating object containing rating data
     * @param memberId of the user who will rate a book
     */
    static void rateBook(Book &b, Member &m, Rating &r, int memberId);

    /**
     * Method that displays the application's goodbye message
     */
    static void exitProgram();
};


#endif //P3_DRIVER_H
