#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<sstream>
using namespace std;

string formatNumber(double value) {
    ostringstream oss;
    oss << fixed << setprecision(4) << value;
    string str = oss.str();

    // remove trailing zeros
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    // remove trailing decimal point if all decimals were zero
    if (!str.empty() && str.back() == '.') {
        str.pop_back();
    }
    return str;
}

void toLower(string& input) {
    for(int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
}

class Shape {
    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
};

class Circle: public Shape {
    double radius;
    public:
        Circle(double r): radius(r) {}

        double area() {
            return M_PI*radius*radius;
        }

        double perimeter() {
            return 2*M_PI*radius;
        }
};

class Rectangle: public Shape {
    double length, breadth;

    public:
        Rectangle(double l, double b): length(l), breadth(b) {}

        double area() {
            return length*breadth;
        }
        
        double perimeter() {
            return 2*(length+breadth);
        }
};

class Triangle: public Shape {
    double side1, side2, side3;

    public:
        Triangle(double a, double b, double c): side1(a), side2(b), side3(c) {}

        double perimeter() {
            return side1+side2+side3;
        }

        double area() {
            double semi_per = perimeter()/2;
            return sqrt(semi_per*(semi_per-side1)*(semi_per-side2)*(semi_per-side3));
        }
};

int main() {
    string shape;
    double perimeter, area;
    cout << fixed << setprecision(4);
    cout << "What shape do you want: ";
    cin >> shape;
    toLower(shape);
    Shape* obj;

    if(shape == "circle") {
        double radius;
        cout << "Enter the radius: ";
        cin >> radius;
        obj = new Circle(radius);
        perimeter = obj->perimeter();
        area = obj->area();
    } else if(shape == "rectangle") {
        double length, breadth;
        cout << "Enter the length and breadth: ";
        cin >> length >> breadth;
        obj = new Rectangle(length, breadth);
        perimeter = obj->perimeter();
        area = obj->area();
    } else if (shape == "triangle") {
        double a, b, c;
        cout << "Enter the three sides: ";
        cin >> a >> b >> c;
        obj = new Triangle(a, b, c);
        perimeter = obj->perimeter();
        area = obj->area();
    } else {
        cout << "Wrong shape." << endl;
        return 0;
    }
    
    cout << "Perimeter = " << formatNumber(perimeter) << endl;
    cout << "Area = " << formatNumber(area) << endl;

    return 0;
}