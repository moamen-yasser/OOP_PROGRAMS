#include <iostream>
#include <conio.h>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point() {
		x = y = 0;
	}
	void display()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
	//Prefix
	Point operator ++() {
		++x, ++y;
		Point temp;
		temp.x = x;
		temp.y = y;
		return temp;
	}
	//Postfix
	Point operator ++(int) {
		Point temp;
		temp.x = x;
		temp.y = y;
		++x, ++y;
		return temp;
	}
};
int main() {
	Point p1,p2;
	p2 = p1++;
	p2 = p1++;
	p2 = ++p1;
	p2.display(); //(3,3)
	return 0;
}
