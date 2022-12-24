//
// Created by Caleb St. Clair on 11/2/22.
//

#include "Square.hpp"

namespace shapes {
    bool shapes::Square::contains(int x, int y) const {
        if ((topLeftOfBox.x <= x && topLeftOfBox.y <= y) &&
                (x <= XOfBox && y <= YOfBox)){
            return true;
        }
        else{
            return false;
        }
    }

    void Square::draw(Canvas& canvas) const {
        canvas.drawRectangle(topLeftOfBox.x, topLeftOfBox.y, XOfBox, YOfBox, 0, color());
    }
    ShapePtr Square::clone() const {
        return std::make_shared<Square>(*this);
    }
}
