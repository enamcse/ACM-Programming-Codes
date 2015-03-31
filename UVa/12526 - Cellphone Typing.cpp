#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>

#define sz 200005
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int sum;
char line[sz][100];

// TRIE starts array
#define trie_sz 26
struct node
{
    int next[trie_sz], cnt;
} data[sz*10];

int counter=0;

void insert_in_trie(char *str, int len)
{
    int n = 0;
    for (int i = 0; i<len; i++)
    {
        int now = str[i]-'a';
        data[n].cnt++;
        if(data[n].next[now]==0)
        {
            data[n].next[now] = ++counter;
            clr(data[counter].next,0);
            data[counter].cnt =0;
        }

        n=data[n].next[now];
    }
    data[n].cnt++;
}

void search_in_trie(char *str, int len)
{
    int n = 0, prev = 0;
    int now = str[0]-'a';
    sum++;
    n=data[n].next[now];

    for (int i = 1; i<len; i++)
    {
        now = str[i]-'a';
        prev = n;

        n=data[n].next[now];
        if(data[n].cnt<data[prev].cnt) sum++;
    }
    return;
}

bool delete_from_trie() // this is for memset only
{
    clr(data[0].next,0);
    counter = 0;
    data[counter].cnt =0;
    sum = 0;
}
// TRIE ends using array




int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif

    int n;

    while(~scanf("%d", &n))
    {
        for (int i = 0; i<n; i++)
        {
            scanf("%s", line[i]);
            insert_in_trie(line[i],strlen(line[i]));
        }

        for (int i = 0; i<n; i++)
        {
            search_in_trie(line[i],strlen(line[i]));
        }

        printf("%.2lf\n", (double)sum/(double)n);
        delete_from_trie();
    }


    return 0;
}


/*

4
hello
hell
heaven
goodbye
3
hi
he
h
7
structure
structures
ride
riders
stress
solstice
ridiculous

*/
