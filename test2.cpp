#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>numbers = {4,5,3,2,5,42};
    cout<<"-------------------\n";
    for (auto x : numbers){
        cout<< &x <<endl;
        x+=10;
    }

    cout<<"-------------------\n";
    for (vector<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){
        cout<< &(*it) <<" "<< *it << endl;
    }

    return 0;
}
