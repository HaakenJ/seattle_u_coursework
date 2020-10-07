//
// Created by Haake on 10/6/2020.
//
#include "Book.h"
#include "Member.h"
#include "Rating.h"

#ifndef P3_DRIVER_H
#define P3_DRIVER_H


class Driver {
public:
    static int openingScreen();

    static void initialDriver(Book &b, Member &m, Rating &r);

    static void loggedInDriver(Book &b, Member &m, Rating &r,
                               int memberId, int choice);

    static int memberLogin(Member &m);

    static void memberLogout(Member &m, int memberId);

    static void addMember(Member &m);

    static void addBook(Book &b);

    static int loggedInScreen(Book &b, Member &m, Rating &r);

    static void displayUserRatings(Book &b, Member &m,
                                   Rating &r, int memberId);

    static void displayRecommendations(Book &b, Member &m,
                                       Rating &r, int memberId);

    static void rateBook(Book &b, Member &m, Rating &r, int memberId);

    static void exitProgram();
};


#endif //P3_DRIVER_H
