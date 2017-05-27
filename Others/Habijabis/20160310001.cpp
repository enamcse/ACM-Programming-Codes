/**
* E:\Dropbox\Code\Others\Habijabis\20160310001.cpp
* Created on: 2016-03-10-07.07.09, Thursday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

    #include <bits/stdc++.h>
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);

    #define sz 10000005

    using namespace std;

    int arr[sz];

    int main()
    {
        _
        int cas = 1,t,n,m,x,y,z;
        n = 45;
        m = 37;
        FILE *file = fopen("test1.txt", "w");

        for (int i = 0; i<sz; i++)
        {
            n = 2*n - m + 1;
            m = -n;
            arr[i] = n+m;
        }


        clock_t begin, end;
        double time_spent;
        begin = clock();

        for(int i = 0; i<sz; i++)
            fprintf(file, "%d\n", arr[i]);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        cerr<<"Normal for loop Time spent = "<<time_spent<<endl;

        fclose(file);


        file = fopen("test2.txt", "w");


        begin = clock();

        for(int i :arr)
            fprintf(file, "%d\n", i);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        cerr<<"Enhanced for loop Time spent = "<<time_spent<<endl;

        fclose(file);

        file = fopen("test3.txt", "w");

        begin = clock();

        for(int &i :arr)
            fprintf(file, "%d\n", i);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        cerr<<"Enhanced for loop using address Time spent = "<<time_spent<<endl;

        fclose(file);

       return 0;
    }
