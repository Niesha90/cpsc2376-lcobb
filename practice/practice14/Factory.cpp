#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <map>

// Shape interface
double const PI = 3.141592653589793;
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return PI * radius * radius; }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override { return side * side; }
};

class Rectangle : public Shape {
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

// Factory functions
std::unique_ptr<Shape> makeCircle(std::istringstream& ss)
{
    double r;
    ss >> r;
    return std::unique_ptr<Shape>(new Circle(r));
}

std::unique_ptr<Shape> makeSquare(std::istringstream& ss)
{
    double s;
    ss >> s;
    return std::unique_ptr<Shape>(new Square(s));
}

std::unique_ptr<Shape> makeRectangle(std::istringstream& ss)
{
    double w;
    ss >> w;
    double h;
    ss >> h;
    return std::unique_ptr<Shape>(new Rectangle(w, h));
}

int main()
{
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Cannot open input file.\n";
        return 1;
    }

    std::map<std::string, std::unique_ptr<Shape>(*)(std::istringstream&)> factoryMap;
    factoryMap.insert(std::make_pair(std::string("circle"), &makeCircle));
    factoryMap.insert(std::make_pair(std::string("square"), &makeSquare));
    factoryMap.insert(std::make_pair(std::string("rectangle"), &makeRectangle));

    std::string line;
    double totalArea = 0.0;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string shapeType;
        ss >> shapeType;
        auto it = factoryMap.find(shapeType);
        if (it != factoryMap.end()) {
            std::unique_ptr<Shape> shape = (it->second)(ss);
            totalArea += shape->area();
        }
        else {
            std::cerr << "Unknown shape: " << shapeType << "\n";
        }
    }

    std::cout << "Total area of shapes: " << totalArea << "\n";
    return 0;
}
