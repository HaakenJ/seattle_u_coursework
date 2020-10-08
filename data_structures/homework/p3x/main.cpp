#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Rating.h"
#include "Book.h"
#include "Member.h"
#include "Driver.h"

using namespace std;

/**
 * Function to load all books from a file and store them in a passed-in
 * book object
 * @param fileName - name of the file containing book info
 * @param book - address of a book object
 */
void loadBooks(Book &book) {
    auto *currentBook = new string[4];
    int isbn = 1;
    string filepath = "../books-updated.txt";

    string bookLine;
    ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    // If the opening failed, prompt the user for a file name
    if (inFile.fail()) {
        cout << "Please enter the name of a books file: ";
        cin >> filepath;
        filepath = "../" + filepath;

        // Attempt to open file
        inFile.open(filepath);
    }

    if (inFile.is_open()) {
        // Proceed while lines are being read from file
        while (getline(inFile, bookLine)) {
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
    } else {
        // File name was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }

    // Perform cleanup
    inFile.close();
    delete[] currentBook;
}

/**
 * This function will load data from a member-rating file.
 * File needs to be formatted as such:
*     Member name
*     List of space separated ratings (i.e. 0 3 4 3 2 1)
 * @param fileName - name of the file containing member and rating data
 * @param member - address of a Member object
 * @param rating - address of a Rating object
 */
void loadMemberRatingData(Member &member,
                          Rating &rating) {

    // numMembers will keep track of memberId's
    int numMembers = 0;
    int numBooks;
    string filepath = "../ratings-updated.txt";

    string name;
    string memberRatings;
    ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    // If the opening failed, prompt the user for a file name
    if (inFile.fail()) {
        cout << "Please enter the name of a ratings file: ";
        cin >> filepath;
        filepath = "../" + filepath;

        // Attempt to open file
        inFile.open(filepath);
    }

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
    } else {
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

/**
 * Function to write all book, member, and rating data to a file
 * @param b Book object containing book data
 * @param m Member object containing member data
 * @param r rating object containing rating data
 */
void writeDataToFile(Book &b, Member &m, Rating &r) {
    string bookFile = "../books-updated.txt";
    string ratingsFile = "../ratings-updated.txt";

    ofstream updatedBooks;
    ofstream updatedRatings;

    updatedBooks.open(bookFile);
    updatedRatings.open(ratingsFile);

    if (updatedBooks) {
        for (int i = 0; i < b.size(); ++i) {
            updatedBooks << b.getBookString(i) + "\n";
        }
    } else {
        // Filepath was invalid, exit application
        cout << "ERROR: cannot open/create updated book file";
        return;
    }

    if (updatedRatings) {
        for (int i = 0; i < m.size(); ++i) {
            updatedRatings << m.findName(i) + "\n";
            for (int j = 0; j < b.size(); ++j) {
                updatedRatings << to_string(r.getRating(i, j)) + " ";
            }
            updatedRatings << "\n";
        }
    } else {
        // Filepath was invalid, exit application
        cout << "ERROR: cannot open/create updated book file";
        return;
    }

    // Cleanup
    updatedBooks.close();
    updatedRatings.close();
}

int main() {
    Book b;
    Member m;
    Rating r(30);

    loadBooks(b);
    loadMemberRatingData(m, r);

    Driver::initialDriver(b, m, r);

    writeDataToFile(b, m, r);

    return 0;
}