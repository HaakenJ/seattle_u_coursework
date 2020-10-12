//
// Created by Haake on 10/6/2020.
//

#include "Driver.h"
#include <iostream>

using namespace std;


int Driver::openingScreen() {
    cout << endl;
    cout << "************** MENU **************" << endl;
    cout << "* 1. Add a new member            *" << endl;
    cout << "* 2. Add a new book              *" << endl;
    cout << "* 3. Login                       *" << endl;
    cout << "* 4. Quit                        *" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    // Get user choice
    int response;
    cout << "Enter a menu option: ";
    cin >> response;

    // Do not allow invalid choices
    while (response < 1 || response > 4) {
        cout << "That is not a valid selection. ";
        cout << "Please enter a menu option: ";
        cin >> response;
    }

    cout << endl;
    return response;
}


void Driver::initialDriver(Book &b, Member &m, Rating &r) {
    int memberId;
    int choice;
    switch (openingScreen()) {
        case 1:
            addMember(m);
            initialDriver(b, m, r);
            break;
        case 2:
            addBook(b);
            initialDriver(b, m, r);
            break;
        case 3:
            memberId = memberLogin(m);
            choice = loggedInScreen(b, m, r);
            loggedInDriver(b, m, r, memberId, choice);
            break;
        case 4:
            exitProgram();
            return;
    }
}

void Driver::loggedInDriver(Book &b, Member &m, Rating &r, int memberId, int choice) {
    switch (choice) {
        case 1:
            addMember(m);
            choice = loggedInScreen(b, m, r);
            loggedInDriver(b, m, r, memberId, choice);
            break;
        case 2:
            addBook(b);
            choice = loggedInScreen(b, m, r);
            loggedInDriver(b, m, r, memberId, choice);
            break;
        case 3:
            rateBook(b, m, r, memberId);
            choice = loggedInScreen(b, m, r);
            loggedInDriver(b, m, r, memberId, choice);
            break;
        case 4:
            displayUserRatings(b, m, r, memberId);
            choice = loggedInScreen(b, m, r);
            loggedInDriver(b, m, r, memberId, choice);
            break;
        case 5:
            displayRecommendations(b, m, r, memberId);
            choice = loggedInScreen(b, m, r);
            loggedInDriver(b, m, r, memberId, choice);
            break;
        default:
            memberLogout(m, memberId);
            initialDriver(b, m, r);
    }
}

int Driver::loggedInScreen(Book &b, Member &m, Rating &r) {
    cout << "************** MENU **************" << endl;
    cout << "* 1. Add a new member            *" << endl;
    cout << "* 2. Add a new book              *" << endl;
    cout << "* 3. Rate a book                 *" << endl;
    cout << "* 4. View ratings                *" << endl;
    cout << "* 5. See recommendations         *" << endl;
    cout << "* 6. Logout                      *" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    // Get user choice
    int response;
    cout << "Enter a menu option: ";
    cin >> response;

    // Do not allow invalid choices
    while (response < 1 || response > 6) {
        cout << "That is not a valid selection. ";
        cout << "Please enter a menu option: ";
        cin >> response;
        cout << endl;
    }

    cout << endl;
    return response;
}

int Driver::memberLogin(Member &m) {
    int memberId;

    // Get users member Id
    cout << "Enter member ID: ";
    cin >> memberId;
    cout << endl;

    // Do not allow invalid member id
    while (memberId >= m.size()) {
        cout << "That is not a valid member Id. ";
        cout << "Please enter the correct id: ";
        cin >> memberId;
        cout << endl;
    }

    // Log the user in and notify
    m.login(memberId);
    cout << m.findName(memberId) << ", you are logged in!" << endl;
    cout << endl;

    return memberId;
}

void Driver::memberLogout(Member &m, int memberId) {
    // Log user out
    m.logout(memberId);
    cout << endl;
}

void Driver::addMember(Member &m) {

    // Get new member name
    string newName;
    cout << "Enter the name of the new member :";
    cin >> newName;

    // Add member to Member object
    int memberId = m.addMember(newName);

    // Notify user than new member has been added
    cout << m.findName(memberId);
    cout << " (member Id: " << memberId;
    cout << ") was added." << endl;
    cout << endl;
}

void Driver::addBook(Book &b) {
    string author;
    string title;
    string year;

    // set isbn
    string isbn = to_string(b.size() + 1);

    // Remove the hanging newline character
    cin.get();

    // Get info about new book
    cout << "Enter the author of the new book: ";
    getline(cin, author);

    cout << "Enter the title of the new book: ";
    getline(cin, title);

    cout << "Enter the year (or range of years) of the new book: ";
    getline(cin, year);
    cout << endl;

    // Add book to Book object
    b.addBook(isbn, author, title, year);

    // Newest book will always have a bookId(index) of one less than the size
    // Always the last item in the bookArrray
    b.printBook(b.size() - 1);
    cout << " was added." << endl;
    cout << endl;
}

void Driver::displayUserRatings(Book &b, Member &m, Rating &r, int memberId) {
    cout << m.findName(memberId) << "'s ratings..." << endl;

    for (int i = 0; i < b.size(); ++i) {
        b.printBook(i);
        cout << " => rating: " << r.getRating(memberId, i);
        cout << endl;
    }
    cout << endl;
}

void Driver::displayRecommendations(Book &b, Member &m, Rating &r, int memberId) {

    // Get most similar member
    int mostSimilar = r.mostSimilar(memberId);

    // Notify user of their most similar member
    cout << "You have similar taste in books as ";
    cout << m.findName(mostSimilar) << "!" << endl;
    cout << endl;

    // Display mostSimilar's books with rating of 5
    cout << "Here are the books they really liked:" << endl;
    for (int i = 0; i < b.size(); ++i) {
        if (r.getRating(mostSimilar, i) == 5) {
            b.printBook(i);
            cout << endl;
        }
    }
    cout << endl;

    // Display mostSimilar's books with rating of 3
    cout << "And here are the books they liked:" << endl;
    for (int i = 0; i < b.size(); ++i) {
        if (r.getRating(mostSimilar, i) == 3) {
            b.printBook(i);
            cout << endl;
        }
    }
    cout << endl;
}

void Driver::rateBook(Book &b, Member &m, Rating &r, int memberId) {

    // Get isbn
    int isbn;
    cout << "Enter the ISBN for the book you'd like to rate: ";
    cin >> isbn;

    // Isbn == (index in bookArray) + 1
    while (isbn < 1 || isbn > b.size()) {
        cout << "That is an invalid isbn.  Please enter an ISBN: ";
        cin >> isbn;
    }
    cout << endl;

    // Get the book id from the isbn
    int bookId = b.lookupISBN(to_string(isbn));

    // Check if the book has already been rated
    if (r.getRating(memberId, bookId) != 0) {
        cout << "Your current rating for ";
        b.printBook(bookId);
        cout << " => rating: " << r.getRating(memberId, bookId) << endl;

        cout << "Would you like to re-rate this book (y/n)? ";
        string reRate;
        cin >> reRate;

        // Require y or n response
        while (reRate != "y" && reRate != "n") {
            cout << "Please enter (y/n): ";
            cin >> reRate;
        }

        // Exit if response is 'n'
        if (reRate == "n") {
            cout << endl;
            return;
        }
    }

    // Let user rate the book
    int rating;
    cout << "Enter your rating: ";
    cin >> rating;
    cout << endl;

    // Require valid rating
    while (
            rating != -5 &&
            rating != -3 &&
            rating != 3 &&
            rating != 5 &&
            rating != 1
            ) {
        cout << "    ____ ______________________" << endl;
        cout << "   | -5 | Hated it!            |" << endl;
        cout << "   | -3 | Didn't like it       |" << endl;
        cout << "   |  1 | neither hot nor cold |" << endl;
        cout << "   |  3 | Liked it!            |" << endl;
        cout << "   |  5 | Really liked it!     |" << endl;
        cout << "    ---------------------------" << endl;
        cout << "Please enter a valid rating: " << endl;
        cin >> rating;
        cout << endl;
    }

    // Display the user's book and rating
    r.addRating(memberId, bookId, rating);
    cout << "Your new rating for ";
    b.printBook(bookId);
    cout << " => rating: " << rating << endl;

    cout << endl;
}

void Driver::exitProgram() {
    cout << "Thank you for using the Book Recommendation Program!" << endl;
}

