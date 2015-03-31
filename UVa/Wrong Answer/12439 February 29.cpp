#include <iostream>

using namespace std;

bool leapyear_check(int yy);

int main()
{
    string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_no,t,caseno=1, leap_day,y1,y2,y;
    string month_beg, month_end;
    int date_beg, date_end;
    int year_beg, year_end;
    char c;
    bool include_beg, include_end;
    cin>>t;

    while(t--)
    {
        leap_day = 0;

        cin>>month_beg>>date_beg>>c>>year_beg;
        cin>>month_end>>date_end>>c>>year_end;
        y1 = year_beg;
        y2 = year_end;

        if(leapyear_check(y1)==false) while(leapyear_check(y1)!=true&&y<year_end) ++y1;
        else if(leapyear_check(y1)==true && (month_beg==month[0] || month_beg==month[1]))
        {
            y1 = y1;
        }
        else y1+=4;

        if(leapyear_check(y2)==false)
        {
            while(leapyear_check(y2)!=true) --y2;
        }
        else if(leapyear_check(y1)==true && (month_beg==month[0] || month_beg==month[1]))
        {
            y1 = y1;
        }
        else y1+=4;

        if(month_end==month[0] || month_end==month[1])
        {
            if(month_end==month[1] && date_end==29)
        }

        while(leapyear_check(y2)!=true && y2>y1)
        {

            --y2;
        }

        y = y1 - y2;
        y/=4;
        minus = y/25-y/100;

        if()

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
