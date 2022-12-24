#include "ShapeManager.hpp"
#include <memory>
using std::make_shared;

namespace shapes {
    const std::map<ShapeManager::ShapeType, std::string> ShapeManager::shapeTypes = {
      { ShapeManager::ShapeType::Square,   "Square"  },
      { ShapeManager::ShapeType::Circle,   "Circle"  },
      { ShapeManager::ShapeType::Triangle, "Triangle"}
    };

    
    ShapePtr ShapeManager::makeShape(ShapeManager::ShapeType type, int x, int y, int size, Color color) {
        if (ShapeType::Triangle == type) {
            return make_shared<Triangle>(x, y, size, color);
        }
        else if (ShapeType::Circle == type) {
            return make_shared<Circle>(x, y, size, color);
        }
        else if (ShapeType::Square == type) {
            return make_shared<Square>(x, y, size, color);
        }
        else {
            return nullptr;
        }
    }
    void ShapeManager::addShape(ShapePtr shape) {
        //New element gets added at the top of list
        shapes.insert(shapes.begin(), shape);
    }

    ShapePtr ShapeManager::select(int x, int y) {
        for (int i = 0; i < shapes.size(); ++i) {
            if (shapes.at(i)->contains(x, y)) {
                shapes.insert(shapes.begin(), shapes.at(i));
                shapes.erase(shapes.begin() + i + 1);
                return shapes.at(0);
            }
        }
        return nullptr;
    }

    void ShapeManager::drawShapes(Canvas& canvas) const {
        for (int i = shapes.size() - 1; i >= 0; --i) {
            shapes.at(i)->draw(canvas);
        }
    }
}