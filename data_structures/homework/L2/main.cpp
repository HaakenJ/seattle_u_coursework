#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void testFileOpen(string filepath) {
    const string FILENAME = filepath;
    string name;
    ifstream inFile;

    // now open and read from file (strings)
    inFile.open(filepath);
    if (inFile) {
           while (getline(inFile, name))
              cout << name << endl;
        } else {
           cout << "ERROR: cannot open file.\n";
        }
    inFile.close();
}

void loadExternalData(const string &filepath) {
    string *members;
    int numMembers = 0;
    int **ratings;
    int numRatings = 0;

    // Allocate memory
    members = new string[100];
    ratings = new int*[100];
    for (int i = 0; i < 100; i++)
        ratings[i] = new int[100];

    // Open and read from members
    string name;
    string nums;
    ifstream inFile;
    cout << filepath << endl;
    inFile.open(filepath);
    if (inFile.is_open()) {
        while (getline(inFile, name)) {
            members[numMembers] = name;
            if (getline(inFile, nums)) {
                istringstream ss(nums);
                numRatings = 0;
                while (ss) {
                    int rating;
                    ss >> rating;
                    ratings[numMembers][numRatings++] = rating;
                }
                cout << endl;
            }
            numMembers++;
        }
    } else  {
        cout << "ERROR: cannot open file";
    }
    cout << numRatings << endl;
    for (int i = 0; i < numMembers; i++) {
        cout << members[i] << endl;
        for (int j = 0; j < numRatings; j++) {
            cout << ratings[i][j] << " ";
        }
        cout << endl;
    }
    inFile.close();
}

int main() {
    loadExternalData(R"(D:\Haake\Documents\seattle_u_notes\data_structures\homework\L2\ratings.txt)");
    return 0;
}
