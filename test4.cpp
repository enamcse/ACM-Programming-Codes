#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>

#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("input.txt","w",stdout)
using namespace std;

int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
string months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" ,"December"};

bool isleap(int a)
{
    if (a%400==0||(a%4==0 && a%100!=0))
        return true;
    return false;
}
int d,y;
string s;

int count()
{
    int ret=0;
    if ( y==0)
        ret=0;
    else ret=((y-1)/400)*97;
    for (int i=0;i<=(y-1)%400;i++)
        if (isleap(i))
            ret++;
    if (isleap(y))
    {
        if (!(s=="January" ||(s=="February" && d<29)))
            ret++;
    }
    return ret;
}

bool gao()
{
    if ((s=="February" && d==29))
        return true;
    return false;
}

int main()
{
#ifdef ENAM
     // fread;
    fwrite;
#endif // ENAM
    int test=6;
    cout<<test<<endl;
    // for (int i = 0; i < test; ++i)
    // {
    //     cout<<i+1<<endl;
    // }
    cout<<"10000"<<endl;
    cout<<"11000"<<endl;
    cout<<"11100"<<endl;
    cout<<"11110"<<endl;
    cout<<"11111"<<endl;
    cout<<"21111"<<endl;

    // scanf("%d",&test);
    // int cas=1;
    // while(test--)
    // {

    //     cin>>s;

    //     scanf("%d,%d",&d,&y);
    //     int ans1=count();
    //     bool flag1=gao();
    //     cin>>s;
    //     scanf("%d,%d",&d,&y);
    //     int ans2=count();
    //     bool flag2=gao();
    //     int ans;
    //     if (ans1<ans2)
    //     {
    //         ans=ans2-ans1;
    //         if (flag1)
    //             ans++;
    //     }
    //     else if (ans2<ans1)
    //     {
    //         ans=ans1-ans2;
    //         if (flag2)
    //             ans++;
    //     }
    //     else if (ans2==ans1)
    //     {
    //         ans=0;
    //         if (flag1 || flag2)
    //             ans++;
    //     }
    //     //printf("$$$$$$  %d %d\n",ans1,ans2);
    //     printf("Case %d: %d\n",cas++,ans);
    // }
    return 0;
}
