#include <iostream>
using namespace std;

// ===================== Time Class =====================
class time {
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
    time() {
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

    void setTime(int h, int m, int s) {
        if (h >= 0 && h < 24 &&
            m >= 0 && m < 60 &&
            s >= 0 && s < 60) {
            hour = h;
            minute = m;
            second = s;
        }
    }

    // ===== Getters =====
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    // ===== Show =====
    void showTime24() const {
        cout << hour << ":" << minute << ":" << second << endl;
    }

    void showTime12() const {
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

    // ===== Operations =====
    void addTime(int h, int m, int s) {
        hour += h;
        minute += m;
        second += s;
        normalize();
    }

    void addTime(time t) {
        hour += t.hour;
        minute += t.minute;
        second += t.second;
        normalize();
    }

    void subTime(int h, int m, int s) {
        hour -= h;
        minute -= m;
        second -= s;
        normalize();
    }

    void subTime(time t) {
        hour -= t.hour;
        minute -= t.minute;
        second -= t.second;
        normalize();
    }
};

// ===================== Date Class =====================
class Date {
private:
    int d, m, y;

    void adjust() {
        while (d < 1) { d += 30; m--; }
        while (d > 30) { d -= 30; m++; }

        while (m < 1) { m += 12; y--; }
        while (m > 12) { m -= 12; y++; }

        if (y < 2025) y = 2025;
    }

public:
    // Constructors
    Date() {
        d = m = 1;
        y = 2025;
    }

    Date(int id, int im, int iy) {
        d = id;
        m = im;
        y = iy;
        adjust();
    }

    // Destructor
    ~Date() {
        cout << "Date object destroyed" << endl;
    }

    // Show
    void showDate() {
        cout << y << "\\" << m << "\\" << d << endl;
    }

    // ===== Operations =====
    void addDate(int day, int month, int year) {
        d += day;
        m += month;
        y += year;
        adjust();
    }

    void addDate(Date date) {
        d += date.d;
        m += date.m;
        y += date.y;
        adjust();
    }

    void subDate(int sd, int sm, int sy) {
        d -= sd;
        m -= sm;
        y -= sy;
        adjust();
    }

    void subDate(Date date) {
        d -= date.d;
        m -= date.m;
        y -= date.y;
        adjust();
    }
};

// ===================== DateTime Class =====================
class myDateTime : public Date, public time {
public:
    // Default Constructor
    myDateTime() : Date(), time() {}

    // Constructor with values
    myDateTime(int d, int m, int y, int h, int min, int s)
        : Date(d, m, y) {
        setTime(h, min, s);
    }

    // Show full DateTime
    void showDateTime() {
        showDate();
        showTime24();
    }

    void showDateTime12() {
        showDate();
        showTime12();
    }
};

// ===================== Main =====================
int main() {
    myDateTime dt1;

    cout << "Default DateTime:\n";
    dt1.showDateTime();

    cout << "\nAfter adding:\n";
    dt1.addDate(5, 2, 0);
    dt1.addTime(2, 40, 50);
    dt1.showDateTime();

    cout << "\nCustom DateTime:\n";
    myDateTime dt2(6, 4, 2026, 22, 15, 10);
    dt2.showDateTime();

    cout << "\n12 Hour Format:\n";
    dt2.showDateTime12();

    return 0;
}
