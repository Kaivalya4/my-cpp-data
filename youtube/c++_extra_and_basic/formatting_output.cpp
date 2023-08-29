#include<iostream>
#include<iomanip> //required

using namespace std;

int main()
{
     //setw sets width of the field
    cout << setw(6) << "R" ;   //_ _ _ _ _ R
    cout << endl;

   // it does not stick with one cout statement with another
    cout << "R" ; // it will not shift
    cout << endl;
    
    //More precisely we can say it sticks with cout until we output something
    cout << setw(8);
    cout << endl ;
    cout << endl;
    cout<< "R";
    cout << endl << setw(5) <<123.456; //an entity acquiring 7 place . it will no work
    cout << endl << setw(8) << 123.456;

    //setprecision set total number of sigits to be displayed when floating point numbers are printed
    cout << endl << setprecision(5) << 123.456; // it rounds of the output value
    cout << endl << setprecision(5) << endl;   // it will work untill the float number is not encountered
    cout << "hello";
    cout << 123.456; 
    cout << endl;

    //to set number of decimal places we can use - fixed
    cout.setf(ios::fixed);
    cout<<setprecision(5) << 123.45677999 << endl ; 
    cout<< fixed;   //we can directly use fixed
    cout<<setprecision(5) << 123.45677999 << endl;

    //some other ios flags - 
    cout <<left<< setw(20)<< 123.45677999;


    return 0;
}