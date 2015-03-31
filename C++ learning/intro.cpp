//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//  cout<<"HEY, you, I'm alive! Oh, and Hello World!\n";
//  cin.get();
//}


//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//  cout<<"HEY, you, I'm alive! Oh, and Hello World!\n";
//  cin.get();
//
//  return 1;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int x;
//    char letter;
//    float the_float;
//    int a, b, c, d;
//
//    return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int thisisanumber;
//
//    cout<<"Please enter a number: ";
//    cin>> thisisanumber;
//    cin.ignore();
//    cout<<"You entered: "<< thisisanumber <<"\n";
//    cin.get();
//}



#include <iostream>

using namespace std;

int main()
{
    int x;
    char letter;
    float the_float;
    int a, b, c, d;

    a = 4 * 6; // (Note use of comments and of semicolon) a is 24
    a = a + 5; // a equals the original value of a with five added to it
    a == 5;     // Does NOT assign five to a. Rather, it checks to see if a equals 5.


    a < 5;  // Checks to see if a is less than five
    a > 5;  // Checks to see if a is greater than five
    a == 5; // Checks to see if a equals five, for good measure
    if ( 5 < 10 )
        cout<<"Five is now less than ten, that's a big surprise";

    cout<<"Please enter a number: ";
    cin>> b;
    cin.ignore();
    cout<<"You entered: "<< a+b <<"\n";
    cin.get();
}
