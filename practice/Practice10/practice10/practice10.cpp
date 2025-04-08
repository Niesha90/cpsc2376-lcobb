#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>


class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4)
            << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Unable to open file shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line, type;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        ss >> type;

        if (type == "rectangle") {
            double width, height;
            ss >> width >> height;
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        }
        else if (type == "circle") {
            double radius;
            ss >> radius;
            shapes.push_back(std::make_unique<Circle>(radius));
        }
    }

    printAllAreas(shapes);

    return 0;
}


