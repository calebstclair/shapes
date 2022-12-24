//
// Created by Caleb St. Clair on 11/2/22.
//

#include "Circle.hpp"
#include <cmath>

namespace shapes {

    Circle::Circle(int x, int y, int size, Color color) : Shape(x, y, size, color) {
        center = { topLeftOfBox.x + (sizeOfShape / 2), topLeftOfBox.y + (sizeOfShape / 2) };
    }
    bool Circle::contains(int x, int y) const {
    //√(p.x – q.x)2 + (p.y – q.y)2
        double xside = std::pow((center.x - x), 2);
        double yside = std::pow((center.y - y), 2);
        double containsPoint = std::sqrt(xside + yside);
        if (containsPoint < sizeOfShape / 2.0) {
            return true;
        } else {
            return false;
        }
    }

    void Circle::draw(Canvas& canvas) const {
        canvas.drawEllipse(center, sizeOfShape / 2.0, 0, color());
    }

    ShapePtr Circle::clone() const {
        return std::make_shared<Circle>(*this);
    }

    void Circle::move(int x, int y) {
        Shape::move(x, y);
        center = { topLeftOfBox.x + (sizeOfShape / 2), topLeftOfBox.y + (sizeOfShape / 2) };
    }
}
