#include <iostream>
#include <bits/stdc++.h>
#include "Rating.h"
#include "Book.h"

using namespace std;

int main() {
    Rating rates(3);

    rates.addRating(0, 0, 5);
    rates.addRating(0, 1, 3);
    rates.addRating(0, 2, -5);

    rates.addRating(1, 0, 5);
    rates.addRating(1, 1, -3);
    rates.addRating(1, 2, 5);

    rates.addRating(2, 0, 1);
    rates.addRating(2, 1, 5);
    rates.addRating(2, 2, -3);

    cout << rates.mostSimilar(0);

    return 0;
}