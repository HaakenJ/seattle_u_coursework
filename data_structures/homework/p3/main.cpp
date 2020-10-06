#include <iostream>
#include <bits/stdc++.h>
#include "Rating.h"
#include "Book.h"

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

int main() {
    Book book;

    loadBooks("books.txt", book);

    for (int i = 0; i < book.size(); ++i) {
        book.printBook(i);
    }

    return 0;
}