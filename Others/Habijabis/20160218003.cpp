/**
* E:\Dropbox\Code\Others\Habijabis\20160218003.cpp
* Created on: 2016-02-19-23.11.09, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

    #include <bits/stdc++.h>
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);

    using namespace std;

    int main()
    {
        int n = 10;
        unsigned m = 10;
    //    clock_t begin, end;
    //    double time_spent;
    //    begin = clock();

        bitset<32> now(n);
        cout<<"n        = "<<now.to_string()<<" = "<<n<<endl;
        bitset<32> now0(~n);
        cout<<"~n       = "<<now0.to_string()<<" = "<<~n<<endl;
        bitset<32> now1(-n);
        cout<<"-n       = "<<now1.to_string()<<" = "<<-n<<endl;
        bitset<32> now2(~(-n)+1);
        cout<<"~(-n)+1  = "<<now2.to_string()<<" = "<<~(-n)+1<<endl;

        bitset<32> now3(m);
        cout<<"m        = "<<now3.to_string()<<" = "<<m<<endl;
        bitset<32> now4(~m);
        cout<<"~m       = "<<now4.to_string()<<" = "<<~m<<endl;

    //    end = clock();
    //    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //    cerr<<"Time spent = "<<time_spent<<endl;

       return 0;
    }
