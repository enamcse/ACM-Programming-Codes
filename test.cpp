#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    double value, sum;
    double average, minimum=(int)INFINITY, maximum=-(int)INFINITY, median;
    map<int,int>modes;
    vector<int>data;
    int count,mxmode=0;
    // initialise
    sum = 0.0;
    count = 0;
    cout << "Enter a value: ";

    while (cin >> value)
    {
        // process value
        sum += value;
        count++;
        if (value > maximum)
            maximum = value;
        else if (value < minimum)
            minimum = value;

        modes[ value ]++;
        mxmode = max(mxmode, modes[value]);
        data.push_back(value);

        // get next value
        cout << "Enter a value: ";
    }
    if (count == 0)
        cout << "No data entry" << endl;
    else
    {
        average = sum / count;

        sort(data.begin(), data.end());

        if(data.size()%2==0) median = ( data[ data.size()/2 - 1 ] + data[ data.size()/2 ] )/2.0;
        else median = data[ data.size()/2 ];

        cout << "There were " << count << " numbers" << endl;
        cout << "Average was " << average << endl;
        cout << "Minimum was " << minimum << endl;
        cout << "Maximum was " << maximum << endl;
        cout << "Median was " << median << endl;
        cout << "Median was";

        for (auto &x: modes)
            if(x.second == mxmode) cout<<" "<<x.first;

        cout<<" ("<<mxmode<<")" << endl;
    }
}
