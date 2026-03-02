/*
Define a class called "myClock",
which has a default value of 6:30,
with members: setHour, setMin, setSec, setClock, showClock12, showClock24, addClock, subClock.
and make the main function to use all members of the class myClock.
*/
/*
Here we apply these topics in OOP:
1- Class.
2- Access Modifiers (private, public).
3- Constructor.
4- Encapsulation (setters, getters).
5- Overloading.
*/

#include <iostream>
using namespace std;

class myClock {
private:
    int hour;
    int minute;
    int second;

    void normalize() {
        if (second >= 60) {
            minute += second / 60;
            second %= 60;
        }
        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        }
        if (hour >= 24)
            hour %= 24;

        if (second < 0) {
            minute--;
            second += 60;
        }
        if (minute < 0) {
            hour--;
            minute += 60;
        }
        if (hour < 0)
            hour += 24;
    }

public:
    // Constructor
    myClock() {
        hour = 6;
        minute = 30;
        second = 0;
    }

    // ===== Setters =====
    void setHour(int h) {
        if (h >= 0 && h < 24)
            hour = h;
    }

    void setMinute(int m) {
        if (m >= 0 && m < 60)
            minute = m;
    }

    void setSecond(int s) {
        if (s >= 0 && s < 60)
            second = s;
    }

    void setClock(int h, int m, int s) {
        if (h >= 0 && h < 24 &&
            m >= 0 && m < 60 &&
            s >= 0 && s < 60) {
            hour = h;
            minute = m;
            second = s;
        }
    }

    // ===== Getters =====
    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    int getSecond() const {
        return second;
    }

    void showClock24() const {
        cout << hour << ":" << minute << ":" << second << endl;
    }

    void showClock12() const {
        int h = hour;
        string period = "AM";

        if (h >= 12) {
            period = "PM";
            if (h > 12)
                h -= 12;
        }
        if (h == 0)
            h = 12;

        cout << h << ":" << minute << ":" << second
             << " " << period << endl;
    }

    void addClock(int h, int m, int s) {
        hour += h;
        minute += m;
        second += s;
        normalize();
    }

    void addClock(myClock clock) {
        hour +=clock.hour;
        minute += clock.minute;
        second += clock.second;
        normalize();
    }

    void subClock(int h, int m, int s) {
        hour -= h;
        minute -= m;
        second -= s;
        normalize();
    }

    void subClock(myClock clock) {
        hour -= clock.hour;
        minute -= clock.minute;
        second -= clock.second;
        normalize();
    }
};

int main() {

    myClock clock1, clock2, clock3, clock4;

    cout << "Default time: ";
    clock1.showClock24(); //6:30:0

    cout << "\nUsing setters:\n";
    clock1.setHour(22);
    clock1.setMinute(45);
    clock1.setSecond(55);
    clock1.showClock24(); //22:45:55

    cout << "\nUsing getters individually:\n";
    cout << "Hour: " << clock1.getHour() << endl;     //22
    cout << "Minute: " << clock1.getMinute() << endl; //45
    cout << "Second: " << clock1.getSecond() << endl; //55

    cout << "\nUsing setClock:\n";
    clock2.setClock(14, 20, 30);
    cout << "24-hour format: ";
    clock2.showClock24(); //14:20:30
    cout << "12-hour format: ";
    clock2.showClock12(); //2:20:30 PM

    cout << "\nAdd time:\n";
    clock2.addClock(10, 50, 40);
    clock2.showClock24(); //1:11:10

    cout << "\nSubtract time:\n";
    clock2.subClock(20, 30, 50);
    clock2.showClock24(); //4:40:20

    cout << "\n12-hour format:\n";
    cout << "Clock One: ";
    clock1.showClock12(); //10:45:55 PM
    cout << "Clock Two: ";
    clock2.showClock12(); //4:40:20 AM

    clock3 = clock1;
    clock3.addClock(clock2);
    clock3.showClock24(); //3:26:15

    clock4 = clock2;
    clock4.subClock(clock1);
    clock4.showClock24(); //5:54:25

    return 0;
}
