#include <iostream>
#include <cmath>
#define M_PI 3.14

using namespace std;

class Polygon{
protected:
	int mPoint;
	double mLenght;
public:
	Polygon(){}
	Polygon(int point, float length){
		mPoint = point;
		mLenght = length;
	}
	~Polygon(){}
	
	virtual void calcPerimeter(){
		cout << "Perimeter : empty" << endl;
	}
	
	virtual void calcArea(){
		cout << "Area : empty" << endl;
	}
};

class Rectangle : public Polygon{
public:
	Rectangle(){}
	Rectangle(int point, float length) : Polygon(point, length){}
	~Rectangle(){}
	
	void calcPerimeter() override{
		cout << "Perimeter : " << mPoint * mLenght << endl;
	}
	
	void calcArea() override{
		cout << "Area : " << mLenght * mLenght << endl;
	}
};

class Triangle : public Polygon{
public:
	Triangle(){}
	Triangle(int point, float length) : Polygon(point, length){}
	~Triangle(){}
	
	void calcPerimeter() override{
		cout << "Perimeter : " << mPoint * mLenght << endl;
	}
	
	void calcArea() override{
		cout << "Area : " << mLenght * mLenght * sqrt(3) / 4 << endl;
	}
};

class Circle : public Polygon{
public:
	Circle(){}
	Circle(int point, float length) : Polygon(point, length){}
	~Circle(){}
	
	void calcPerimeter() override{
		cout << "Perimeter : " << 2 * mLenght * M_PI << endl;
	}
	
	void calcArea() override{
		cout << "Area : " << mLenght * mLenght * M_PI << endl;
	}
};

int main() {
	Polygon pol;
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);

	cout << "--- Polygon class ---" << endl;
	pol.calcPerimeter();
	pol.calcArea();

	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();

	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();

	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();

	return 0;
}