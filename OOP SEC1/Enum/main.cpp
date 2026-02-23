// Define an enumeration type quadrilateralType with values
// SQUARE, RECTANGLE, RHOMBUS, TRAPEZIOD, PARALLELOGRAM, QUADRILATERAL, and KITE.
// Also declare the variable quadrilateral of type quadrilateralType while defining this type.

#include <iostream>
using namespace std;

enum quadrilateralType {
    SQUARE,
    RECTANGLE,
    RHOMBUS,
    TRAPEZOID,
    PARALLELOGRAM,
    QUADRILATERAL,
    KITE
};

int main() {
    quadrilateralType quadrilateral = RHOMBUS;

    switch (quadrilateral) {
        case SQUARE:
            cout << "This is a Square." << endl;
            break;

        case RECTANGLE:
            cout << "This is a Rectangle." << endl;
            break;

        case RHOMBUS:
            cout << "This is a Rhombus." << endl;
            break;

        case TRAPEZOID:
            cout << "This is a Trapezoid." << endl;
            break;

        case PARALLELOGRAM:
            cout << "This is a Parallelogram." << endl;
            break;

        case QUADRILATERAL:
            cout << "This is a Quadrilateral." << endl;
            break;

        case KITE:
            cout << "This is a Kite." << endl;
            break;

        default:
            cout << "Unknown type." << endl;
    }

    return 0;
}
