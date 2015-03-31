//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

struct person
{
    char name[15];
    int buy, sell;
    person(char line[])
    {
        strcpy(name, line);
        buy=sell=0;
    }
};

struct commodity
{
    char name[5];
    int n, sum, mn, mx;
    commodity(char line[])
    {
        sum = n = 0;
        mn = inf;
        mx = -inf;
        strcpy(name,line );
    }
};

struct product
{
    char name[15];
    char prod[5];
    int price;
    int cnt;

    product(char line1[], char line2[], int p, int c)
    {
        strcpy(name, line1);
        strcpy(prod, line2);
        price = p;
        cnt = c;
    }
};


vector<person>per;
vector<commodity>thing;
vector<product>buys, sells;

bool compbuy(const product &a, const product &b)
{
    if(a.price==b.price) return a.cnt<b.cnt;
    return a.price>b.price;
}
bool compsell(const product &a, const product &b)
{
    if(a.price==b.price) return a.cnt<b.cnt;
    return a.price<b.price;
}

bool printCompThing(const commodity &a, const commodity &b)
{
    return strcmp(a.name,b.name)<0;
}

bool printCompPerson(const person &a, const person &b)
{
    return strcmp(a.name,b.name)<0;
}

void printall()
{
    sort(thing.begin(), thing.end(), printCompThing);
    for (int i = 0; i<thing.size(); i++)
        printf("%s %d %d %d\n", thing[i].name, thing[i].mn, thing[i].sum/thing[i].n, thing[i].mx);
    puts("--");

    sort(per.begin(), per.end(), printCompPerson);
    for (int i = 0; i<per.size(); i++)
        printf("%s %d %d\n", per[i].name, per[i].buy, per[i].sell);
    puts("----------");

    return;
}

void printBuyList()
{
    cout<<"Buy ---------------"<<endl;
    for (int i = 0; i<buys.size(); i++)
        cout<<"N: "<<buys[i].name<<" Prod: "<<buys[i].prod<<" Price: "<<buys[i].price<<" cnt: "<<buys[i].cnt<<endl;
    cout<<"-------------------"<<endl;
    return;
}

void printSellList()
{
    cout<<"Sell---------------"<<endl;
    for (int i = 0; i<sells.size(); i++)
        cout<<"N: "<<sells[i].name<<" Prod: "<<sells[i].prod<<" Price: "<<sells[i].price<<" cnt: "<<sells[i].cnt<<endl;
    cout<<"-------------------"<<endl;
    return;
}




int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n, m, cas=1, price, x,y, dealprice;
    char name[20], type[10], com[5];


    while(~scanf("%d", &n)&&n)
    {
        per.clear();
        thing.clear();
        buys.clear();
        sells.clear();

        for (int i = 0; i<n; i++)
        {
//            printBuyList();
//            printSellList();
            scanf(" %s %s %s %d", name, type, com, &price);
            int j;
            for (j = 0; j<per.size(); j++)
                if(!strcmp(per[j].name, name)) break;

            if(j==per.size()) per.pb(person(name));

//            printf("::>> %s %s %s %d\n", name, type, com, price);

            if(!strcmp(type, "SELL"))
            {
                if(!buys.empty())
                {
                    sort(buys.begin(), buys.end(), compbuy);
                    for (j = 0; j<buys.size(); j++)
                    {
                        if(strcmp(buys[j].name, name) && !strcmp(com,buys[j].prod) && price<= buys[j].price)
                        {
                            dealprice = (price+buys[j].price)/2;

                            int ii;
                            //selling person update
                            for (ii = 0; ii<per.size(); ii++ )
                                if(!strcmp(per[ii].name, name)) break;
                            per[ii].sell+=dealprice;

                            //buying person update
                            for (ii = 0; ii<per.size(); ii++ )
                                if(!strcmp(per[ii].name, buys[j].name)) break;
                            per[ii].buy+=dealprice;

                            //commodity update
                            for (ii = 0; ii<thing.size(); ii++ )
                                if(!strcmp(thing[ii].name, com)) break;

                            if(ii==thing.size()) thing.pb(commodity(com));

                            thing[ii].n++;
                            thing[ii].sum+=dealprice;
                            thing[ii].mn = min(thing[ii].mn, dealprice);
                            thing[ii].mx = max(thing[ii].mx, dealprice);

                            break;
                        }
                    }

                    if(j==buys.size()) sells.pb(product(name,com, price,i));
                    else buys.erase(buys.begin()+j);
                }
                else sells.pb(product(name,com, price,i));
            }
            else
            {
//                printf(":->%s %s %s %d\n", name, type, com, price);
                if(!sells.empty())
                {
                    sort(sells.begin(), sells.end(), compsell);
                    int j;
                    for (j = 0; j<sells.size(); j++)
                    {
                        if(strcmp(sells[j].name, name) && !strcmp(com,sells[j].prod) && sells[j].price <= price)
                        {
                            dealprice = (price+sells[j].price)/2;

                            int ii;
                            //buying person update
                            for (ii = 0; ii<per.size(); ii++ )
                                if(!strcmp(per[ii].name, name)) break;
                            per[ii].buy+=dealprice;

                            //selling person update
                            for (ii = 0; ii<per.size(); ii++ )
                                if(!strcmp(per[ii].name, sells[j].name)) break;
                            per[ii].sell+=dealprice;

                            //commodity update
                            for (ii = 0; ii<thing.size(); ii++ )
                                if(!strcmp(thing[ii].name, com)) break;

                            if(ii==thing.size()) thing.pb(commodity(com));

                            thing[ii].n++;
                            thing[ii].sum+=dealprice;
                            thing[ii].mn = min(thing[ii].mn, dealprice);
                            thing[ii].mx = max(thing[ii].mx, dealprice);

                            break;
                        }
                    }

                    if(j==sells.size()) buys.pb(product(name,com, price,i));
                    else sells.erase(sells.begin()+j);
                }
                else buys.pb(product(name,com, price,i));
            }
        }
        printall();
    }
    return 0;
}

/*
3
PERLIS SELL A 300
MILKES BUY A 200
HAMMING SELL A 100
4
BACKUS SELL A 10
FLOYD BUY A 20
IVERSON SELL B 30
BACKUS BUY B 40
7
MILKINSON SELL A 500
MCCARTHY BUY C 300
MILKINSON SELL C 200
DIJKSTRA SELL B 100
BACHMAN BUY A 400
DIJKSTRA BUY A 600
MILKINSON SELL A 300
2
ABCD SELL X 10
ABC BUY X 15
2
A SELL M 100
A BUY M 100
0
*/
