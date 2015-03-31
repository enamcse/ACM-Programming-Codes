//#include <cstdlib>   // Include rand()
//
//using namespace std; // Make rand() visible
//
//int a = rand(); // rand is a standard function that all compilers have


//return-type function_name ( arg_type arg1, ..., arg_type argN );


//int mult ( int x, int y );


#include <iostream>

using namespace std;

int mult ( int x, int y );

int main()
{
    int x;
    int y;

    cout<<"Please input two numbers to be multiplied: ";
    cin>> x >> y;
    cin.ignore();
    cout<<"The product of your two numbers is "<< mult ( x, y ) <<"\n";
    cin.get();
}

int mult ( int x, int y )
{
    return x * y;
}
