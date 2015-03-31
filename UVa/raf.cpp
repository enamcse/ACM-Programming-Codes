#include <iostream>

using namespace std;

bool leapyear_check(int yy);

int main()
{
    string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_no,t,caseno=1, leap_day,y;
    string month_beg, month_end;
    int date_beg, date_end;
    int year_beg, year_end;
    char c;
    cin>>t;

    while(t--)
    {
        leap_day = 0;
        cin>>month_beg>>date_beg>>c>>year_beg;
        cin>>month_end>>date_end>>c>>year_end;
        y = year_beg;
        if(month_beg==month[0] || month_beg==month[1])
        {
            if(leapyear_check(y)==true)
            {
                leap_day++;
                y++;
            }
            else y++;
        }
        else y++;

        while(y<year_end)
        {
            if(leapyear_check(y)==true)
            {
                leap_day++;
                y+=4;
            }
            else y++;
        }

        if(leapyear_check(y)==true && y==year_end && month_end!=month[0])
        {
            if(month_end!=month[1]) leap_day++;
            else if (month_end==month[1] && date_end == 29) leap_day++;
        }
        cout<<"Case "<<caseno++<<": "<<leap_day<<endl;
    }
    return 0;
}

bool leapyear_check(int yy)
{
    if(yy%4==0&&yy%400==0) return true;
    else if (yy%100==0) return false;
    else if(yy%4==0) return true;
    else return false;
}
