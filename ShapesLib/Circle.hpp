//
// Created by Caleb St. Clair on 11/2/22.
//
#pragma once
#include "Shape.hpp"
#include "Canvas.hpp"

namespace shapes {
    class Circle : public Shape {
    public:
        Circle(int x, int y, int size, Color color);
        bool contains(int x, int y) const override;
        void draw(Canvas &canvas) const override;
        ShapePtr clone() const override;
        void move(int x, int y) override;
    private:
        Point center;
    };
}
