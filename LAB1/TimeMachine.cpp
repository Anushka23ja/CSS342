#include <iostream>
#include "TimeSpan.h"

using namespace std;

int main() {

    //Setting objects
    cout<<"=== Objects i.e constructor initializations: ==="<<endl;
    TimeSpan objone;
    TimeSpan objtwo(2.9, 3.4, 1);
    TimeSpan objthree(8.7,7,6);
    TimeSpan objfour(2.3,9,3);
    TimeSpan objfive(1,3);

    //Outputs all the calculated times 
    cout << "("<<objone<<")"<<endl; //time the user set
    cout << "("<<objtwo<<")"<<endl;
    cout << "("<<objthree<<")"<<endl;
    cout << "("<<objfour<<")"<<endl;
    cout << "("<<objfive<<")"<< endl;

    //Gets time input from user and save it as objone
    cout<<endl;
    cout<<"=== Istream /Ostream test: ==="<<endl;
    cout << "Input time: " <<endl;
    cin >> objone;
    cout << objone<< endl;

    //Unary operators applied to all the times
    cout<<endl;
    cout<<"=== Unary Operator Testing: ==="<<endl;
    cout << "Before negation" << objtwo;
    cout << "After negation" << -objtwo << endl;

    //call the setTimefunction and resets the value to use operators next
    cout<<endl;
    cout<<"=== Testing Set Time Function: ==="<<endl;
    objthree.setTime(2,5,2);
    cout <<"Object three value: "<<objthree<<endl;

    //Compares the objects using the (!=,==) operators 
    cout<<endl;
    cout<<"=== Testing (!=,==) Operators: ==="<<endl;

    TimeSpan objcomp(2,5,2);
    if(objcomp == objthree)
    {
       cout << "The times "<<objcomp<<" && "<<objthree<<" are SAME!"<<endl;
    }
    else
    {
       cout << "The times "<<objcomp<<" && "<<objthree<<" are NOT SAME!"<<endl;
    }

    if(objcomp != objtwo)
    {
        cout << "The times "<<objcomp<<" && "<<objtwo<<" are NOT THE SAME!"<<endl;
    }
    else
    {
        cout << "The times "<<objcomp<<" && "<<objtwo<<" are  SAME!"<<endl;
    }

    //testing main operators (+,+=,-,-=)
    cout<<endl;
    cout<<"=== Testing for Operator Overloading (+,-,+=,-=): ==="<<endl;
    cout << "Addition :" << (objone) << " and " << (objthree) <<" is " << endl << '\t'<<(objone + objthree)<< endl;
    cout << "Substraction: " <<(objone) << " and " << (objtwo) << " is " << endl << '\t'<<(objone - objtwo)<< endl;
    cout << "Operator (+=): " << objone << " and " << objtwo   << " is " <<endl << '\t' <<(objone += objtwo)<< endl;
    cout << "Operator (-=): " <<objfour << " and " <<objfive <<" is " << endl << '\t' <<(objfour -= objfive)<< endl;
    
    return 0;
}
