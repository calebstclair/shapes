#pragma once
#include <map>
#include <string>
#include "Shape.hpp"
#include <vector>
#include "Circle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"

namespace shapes {

  class ShapeManager {
  public:
    enum class ShapeType { Square, Circle, Triangle };
    const static std::map<ShapeType, std::string> shapeTypes;

    static ShapePtr makeShape(ShapeType type, int x, int y, int size, Color color);
    void addShape(ShapePtr shape);
    ShapePtr select(int x, int y);
    void drawShapes(Canvas& canvas) const;

  private:
    std::vector<ShapePtr> shapes;
  };

}  // namespace shapes
