#include <iostream>
#include <conio.h>
using namespace std;


class Distance{
private:
	int feet;
	int inches;
public:
	Distance() {
		feet = 0;
		inches = 0;
	}
	Distance(int feet, int inches) {
		this->feet = feet;
		this->inches = inches;
	}
	void displayDistance() {
		cout << feet << "|" << inches << endl;
	}
	void operator - () {
		feet = -feet;
		inches = -inches;
	}
};


int main() {
    int x , y , z;
	Distance D1(11, 10), D2(-5, 11), D3;
	-D1;
	D1.displayDistance();
	-D2;
	D2.displayDistance();
	D3.displayDistance();
	return 0;
}
