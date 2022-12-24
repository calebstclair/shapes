#include "Shape.hpp"
#include "ShapeManager.hpp"
#include "TestCanvas.hpp"
#include <gtest/gtest.h>

const easywin::Color BLUE = easywin::rgb(0, 0, 255);
const easywin::Color GREEN = easywin::rgb(0, 255, 0);
const easywin::Color BLACK = 0;

TEST(Triangle, BoundingBox) {
    auto p = shapes::ShapeManager::makeShape(
        shapes::ShapeManager::ShapeType::Triangle,
        150,
        250,
        100,
        GREEN
    );

    ASSERT_EQ(p->x(), 150);
    ASSERT_EQ(p->y(), 250);
    ASSERT_EQ(p->size(), 100);
}

TEST(Triangle, Move) {
    auto p = shapes::ShapeManager::makeShape(
        shapes::ShapeManager::ShapeType::Triangle,
        100,
        200,
        100,
        BLUE
    );

    p->move(123, 456);
    ASSERT_EQ(p->x(), 123);
    ASSERT_EQ(p->y(), 456);

    p->move(1000, 2500);
    ASSERT_EQ(p->x(), 1000);
    ASSERT_EQ(p->y(), 2500);
}

TEST(Triangle, Resize) {
    auto p = shapes::ShapeManager::makeShape(
        shapes::ShapeManager::ShapeType::Triangle,
        100,
        200,
        100,
        BLUE
    );

    p->resize(400);
    ASSERT_EQ(p->size(), 400);

    p->resize(150);
    ASSERT_EQ(p->size(), 150);
}

TEST(Triangle, Clone) {
    auto p = shapes::ShapeManager::makeShape(
        shapes::ShapeManager::ShapeType::Triangle,
        100,
        200,
        300,
        GREEN
    );

    auto q = p->clone();
    ASSERT_NE(p, q);
    ASSERT_EQ(typeid(*p), typeid(*q));
    ASSERT_EQ(p->x(), q->x());
    ASSERT_EQ(p->y(), q->y());
    ASSERT_EQ(p->size(), q->size());
    ASSERT_EQ(p->color(), q->color());
}

TEST(Triangle, Contains) {
    auto p = shapes::ShapeManager::makeShape(
        shapes::ShapeManager::ShapeType::Triangle,
        100,
        200,
        100,
        BLUE
    );

    ASSERT_TRUE(p->contains(150, 250));
}