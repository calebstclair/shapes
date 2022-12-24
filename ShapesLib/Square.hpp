//
// Created by Caleb St. Clair on 11/2/22.
//

#pragma once
#include "Shape.hpp"
#include "Canvas.hpp"

namespace shapes{
class Square : public Shape{
public:
        using Shape::Shape;
        bool contains(int x, int y) const override;
        void draw(Canvas& canvas) const override;
        ShapePtr clone() const override;
    };
}
