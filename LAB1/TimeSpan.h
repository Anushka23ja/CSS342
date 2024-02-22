#include<iostream>
using namespace std;

class TimeSpan{
    private:
    int hours;
    int minutes;
    int seconds;
    void set(double hours, double minutes, double seconds);

    public:
    // initzilazing constructor for all parameters
    TimeSpan(double hours, double minutes, double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double seconds);

    //Default constructor
    TimeSpan();

    //Accessor/Mutator Functions (Getter & Setter)
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool setTime(int hours, int  minutes, int  seconds);

    //(>>and<<)Friend operators   
    friend ostream &operator<<(ostream &outputstream, const TimeSpan &time);
    friend istream &operator>>(istream &inputstream, TimeSpan &time);

    //(+)Arithmetic and Argumentaed operators 
    TimeSpan operator+(const TimeSpan &time)const;
    TimeSpan& operator+=(const TimeSpan &time);

    //Unary operator
    TimeSpan operator-()const;

    //(-)Arithmetic and Argumentaed operators 
    TimeSpan operator-(const TimeSpan &time)const;
    TimeSpan& operator-=(const TimeSpan &time);

    //Sets boolean operators (!=/==)
    bool operator==(const TimeSpan &time)const;
    bool operator!=(const TimeSpan &time)const;
    };
