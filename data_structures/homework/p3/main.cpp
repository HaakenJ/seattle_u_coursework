#include <iostream>
#include <bits/stdc++.h>
#include "Rating.h"
#include "Book.h"
#include "Member.h"

using namespace std;

/**
 * Function to load all books from a file and store them in a passed-in
 * book object
 * @param fileName - name of the file containing book info
 * @param book - address of a book object
 */
void loadBooks(const string &fileName, Book &book) {
    auto *currentBook = new string[4];
    int isbn = 1;

    string filepath = "../" + fileName;
    string bookLine;
    ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        // Proceed while lines are being read from file
        while(getline(inFile, bookLine)) {
            istringstream ss(bookLine);

            // Add the isbn as the position in the list
            // The isbn being index + 1 is an implementation decision
            currentBook[0] = to_string(isbn++);

            // Add the author, title, and year to currentBook
            // in positions 1, 2, 3.
            int i = 0;
            string bookInfo;
            while (getline(ss, bookInfo, ',')) {
                currentBook[++i] = bookInfo;
            }

            // Add the book to the list the Book's list
            book.addBook(currentBook[0], currentBook[1],
                         currentBook[2], currentBook[3]);
        }
    } else  {
        // File name was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }

    // Perform cleanup
    inFile.close();
    delete [] currentBook;
}

/**
 * This function will load data from a member-rating file.
 * File needs to be formatted as such:
*     Member name
*     List of space separated ratings (i.e. 0 3 4 3 2 1)
 * @param filepath - path to the ratings.txt file
 * @param member - address of a Member object
 * @param rating - address of a Rating object
 */
void loadMemberRatingData(const string &fileName, Member &member, Rating &rating) {

    // numMembers will keep track of memberId's
    int numMembers = 0;
    int numBooks;
    string filepath = "../" + fileName;

    string name;
    string memberRatings;
    ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        // Proceed while lines are being read from file
        while (getline(inFile, name)) {
            member.addMember(name);

            // After a name is read, next line is the member's book ratings
            if (getline(inFile, memberRatings)) {
                istringstream ss(memberRatings);
                numBooks = -1;

                // While there is data in the input stream
                while (ss) {
                    int currRating;
                    ss >> currRating;
                    // Assign the rating to the associated member's
                    // rating array
                    rating.addRating(numMembers, ++numBooks, currRating);
                }
            }
            numMembers++;
        }
    } else  {
        // Filepath was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }

    cout << "# of books: " << numBooks << endl;
    cout << "# of members: " << numMembers << endl;
    cout << endl;

    // Perform cleanup
    inFile.close();
}

int openingScreen() {
    cout << endl;
    cout << "************** MENU **************" << endl;
    cout << "* 1. Add a new member            *" << endl;
    cout << "* 2. Add a new book              *" << endl;
    cout << "* 3. Login                       *" << endl;
    cout << "* 4. Quit                        *" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    int response;
    cout << "Enter a menu option: ";
    cin >> response;

    while (response < 1 || response > 4) {
        cout << "That is not a valid selection. ";
        cout << "Please enter a menu option: ";
        cin >> response;
    }

    cout << endl;

    return response;
}

void memberLogin(Member m) {
    int memberId;

    // Get users member Id
    cout << "Enter member ID: ";
    cin >> memberId;
    cout << endl;

    // Do not allow the user to enter an incorrect id
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
}

int loggedInScreen(Book b, Member m, Rating r) {
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

void initialDriver(Book b, Member m, Rating r) {

    switch (openingScreen()) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            memberLogin(m);
            loggedInScreen(b, m, r);
            break;
        case 4:
            break;
    }
}

int main() {
    Book b;
    Member m;
    Rating r(30);

    loadBooks("books.txt", b);
    loadMemberRatingData("ratings.txt", m, r);

    initialDriver(b, m, r);

    return 0;
}