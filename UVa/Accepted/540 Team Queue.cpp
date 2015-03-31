#include <iostream>
#include <string>
#include <stdio.h>
#define sz 1000

int queue[sz][sz],q[sz], team[sz], team_q[sz], teammates[sz][sz];

using namespace std;

int main()
{
    int i,j,n,t, num, team_i, caseno=1, front, rear;
    bool flag;
    string enq = "ENQUEUE", deq = "DEQUEUE", input;
    cin>>n;
    while(n)
    {
        for (i=0; i<n; i++)
        {
            cin>>team[i];
            for (j=0; j<team[i]; j++)
                cin>>teammates[i][j];
        }
        cin>>input;
        rear=front=0;
        cout<<"Scenario #"<<caseno++<<endl;
        while(input!="STOP")
        {
            if(input==enq)
            {
                cin>>num;
                flag = false;
                for (i=0; i<n; i++)
                {
                    for (j=0; j<team[i]; j++)
                    {
                        if(num==teammates[i][j])
                        {
                            team_i = i;
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(rear==0)
                {
                    team_q[0] = team_i;
                    q[rear++] = 1;
                    queue[0][0] = num;
                }
                else
                {
                    flag = false;
                    if(rear>=front)
                    {
                        for (i=front; i<rear; i++)
                        {
                            if(team_q[i]==team_i)
                            {
                                flag=true;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (i=front; i<1000; i++)
                        {
                            if(team_q[i]==team_i)
                            {
                                flag=true;
                                break;
                            }
                        }
                        if(!flag)
                        {
                            for (i=0; i<rear; i++)
                            {
                                if(team_q[i]==team_i)
                                {
                                    flag=true;
                                    break;
                                }
                            }
                        }
                    }


                    if(flag)
                    {
                        j = q[i]++;
                        queue[i][j] = num;
                    }
                    else
                    {
                        team_q[rear] = team_i;
                        q[rear] = 1;
                        queue[rear++][0] = num;
                        rear%=1000;
                    }
                }
            }
            else if(input==deq)
            {
                cout<<queue[front][0]<<endl;
                for (j=1; j<q[front]; j++)
                {
                    queue[front][j-1] = queue[front][j];
                }
                q[front]--;
                if(q[front]==0)
                {
                    team_q[front++] = -5;
                    front%=1000;
                }
            }
            cin>>input;
        }
        cout<<endl;
        cin>>n;
    }


    return 0;
}
/*#define check for (i=0; i<rear; i++)\
                {\
                    for (j=0; j<q[i]; j++)\
                        cout<<queue[i][j]<<" ";\
                    cout<<endl;\
                }\

#define checks(a) for (i=0; i<rear; i++)\
                {cout<<a<<endl;cout<<i<<":"<<team_q[i]<<" ";cout<<endl;}*/
