#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void loadExternalData(const string &filepath) {
    string *members;
    int numMembers = 0;
    int **ratings;
    int numBooks;

    // Allocate memory for 2D array
    members = new string[100];
    ratings = new int*[100];
    for (int i = 0; i < 100; i++)
        ratings[i] = new int[100];

    string name;
    string memberRatings;
    ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        // Proceed while lines are being read from file
        while (getline(inFile, name)) {
            members[numMembers] = name;

            // After a name is read, next line is the member's book ratings
            // Read from this next line
            if (getline(inFile, memberRatings)) {
                istringstream ss(memberRatings);
                numBooks = -1;

                // While there is data in the input stream
                while (ss) {
                    int rating;
                    ss >> rating;
                    // Assign the rating to the associated member's
                    // rating array
                    ratings[numMembers][++numBooks] = rating;
                }
                cout << endl;
            }
            numMembers++;
        }
    } else  {
        // Filepath was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }

    cout << "# of members: " << numMembers << endl;
    cout << "# of books: " << numBooks << endl;
    cout << endl;

    // Display members and associated ratings
    for (int i = 0; i < numMembers; i++) {
        cout << members[i] << endl;
        for (int j = 0; j < numBooks; j++) {
            cout << ratings[i][j] << " ";
        }
        cout << endl;
    }
    // Close file
    inFile.close();
}

int main() {
    // Needing to use ../ because Clion's cwd is the location of the .cmake
    // file which is in the Project/CMakeFiles.  The application files along
    // with my rating file are all included in Project/
    loadExternalData("../ratings.txt");
    return 0;
}
