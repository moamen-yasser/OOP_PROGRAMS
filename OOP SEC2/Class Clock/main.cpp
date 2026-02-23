/*
Create a class called Clock that contains three variables:
- Hour
- Minute
- Second

The class should include two functions:
1. A function to input the values of the variables and validate the allowed ranges.
2. A function to display the time in digital clock format.

Then create a main program that:
- Creates objects from the Clock class.
- Uses the class functions with each object.
*/

#include <iostream>

using namespace std;

class Clock {
private:
    int h, m;
    float s;
public:
    void setTime(int a, int b, float c){
        h = (a >= 0 && a <= 23) ? a : 0;
        m = (b >= 0 && b <= 59) ? b : 0;
        s = (c >= 0 && c <= 59) ? c : 0;
    };

    void printTime(){
        cout << h << ":" << m << ":" << s << endl;
    }
};

int main()
{
    Clock c1, c2, c3;

    cout<<"Clock One \n";
    c1.setTime(10, 30, 45.5);
    c1.printTime();

    cout<<"\nClock Two \n";
    c2.printTime();

    cout<<"\nClock Three \n";
    c3.setTime(100,5,-15);
    c3.printTime();

    cout<<"\nArray of Clocks\n";

    Clock clocks[3];

    for(int i = 0; i < 3; i++){
        int h, m;
        float s;

        cout << "Enter time for Clock " << i + 1 << endl;

        cout << "Hour: ";
        cin >> h;

        cout << "Minute: ";
        cin >> m;

        cout << "Second: ";
        cin >> s;

        clocks[i].setTime(h, m, s);
        cout << endl;
    }

    cout << "Digital Clock Times\n";

    for(int i = 0; i < 3; i++){
        cout << "Clock " << i + 1 << ": ";
        clocks[i].printTime();
    }

    return 0;
}
