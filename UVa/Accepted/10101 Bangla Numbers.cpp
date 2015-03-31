#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define sz 100
using namespace std;

int main()
{
    int i, j, len, k, n, caseno=1;
    long long int test;
    char line[sz], shobdo[][20] = {"kuti", "lakh","hajar", "shata" }, now[sz];
    while(cin>>line)
    {
        len = strlen(line);
        printf("%4d.", caseno++);
//        cout<<"   "<<caseno++<<".";
        j = 0;
        k = 0;
        switch(len)
        {
        case 16:
            now[k++] = line[j++];
        case 15:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n<<" "<<shobdo[0];
            k = 0;
        case 14:
            now[k++] = line[j++];
        case 13:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n<<" "<<shobdo[1];
            k = 0;
        case 12:
            now[k++] = line[j++];
        case 11:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n<<" "<<shobdo[2];
            k = 0;
        case 10:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n<<" "<<shobdo[3];
            k = 0;
        case 9:
            now[k++] = line[j++];
        case 8:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n;
            cout<<" "<<shobdo[0];
            k = 0;
        case 7:
            now[k++] = line[j++];
        case 6:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n<<" "<<shobdo[1];
            k = 0;
        case 5:
            now[k++] = line[j++];
        case 4:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n<<" "<<shobdo[2];
            k = 0;
        case 3:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n<<" "<<shobdo[3];
            k = 0;
        case 2:
            now[k++] = line[j++];
        case 1:
            now[k++] = line[j++];
            now[k] = '\0';
            n = atoi(now);
            if(n) cout<<" "<<n;
            break;

        }
        test = atol(line);
        if(!test) cout<<" "<<0;
        cout<<endl;
    }

    return 0;
}
