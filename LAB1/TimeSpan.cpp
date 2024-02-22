#include<iostream>
#include "TimeSpan.h"
#include<cmath>
using namespace std;

//default setting 
 TimeSpan::TimeSpan()
 {
     this->set(0, 0, 0);
 }

//Sets various parameters and chooses it depending on input   
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
 this->set(hours, minutes, seconds);
}
TimeSpan::TimeSpan(double minutes, double seconds)
{
 this->set(0, minutes, seconds);
}
TimeSpan::TimeSpan(double seconds)
{
 this->set(0, 0, seconds);
}

//Initializes the value 
int TimeSpan::getHours() const
{
    return hours;
}
int TimeSpan::getMinutes() const
{
    return minutes;
}
int TimeSpan::getSeconds() const
{
   return seconds;
}


//Set function: calculates the time
void TimeSpan::set(double hours, double minutes, double seconds)
{
    int sum= ((hours)*3600)+((minutes)*60)+round(seconds);
    this->hours = (sum/3600);
    this->minutes = ((sum%3600)/60);
    this->seconds = ((sum%3600)%60);
}

//Boolean function returns true/false 
bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
    this-> hours = hours;
    this-> minutes = minutes;
    this-> seconds = seconds;
    return true;
}


//operators(+/-) tells if the different objects needs to be added or subtracted
TimeSpan TimeSpan:: operator+(const TimeSpan &time) const
{
   int h = this->hours + time.hours;
   int m = this->minutes + time.minutes;
   int s = this->seconds + time.seconds;
   return TimeSpan(h,m,s);
}

TimeSpan TimeSpan:: operator-() const
{
   int h= -(this->hours);
   int m = -(this->minutes);
   int s= -(this->seconds);
   return TimeSpan(h, m, s);
}

TimeSpan TimeSpan:: operator-(const TimeSpan &time) const
{
   int h = this->hours - time.hours;
   int m = this->minutes - time.minutes;
   int s = this->seconds - time.seconds;
   return TimeSpan(h,m,s);
}

//operators(+=/-=)
TimeSpan& TimeSpan::operator-=(const TimeSpan &time)
{
  this->hours-=time.hours;
  this->minutes-=time.minutes;
  this->seconds-=time.seconds;
  return *this ;
}
TimeSpan& TimeSpan::operator+=(const TimeSpan &time)
{
 this->hours+=time.hours;
 this->minutes+=time.minutes;
 this->seconds+=time.seconds;
 return *this;
}

//operators(!=/==) compares the value of two given object values and return true/false
bool TimeSpan::operator!=(const TimeSpan &time)const
{
 return ( this->hours != time.hours || this->minutes != time.minutes || this->seconds != time.seconds ) ;
}

bool TimeSpan::operator==(const TimeSpan &time)const
{
 return ( this->hours == time.hours && this->minutes == time.minutes && this->seconds == time.seconds ) ;
}

//outputs the following result 
ostream& operator<<(ostream &outputstream, const TimeSpan &time)
{
 outputstream <<"Hours: "<<time.getHours()<<" Minutes: "<<time.getMinutes()<<" Seconds: "<<time.getSeconds();
 return outputstream;
}

//Gets time input from the user
istream& operator>>(istream &inputstream, TimeSpan &time)
{
    double hours, minutes, seconds;
    cout << "\nEnter Hours :  ";
    inputstream >> hours;
    cout << "\nEnter Minutes :  ";
    inputstream >> minutes;
    cout << "\nEnter Seconds :  ";
    inputstream >> seconds;
    time.set(hours, minutes, seconds);
    return inputstream;
}
