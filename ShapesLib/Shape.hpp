#pragma once
#include "Canvas.hpp"
#include <memory>

namespace shapes {

    using easywin::Canvas;
    using easywin::Color;
    using easywin::Point;
    class Shape;
    using ShapePtr = std::shared_ptr<Shape>;

    class Shape {
    public:
        //A constructor that takes the x and y coordinates, the size of the bounding box, and the color
        Shape(int x, int y, int size, Color color);

        //Get the x coordinate of the upper-left corner of the bounding box
        int x() const;

        //Get the y coordinate of the upper-left corner of the bounding box
        int y() const;

        //Get the size of the bounding box
        int size() const;

        //Get the color of the shape
        Color color() const;

        //Moves the upper-left corner of the shape to the specified position. You do not have to do any bounds checking.
        virtual void move(int x, int y);

        //Set the size of the shape to the specified amount. If the new size is smaller than 10, then just set the size to 10. If the new size is bigger than 500, then just set it to 500.
        virtual void resize(int size);

        //Returns a new copy of the shape.
        virtual ShapePtr clone() const = 0;

        //Returns true if the point is inside the shape, false otherwise. (Note that just because the point is in the bounding box does not mean the point is in the shape.)
        virtual bool contains(int x, int y) const = 0;

        //Indicates that the shape should draw itself on the canvas using its current location and size. Remember to check the canvas.hpp header file to find the names of the drawing functions you can use.
        virtual void draw(easywin::Canvas& canvas) const = 0;

        virtual ~Shape();

    protected:
        Color shapeColor;
        Point topLeftOfBox;
        int sizeOfShape;
        int XOfBox;
        int YOfBox;
    };


}
