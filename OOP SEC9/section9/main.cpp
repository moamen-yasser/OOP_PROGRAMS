#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    //Constructor
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imaginary = i;
    }

    //Print Function
    void print() {
        if (imaginary >= 0) {
            cout << real << " + i" << imaginary << endl;
        } else {
            cout << real << " - i" << -imaginary << endl;
        }
    }

    // 1. Addition:
    // (a + bi) + (c + di) = (a + c) + (b + d)i
    Complex operator+(Complex c2){
        return Complex(real + c2.real, imaginary + c2.imaginary);
    }

    // 2. Subtraction:
    // (a + bi) - (c + di) = (a - c) + (b - d)i
    Complex operator-(Complex c2){
        return Complex(real - c2.real, imaginary - c2.imaginary);
    };

    // 3. Multiplication:
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    Complex operator*(Complex c2){
        double newReal = (real * c2.real) - (imaginary * c2.imaginary);
        double newImaginary = (real * c2.imaginary) + (imaginary * c2.real);
        return Complex(newReal, newImaginary);
    }

    // 4. Division:
    // (a + bi) / (c + di) = ((ac + bd) + (bc - ad)i) / (c^2 + d^2)
    Complex operator/(Complex c2){
        double denominator = (c2.real * c2.real) + (c2.imaginary * c2.imaginary);

        if (denominator == 0) {
            cout << "Error: Division by zero!" << endl;
            return Complex(0, 0);
        }

        double newReal = (real * c2.real + imaginary * c2.imaginary) / denominator;
        double newImaginary = (imaginary * c2.real - real * c2.imaginary) / denominator;
        return Complex(newReal, newImaginary);
    }

    // 5. Conjugate:
    // (a + bi) = a - bi
    Complex conjugate(){
        return Complex(real, -imaginary);
    }
};

int main() {
    Complex c1(3, 5);
    Complex c2(2, 4);

    Complex c_add = c1 + c2;
    c_add.print();

    Complex c_sub = c1 - c2;
    c_sub.print();

    Complex c_mul = c1 * c2;
    c_mul.print();

    Complex c_div = c1 / c2;
    c_div.print();

    Complex c_conj = c1.conjugate();
    c_conj.print();

    return 0;
}
