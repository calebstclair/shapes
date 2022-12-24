//
// Created by Caleb St. Clair on 11/2/22.
//
#include "Shape.hpp"

namespace shapes {
    //TODO Do these need to be included in both the .hpp and .cpp
    using easywin::Canvas;
    using easywin::Color;
    using easywin::Point;

    Shape::Shape(int x, int y, int size, Color color) {
        topLeftOfBox = { x,y };
        sizeOfShape = size;
        shapeColor = color;
        YOfBox = int(topLeftOfBox.y) + sizeOfShape;
        XOfBox = int(topLeftOfBox.x) + sizeOfShape;
    }

    int Shape::x() const {
        return int(topLeftOfBox.x);
    }

    int Shape::y() const {
        return int(topLeftOfBox.y);
    }

    int Shape::size() const {
        return sizeOfShape;
    }

    Color Shape::color() const {
        return shapeColor;
    }

    void Shape::move(int x, int y) {
        topLeftOfBox.x = x;
        topLeftOfBox.y = y;
        XOfBox = topLeftOfBox.x + sizeOfShape;
        YOfBox = topLeftOfBox.y + sizeOfShape;
    }

    void Shape::resize(int size) {
        if (size < 10) {
            sizeOfShape = 10;
        }
        else if (500 < size) {
            sizeOfShape = 500;
        }
        else {
            sizeOfShape = size;
        }
        XOfBox = topLeftOfBox.x + sizeOfShape;
        YOfBox = topLeftOfBox.y + sizeOfShape;
    }
    
    Shape::~Shape() = default;

}
