//
// Created by Caleb St. Clair on 11/2/22.
//
#include "Triangle.hpp"


namespace shapes {
    Triangle::Triangle(int x, int y, int size, Color color) : Shape(x, y, size, color) {
        topOfTriangle = { topLeftOfBox.x + (sizeOfShape / 2), topLeftOfBox.y };
        //Stores top point, then left point, then right point
        PointsOfTriangle.push_back(topOfTriangle);
        PointsOfTriangle.push_back(Point{ topLeftOfBox.x, YOfBox });
        PointsOfTriangle.push_back(Point{ XOfBox, YOfBox });
    }
    bool shapes::Triangle::contains(int x, int y) const{
        //Checks if the y value is within the bounding box then tests if the slope of the line is greater or equal to -2 or 2
        if (topLeftOfBox.y < y && y < YOfBox){
            double slopeOfTriangle = double(topOfTriangle.y - y) / double(topOfTriangle.x - x);
            if(slopeOfTriangle >= 2 || slopeOfTriangle <= -2){
                return true;
            }
        }
        return false;
    }

    void Triangle::draw(Canvas &canvas) const {
        canvas.drawPolygon(PointsOfTriangle, 0, color());
    }

    ShapePtr Triangle::clone() const {
        return std::make_shared<Triangle>(*this);
    }
    
    void Triangle::resize(int size) {
        Shape::resize(size);
        PointsOfTriangle.clear();
        topOfTriangle = { topLeftOfBox.x + (sizeOfShape / 2), topLeftOfBox.y };
        //Stores top point, then left point, then right point
        PointsOfTriangle.push_back(topOfTriangle);
        PointsOfTriangle.push_back(Point{ topLeftOfBox.x, YOfBox });
        PointsOfTriangle.push_back(Point{ XOfBox, YOfBox });
    }
    
    void Triangle::move(int x, int y) {
        Shape::move(x, y);
        PointsOfTriangle.clear();
        topOfTriangle = { topLeftOfBox.x + (sizeOfShape / 2), topLeftOfBox.y };
        PointsOfTriangle.push_back(topOfTriangle);
        PointsOfTriangle.push_back(Point{ topLeftOfBox.x, YOfBox });
        PointsOfTriangle.push_back(Point{ XOfBox, YOfBox });
    }
}
