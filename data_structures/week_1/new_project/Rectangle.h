//
// Created by Haake on 9/10/2020.
//

#ifndef NEW_PROJECT_RECTANGLE_H
#define NEW_PROJECT_RECTANGLE_H

// If you include this file twice, ignore the second time
#pragma once;

class Rectangle {
public:
    Rectangle();

    Rectangle(double width, double height);

    void setWidth(double width);

    void setHeight(double height);

    double getWidth() const;

    double getHeight() const;

    double getArea() const;

private:
    double width, height;
};


#endif //NEW_PROJECT_RECTANGLE_H
