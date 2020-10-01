#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "Book.h"

using namespace std;

/**
 * This function will print data from a member-rating file.
 * File needs to be formatted as such:
*     Member name
*     List of space separated ratings (i.e. 0 3 4 3 2 1)
 * @param filepath - path to the ratings.txt file
 */
void loadAndPrintBooks(const string &fileName, Book &book) {
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

    cout << "# of books: " << book.size() << endl;
    cout << endl;

    // Print the info for all books
    for (int i = 1; i <= book.size(); ++i) {
        int bookId = book.lookupISBN(to_string(i));
        book.printBook(bookId);
    }

    // Perform cleanup
    inFile.close();
    delete [] currentBook;
}

int main() {
    Book book;
    loadAndPrintBooks("books.txt", book);
    return 0;
}
