/**
* E:\Dropbox\Code\Others\Habijabis\20160218002.cpp
* Created on: 2016-02-18-22.31.58, Thursday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

map<string, int>mpp;

int main()
{
	_
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    int uniq=0,dupl=0;
    string line;
    getline(cin,line);

    size_t prev = 0, pos;
    while ((pos = line.find_first_of(" ';.?", prev)) != string::npos)
    {
        if (pos > prev)
            mpp[ line.substr(prev, pos-prev)]++;
        prev = pos+1;
    }
    if (prev < line.length())
        mpp[ line.substr(prev, string::npos)]++;

    for(auto &x: mpp)
    {
        ///cout<<"-> "<<x.first<<" "<<x.second<<endl;
        if(x.second == 1) uniq++;
        else dupl++;
    }

    cout<< "Unique words    = " <<uniq<<"\n";
    cout<< "Duplicate words = " <<dupl<<"\n";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
