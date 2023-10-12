#include <stdio.h>
#include <stdlib.h>

typedef struct Shape Shape;
typedef struct Rectangle Rectangle;
typedef struct Square Square;
typedef struct Triangle Triangle;
typedef struct shapeVTable shapeVTable;
typedef struct rectangleVTable rectangleVTable;
typedef struct squareVTable squareVTable;
typedef struct triangleVTable triangleVTable;

// Structs

struct Shape {
    int numSides;
    const shapeVTable* vtable;
};

struct Rectangle {
    Shape* parent;
    double length, width;
    const rectangleVTable* vtable;
};

struct Square {
    Rectangle* parent;
    const squareVTable* vtable;
};

struct Triangle {
    Shape* parent;
    double base, height;
    const triangleVTable* vtable;
};

// VTable Structs

struct shapeVTable {
    void (*printNumSides)(Shape* self);
};

struct rectangleVTable {
    void (*printNumSides)(Shape* self);
    double (*area)(Rectangle* self);
    double (*perimeter)(Rectangle* self);
};

struct squareVTable {
    void (*printNumSides)(Shape* self);
    double (*area)(Square* self);
    double (*perimeter)(Square* self);
};

struct triangleVTable {
    void (*printNumSides)(Shape* self);
    double (*area)(Triangle* self);
};

// Functions

void print_num_sides(Shape* shape) {
    printf("Shape has %d sides\n", shape->numSides);
}

double triangle_area(Triangle* shape) {
    return shape->base * shape->height / 2;
}

double rectangle_area(Rectangle* shape) {
    return shape->length * shape->width;
}

double rectangle_perimeter(Rectangle* shape) {
    return shape->length * 2 + shape->width * 2;
}

double square_area(Square* shape) {
    return rectangle_area(shape->parent);
}

double square_perimeter(Square* shape) {
    return rectangle_perimeter(shape->parent);
}

// VTables

static const shapeVTable vtable_shape = {
    .printNumSides = print_num_sides
};

static const rectangleVTable vtable_rectangle = {
    .printNumSides = print_num_sides,
    .area = rectangle_area,
    .perimeter = rectangle_perimeter
};

static const squareVTable vtable_square = {
    .printNumSides = print_num_sides,
    .area = square_area,
    .perimeter = square_perimeter
};

static const triangleVTable vtable_triangle = {
    .printNumSides = print_num_sides,
    .area = triangle_area
};

// Init Functions

Shape* initShape(int sides) {
    Shape* res = (Shape*) malloc(sizeof(Shape));
    res->numSides = sides;
    res->vtable = &vtable_shape;
    return res;
}

Rectangle* initRectangle(int length, int width) {
    Rectangle* res = (Rectangle*) malloc(sizeof(Rectangle));
    res->length = length;
    res->width = width;
    res->parent = initShape(4);
    res->vtable = &vtable_rectangle;
    return res;
}

Square* initSquare(int length) {
    Square* res = (Square*) malloc(sizeof(Square));
    res->parent = initRectangle(length, length);
    res->vtable = &vtable_square;
    return res;
}

Triangle* initTriangle(int base, int height) {
    Triangle* res = (Triangle*) malloc(sizeof(Triangle));
    res->base = base;
    res->height = height;
    res->parent = initShape(3);
    res->vtable = &vtable_triangle;
    return res;
}

// Delete Functions

void deleteShape(Shape* shape) {
    free(shape);
}

void deleteRectangle(Rectangle* shape) {
    deleteShape(shape->parent);
    free(shape);
}

void deleteSquare(Square* shape) {
    deleteRectangle(shape->parent);
    free(shape);
}

void deleteTriangle(Triangle* shape) {
    deleteShape(shape->parent);
    free(shape);
}

int main() {
    Rectangle* rect = initRectangle(5, 4);
    rect->vtable->printNumSides(rect->parent);
    printf("Rectangle area: %lf\n", rect->vtable->area(rect));
    printf("Rectangle perimeter: %lf\n", rect->vtable->perimeter(rect));

    Square* square = initSquare(5);
    square->vtable->printNumSides(square->parent->parent);
    printf("Square area: %lf\n", square->vtable->area(square));
    printf("Square perimeter: %lf\n", square->vtable->perimeter(square));

    Triangle* tri = initTriangle(5, 4);
    tri->vtable->printNumSides(tri->parent);
    printf("Triangle area: %lf\n", tri->vtable->area(tri));

    deleteRectangle(rect);
    deleteSquare(square);
    deleteTriangle(tri);

    return 0;
}