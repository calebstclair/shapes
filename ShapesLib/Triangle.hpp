//
// Created by Caleb St. Clair on 11/2/22.
//

#pragma once
#include "Shape.hpp"
#include "Canvas.hpp"
#include <vector>
namespace shapes{
    class Triangle : public Shape{
    public:
        Triangle(int x, int y, int size, Color color);
        void move(int x, int y) override;
        void resize(int size) override;
        bool contains(int x, int y) const override;
        void draw(Canvas &canvas) const override;
        ShapePtr clone() const override;
    private:
        Point topOfTriangle = { XOfBox / 2, topLeftOfBox.y };
        //Creates a vector to store the points
        std::vector<Point> PointsOfTriangle;
    };
}
