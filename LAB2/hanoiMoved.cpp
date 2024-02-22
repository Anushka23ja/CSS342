//Tower of Hanoi
//Author: Anushka Chougule
#include<iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void hanoiMoves(int n, string from, string to, string extra, int &counter){

//stops and returns when there is no numbers remaining 
if( n == 0){
   return;
 }
hanoiMoves(n - 1, from, extra, to, counter);
cout<<"\t Move disk "<< n <<" from " << from << " to "<< to <<endl ;
hanoiMoves(n - 1, extra, to, from, counter);
counter++; 
}


int main()
{
    int counter = 0;


    auto starttime = high_resolution_clock::now();
    
    hanoiMoves(3, "A", "C", "B", counter);

    //Demonstrate using n from 1 to 15 that the number of moves is 2^n
    //Turn off print (turned this part into comment so it can be testest seperately)
    
    /* 
    for(int num =1; num <=15; num++)
     {
       hanoiMoves(num, "A", "C", "B", counter);
       
     }
    */
   
       auto endtime = high_resolution_clock::now();
       auto elapsed_time = duration_cast<microseconds>(endtime - starttime).count();
       cout << "\nTotal moves: " << counter << endl;
       cout<<"Duration Time: "<< elapsed_time<<" Microsecond" ;    
   
    return 0;
}