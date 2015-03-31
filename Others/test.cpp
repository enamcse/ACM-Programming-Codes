#include<bits/stdc++.h>
using namespace std;

vector<string>v;


int main()
{
    int n;

//    v.push_back("SUST_Vaporized");
    v.push_back("SUST_@");
    v.push_back("SUST_Silence");
    v.push_back("SUST_C");
    v.push_back("SUST_Curious");
    v.push_back("SUST_Unstable");
    v.push_back("SUST_Dot");
    v.push_back("SUST_NoName");

    n = v.size();
    srand(time(NULL));

    n = rand()%n;

    cout<<v[n];
    return 0;
}
