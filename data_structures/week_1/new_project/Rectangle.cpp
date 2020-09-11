//
// Created by Haake on 9/10/2020.
//

#include "Rectangle.h"

// Definition
Rectangle::Rectangle() {
    width = 0;
    height = 0;
}

Rectangle::Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
}

void Rectangle::setHeight(double newHeight) {
    height = newHeight;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(double newWidth) {
    width = newWidth;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getArea() const {
    return width * height;
}