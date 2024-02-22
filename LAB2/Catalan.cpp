//The Catalan Number Problem
//Author: Anushka Chougule
#include<iostream>
using namespace std;

//function created to print catalan numbers 
int catalancalculator(int value){
    if(value <= 1){
        return 1;
    }
    
    int final = 0;

    for(int i = 0; i < value; i++){
        final += catalancalculator(i) * catalancalculator(value - 1 - i);
    }
  
    return final;
}

//executes the function catalancalculator created
int main(int argc, char *argv[]){
 int num = atoi(argv[1]);
 cout<<"Catalan "<<num<<": "<< catalancalculator(num)<<endl;
 return 0;
}

//Developer Notes:
//Value of argc MUST be non-negative && argv is an array of char points to all argc
