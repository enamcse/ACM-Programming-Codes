#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a,b,swel;
    FILE *file, *file2;
    bool done=false;
    cout<<"Assalamualaikum wa Rahmatullah."<<endl;
    cout<<"Select mode:\n1 - Finding mood\n2 - Adding mode\n";
    cin>>swel;
    switch (swel)
    {
    case 1:
        file2 = fopen("C:\\Users\\Enampur\\Desktop\\work for UVa.txt", "a+");
        fprintf(file2,"%s\n","THE FOLLOWING PROMBELM(S) AIN'T DONE IN UVa:");
        cout<<"UVa problem number (-1 for exit): ";
        cin>>a;
        while(a!=-1)
        {
            done = false;
            file = fopen("UVa.txt", "r+");
            while(!feof(file))
            {
                fscanf(file," %d", &b);
                if(a==b)
                {
                    done = true;
                    break;
                }
            }
            fclose(file);
            if(done==true) cout<<"\nCongratulations! You have already done this problem.\nThe Problem number was: "<<a<<"\nThanks\n";
            else
            {
                cout<<"\nSorry! You have not done this problem yet.\nPlease do the problem and add in the list.\nThanks.\n";
                fprintf(file2,"%d\n",a);
            }
            cout<<"UVa problem number (-1 for exit): ";
            cin>>a;
        }
        break;

    case 2:
        file = fopen("UVa.txt", "a+");
        cout<<"UVa problem number to add (-1 for exit): ";
        cin>>a;
        while(a!=-1)
        {
            fprintf(file," %d", a);
            cout<<"\nCongratulations! UVa Problem number: "<<a<<" successfully added in data set\nThanks\n";
            cout<<"UVa problem number (-1 for exit): ";
            cin>>a;
        }
        fclose(file);
        cout<<"Allah Hafiz"<<endl;
        break;
    }
}

