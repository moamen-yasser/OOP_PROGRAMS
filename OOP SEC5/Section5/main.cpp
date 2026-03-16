#include <iostream>
using namespace std;

class Date
{
private:
    int d, m, y;
    void adjust();

public:
    Date();                 // Constructor
    Date(int, int, int);    // Constructor with parameters
    ~Date();                // Destructor

    void showDate();
    void addDate(int, int, int);
    void addDate(Date);
    void subDate(int, int, int);
    void subDate(Date);
};

//---------------------------------

void Date::adjust()
{
    while (d < 1) { d += 30; m--; }
    while (d > 30) { d -= 30; m++; }

    while (m < 1) { m += 12; y--; }
    while (m > 12) { m -= 12; y++; }

    if (y < 2025) y = 2025;
}

//---------------------------------

Date::Date()
{
    d = m = 1;
    y = 2025;
}

Date::Date(int id, int im, int iy)
{
    d = id;
    m = im;
    y = iy;
    adjust();
}

Date::~Date()
{
    cout << "Date object destroyed" << endl;
}

//---------------------------------

void Date::showDate()
{
    cout << y << "\\" << m << "\\" << d << endl;
}

//---------------------------------

void Date::addDate(int day, int month, int year)
{
    d += day;
    m += month;
    y += year;
    adjust();
}

void Date::addDate(Date date)
{
    d += date.d;
    m += date.m;
    y += date.y;
    adjust();
}

//---------------------------------

void Date::subDate(int sd, int sm, int sy)
{
    d -= sd;
    m -= sm;
    y -= sy;
    adjust();
}

void Date::subDate(Date date)
{
    d -= date.d;
    m -= date.m;
    y -= date.y;
    adjust();
}

//---------------------------------

int main()
{
    Date d1;
    Date d2(10, 5, 2026);

    d1.showDate();  //1-1-2025
    d2.showDate();  //10-5-2026

    d1.addDate(5, 2, 0);
    d1.showDate();  //6-3-2025

    d2.subDate(3, 1, 0);
    d2.showDate();  //7-4-2026

    d1.addDate(d2);
    d1.showDate();  //13-7-4051

    return 0;
}
