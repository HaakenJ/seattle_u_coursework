//
// Created by Haake on 9/17/2020.
//

#ifndef ICE_1_MEMBER_H
#define ICE_1_MEMBER_H

#include <iostream>
#include "Rating.h"

// Should be included in main
void loadExternalData(std::string filePath);
void quit();

class Member {
public:
    Member();
    Member(const std::string &name, const int account);

    void logUserIn();
    void logUserOut();
    bool getLoginStatus();

    void displayRatings() const;
    void displayRecommended() const;
private:
    std::string name;
    int account;
    Rating *ratings;
    bool loggedIn;
};


#endif //ICE_1_MEMBER_H
