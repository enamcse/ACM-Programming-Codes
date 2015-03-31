#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    string input, base,a,h_cpp, m_cpp, s_cpp, show;
    char num[10000], h_c[100], m_c[100], s_c[100];
    double cur_speed, d=0, time, hh, mm, ss;
    int h[2],m[2],s[2];

    getline(cin, input);

    base = input.substr(0,8);
    a = input.substr(9);
    strcpy(num, a.c_str());
    cur_speed = atof(num);

    h_cpp = input.substr(0,1);
    strcpy(h_c, h_cpp.c_str());
    h[0] = atoi(h_c);

    m_cpp = input.substr(3,4);
    strcpy(m_c, m_cpp.c_str());
    m[0] = atoi(m_c);

    s_cpp = input.substr(6,7);
    strcpy(s_c, s_cpp.c_str());
    s[0] = atoi(s_c);

    while(getline(cin, input)&&EOF)
    {
        if(input.size()>8)
        {
            base = input.substr(0,9);
            a = input.substr(9);
            strcpy(num, a.c_str());


            h_cpp = input.substr(0,2);
            strcpy(h_c, h_cpp.c_str());
            h[1] = atoi(h_c);

            m_cpp = input.substr(3,2);
            strcpy(m_c, m_cpp.c_str());
            m[1] = atoi(m_c);

            s_cpp = input.substr(6,2);
            strcpy(s_c, s_cpp.c_str());
            s[1] = atoi(s_c);
            hh = (h[1]-h[0]);
            mm = (m[1]-m[0]);
            ss = (s[1]-s[0]);
            time = ( hh + mm/60.0 + ss/3600.0);
            d+= (time*cur_speed);
            cur_speed = atof(num);
            h[0] = h[1];
            m[0] = m[1];
            s[0] = s[1];
        }
        else
        {
            show = input.substr(0,9);
//            cout<< base<< " show = "<<show<<"ii  ";
            h_cpp = input.substr(0,2);
            strcpy(h_c, h_cpp.c_str());
            h[1] = atoi(h_c);

            m_cpp = input.substr(3,2);
            strcpy(m_c, m_cpp.c_str());
            m[1] = atoi(m_c);

            s_cpp = input.substr(6,2);
            strcpy(s_c, s_cpp.c_str());
            s[1] = atoi(s_c);

            hh = (h[1]-h[0]);
            mm = (m[1]-m[0]);
            ss = (s[1]-s[0]);
            time = ( hh + mm/60.0 + ss/3600.0);
            d+= (time*cur_speed);
            h[0] = h[1];
            m[0] = m[1];
            s[0] = s[1];

            cout << setiosflags(ios::fixed) << setprecision(2);
            cout<<show<<" "<<d<<" km"<<endl;
        }
    }
    return 0;
}
