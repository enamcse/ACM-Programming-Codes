#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
int arr [MAX];

int main(){

    int t, n;

    cin>>t;

    while(t--){
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }


        for(int i=0;i<n;i++){
            int lst = -1;

            bool inc = 1;
            bool dec = 1;

            for(int j=0;j<n;j++){
                if(i == j) continue;

                if(lst == -1){
                    lst = arr[j];
                    continue;
                }

                if(arr[j] < lst){
                    inc = 0;
                }

                if(arr[j] > lst){
                    dec = 0;
                }


                lst = arr[j];
            }

            if(inc || dec){
                cout<<i+1<<"\n";
                break;
            }
        }
    }

    return 0;
}
