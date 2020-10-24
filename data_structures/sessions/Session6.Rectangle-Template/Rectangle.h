//
// Created by Kevin Lundeen on 10/15/20.
//

#pragma once

/**
 * Rectangle class
 *
 * @tparam T the datatype of the rectangle dimensions
 */
template<typename T>
class Rectangle {
public:
    Rectangle();
    Rectangle(T width, T length);
    Rectangle(const Rectangle<T> &other);
    Rectangle<T> &operator=(const Rectangle<T> &rhs);

    void setWidth(T newWidth);
    void setLength(T newLength);
    T getWidth() const;
    T getLength() const;
    T getArea() const;

private:
    T width, length;
};

template<typename T>
Rectangle<T>::Rectangle(const Rectangle<T> &other) {
    width = other.width;
    length = other.length;
}

template<typename T>
Rectangle<T> &Rectangle<T>::operator=(const Rectangle<T> &rhs) {
    if (&rhs != this) {
        // no destruction necessary
        width = rhs.width;
        length = rhs.length;
    }
    return *this;
}

template<typename T>
Rectangle<T>::Rectangle() {
    width = 0;
    length = 0;
}

template<typename T>
Rectangle<T>::Rectangle(T width, T length) {
    this->width = width;
    this->length = length;
}

template<typename T>
T Rectangle<T>::getWidth() const {
    return width;
}

template<typename T>
T Rectangle<T>::getLength() const {
    return length;
}

template<typename T>
void Rectangle<T>::setWidth(T newWidth) {
    width = newWidth;
}

template<typename T>
void Rectangle<T>::setLength(T newLength) {
    length = newLength;
}

template<typename T>
T Rectangle<T>::getArea() const {
    return width * length;
}

