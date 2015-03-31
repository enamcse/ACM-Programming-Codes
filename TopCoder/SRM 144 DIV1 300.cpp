#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryCode
{
public:
    vector <string> decode(string message)
    {
        char out1[10000], out2[10000], none[] = "NONE";
        string one, two;
        vector<string> output;
        int i=1,j=0;
        bool ot1, ot2;
        ot1 = ot2 = true;
        out1[j++] = '0';
        if(message[0]=='0')
        {
            out1[j++] = '0';
        }
        else if(message[0]=='1')
        {
            out1[j++] = '1';
        }
        else
        {
            strcpy(out1,none);
            ot1 = false;
//            cout<<"dhukse??\n";
        }

        while(ot1)
        {
            if(message[i]=='0' && out1[j-1] =='0' && out1[j-2]=='0') out1[j++] = '0';
            else if(message[i]=='0')
            {
                strcpy(out1,none);
                ot1=false;
                break;
            }
            else if(message[i]=='1' && ((out1[j-1] =='1' && out1[j-2]=='0') || (out1[j-1] =='0' && out1[j-2]=='1'))) out1[j++] = '0';
            else if(message[i]=='1' && out1[j-1] =='0' && out1[j-2]=='0') out1[j++] = '1';
            else if(message[i]=='1')
            {
                strcpy(out1,none);
                ot1=false;
                break;
            }
            else if(message[i]=='2' && ((out1[j-1] =='1' && out1[j-2]=='0') || (out1[j-1] =='0' && out1[j-2]=='1'))) out1[j++] = '1';
            else if(message[i]=='2' && out1[j-1] =='1' && out1[j-2]=='1') out1[j++] = '0';
            else if(message[i]=='2')
            {
                strcpy(out1,none);
                ot1=false;
                break;
            }
            else if(message[i]=='3' && out1[j-1] =='1' && out1[j-2]=='1') out1[j++] = '1';
            else
            {
                strcpy(out1,none);
                ot1=false;
                break;
            }


            if(message[i]=='\0')
            {
                ot1=false;
                if(out1[j-1]=='0') out1[j-1] = '\0';
                else
                {
                    strcpy(out1,none);
                    break;
                }
            }
            i++;
        }
        i = j =0;
        out2[j++] = '1';
        if(message[0]=='1')
        {
            out2[j++] = '0';
        }
        else if(message[0]=='2')
        {
            out2[j++] = '1';
        }
        else
        {
            strcpy(out2,none);
            ot2 = false;
        }
        i++;
        while(ot2)
        {
            if(message[i]=='0' && out2[j-1] =='0' && out2[j-2]=='0') out2[j++] = '0';
            else if(message[i]=='0')
            {
                strcpy(out2,none);
                ot2=false;
                break;
            }
            else if(message[i]=='1' && ((out2[j-1] =='1' && out2[j-2]=='0') || (out2[j-1] =='0' && out2[j-2]=='1'))) out2[j++] = '0';
            else if(message[i]=='1' && out2[j-1] =='0' && out2[j-2]=='0') out2[j++] = '1';
            else if(message[i]=='1')
            {
                strcpy(out2,none);
                ot2=false;
                break;
            }
            else if(message[i]=='2' && ((out2[j-1] =='1' && out2[j-2]=='0') || (out2[j-1] =='0' && out2[j-2]=='1'))) out2[j++] = '1';
            else if(message[i]=='2' && out2[j-1] =='1' && out2[j-2]=='1') out2[j++] = '0';
            else if(message[i]=='2')
            {
                strcpy(out2,none);
                ot2=false;
                break;
            }
            else if(message[i]=='3' && out2[j-1] =='1' && out2[j-2]=='1') out2[j++] = '1';
            else
            {
                strcpy(out2,none);
                ot2=false;
                break;
            }


            if(message[i]=='\0')
            {
                ot2=false;
                if(out2[j-1]=='0') out2[j-1] = '\0';
                else
                {
                    strcpy(out2,none);
                    break;
                }
            }
            i++;
        }
        one = out1;
        two = out2;
        cout<<out1<<" ands "<<out2<<endl;
        output.push_back(one);
        output.push_back(two);
        return output;
    }
};


template<typename T> void print( T a )
{
    cerr << a;
}

void print( long long a )
{
    cerr << a << "L";
}

void print( string a )
{
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a )
{
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ )
    {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need )
{
    if ( have == need )
    {
        cerr << "Case " << n << " passed." << endl;
    }
    else
    {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need )
{
    if( have.size() != need.size() )
    {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ )
    {
        if( have[i] != need[i] )
        {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need )
{
    if ( have == need )
    {
        cerr << "Case " << n << " passed." << endl;
    }
    else
    {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

    BinaryCode objectBinaryCode;

    //test case0
    string param00 = "123210122";
    vector <string> ret0 = objectBinaryCode.decode(param00);
    vector <string> need0;
    need0.push_back("011100011");
    need0.push_back("NONE");
    assert_eq(0,ret0,need0);

    //test case1
    string param10 = "11";
    vector <string> ret1 = objectBinaryCode.decode(param10);
    vector <string> need1;
    need1.push_back("01");
    need1.push_back("10");
    assert_eq(1,ret1,need1);

    //test case2
    string param20 = "22111";
    vector <string> ret2 = objectBinaryCode.decode(param20);
    vector <string> need2;
    need2.push_back("NONE");
    need2.push_back("11001");
    assert_eq(2,ret2,need2);

    //test case3
    string param30 = "123210120";
    vector <string> ret3 = objectBinaryCode.decode(param30);
    vector <string> need3;
    need3.push_back("NONE");
    need3.push_back("NONE");
    assert_eq(3,ret3,need3);

    //test case4
    string param40 = "3";
    vector <string> ret4 = objectBinaryCode.decode(param40);
    vector <string> need4;
    need4.push_back("NONE");
    need4.push_back("NONE");
    assert_eq(4,ret4,need4);

    //test case5
    string param50 = "12221112222221112221111111112221111";
    vector <string> ret5 = objectBinaryCode.decode(param50);
    vector <string> need5;
    need5.push_back("01101001101101001101001001001101001");
    need5.push_back("10110010110110010110010010010110010");
    assert_eq(5,ret5,need5);
    return 0;
}


/*#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryCode
{
public:
    string[] decode(string message)
    {
        string out1, out2, none = "NONE", output[2];
        int i=1,j=0;
        bool ot1, ot2;
        ot1 = ot2 = true;
        out1[j++] = '0';
        if(message[0]=='0')
        {
            out1[j++] = '0';
        }
        else if(message[0]=='1')
        {
            out1[j++] = '1';
        }
        else
        {
            out1 = none;
            ot1 = false;
        }

        while(ot1)
        {
            if(message[i]=='0' && out1[j-1] =='0' && out1[j-2]=='0') out1[j++] = '0';
            else if(message[i]=='0')
            {
                out1 = none;
                ot1=false;
                break;
            }
            else if(message[i]=='1' && ((out1[j-1] =='1' && out1[j-2]=='0') || (out1[j-1] =='0' && out1[j-2]=='1'))) out1[j++] = '0';
            else if(message[i]=='1' && out1[j-1] =='0' && out1[j-2]=='0') out1[j++] = '1';
            else if(message[i]=='1')
            {
                out1 = none;
                ot1=false;
                break;
            }
            else if(message[i]=='2' && ((out1[j-1] =='1' && out1[j-2]=='0') || (out1[j-1] =='0' && out1[j-2]=='1'))) out1[j++] = '1';
            else if(message[i]=='2' && out1[j-1] =='1' && out1[j-2]=='1') out1[j++] = '0';
            else if(message[i]=='2')
            {
                out1 = none;
                ot1=false;
                break;
            }
            else if(message[i]=='3' && out1[j-1] =='1' && out1[j-2]=='1') out1[j++] = '1';
            else
            {
                out1 = none;
                ot1=false;
                break;
            }


            if(message[i]=='\0')
            {
                ot1=false;
                if(out1[j-1]=='0') out1[j-1] = '\0';
                else
                {
                    out1 = none;
                    break;
                }
            }
            i++;
        }
        i = j =0;
        out2[j++] = '1';
        if(message[0]=='1')
        {
            out2[j++] = '0';
        }
        else if(message[0]=='2')
        {
            out2[j++] = '1';
        }
        else
        {
            out2 = none;
            ot2 = false;
        }
        i++;
        while(ot2)
        {
            if(message[i]=='0' && out2[j-1] =='0' && out2[j-2]=='0') out2[j++] = '0';
            else if(message[i]=='0')
            {
                out2 = none;
                ot2=false;
                break;
            }
            else if(message[i]=='1' && ((out2[j-1] =='1' && out2[j-2]=='0') || (out2[j-1] =='0' && out2[j-2]=='1'))) out2[j++] = '0';
            else if(message[i]=='1' && out2[j-1] =='0' && out2[j-2]=='0') out2[j++] = '1';
            else if(message[i]=='1')
            {
                out2 = none;
                ot2=false;
                break;
            }
            else if(message[i]=='2' && ((out2[j-1] =='1' && out2[j-2]=='0') || (out2[j-1] =='0' && out2[j-2]=='1'))) out2[j++] = '1';
            else if(message[i]=='2' && out2[j-1] =='1' && out2[j-2]=='1') out2[j++] = '0';
            else if(message[i]=='2')
            {
                out2 = none;
                ot2=false;
                break;
            }
            else if(message[i]=='3' && out2[j-1] =='1' && out2[j-2]=='1') out2[j++] = '1';
            else
            {
                out2 = none;
                ot2=false;
                break;
            }


            if(message[i]=='\0')
            {
                ot2=false;
                if(out2[j-1]=='0') out2[j-1] = '\0';
                else
                {
                    out2 = none;
                    break;
                }
            }
            i++;
        }
        output[0] = out1;
        output[1] = out2;
        return output[];
    }
};


template<typename T> void print( T a )
{
    cerr << a;
}

void print( long long a )
{
    cerr << a << "L";
}

void print( string a )
{
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a )
{
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ )
    {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need )
{
    if ( have == need )
    {
        cerr << "Case " << n << " passed." << endl;
    }
    else
    {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need )
{
    if( have.size() != need.size() )
    {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ )
    {
        if( have[i] != need[i] )
        {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need )
{
    if ( have == need )
    {
        cerr << "Case " << n << " passed." << endl;
    }
    else
    {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

void main( int argc, char* argv[] )
{

    BinaryCode objectBinaryCode;

    //test case0
    string param00 = "123210122";
    string[] ret0 = objectBinaryCode.decode(param00);
    string[] need0 = { "011100011",  "NONE" };
    assert_eq(0,ret0,need0);

    //test case1
    string param10 = "11";
    string[] ret1 = objectBinaryCode.decode(param10);
    string[] need1 = { "01",  "10" };
    assert_eq(1,ret1,need1);

    //test case2
    string param20 = "22111";
    string[] ret2 = objectBinaryCode.decode(param20);
    string[] need2 = { "NONE",  "11001" };
    assert_eq(2,ret2,need2);

    //test case3
    string param30 = "123210120";
    string[] ret3 = objectBinaryCode.decode(param30);
    string[] need3 = { "NONE",  "NONE" };
    assert_eq(3,ret3,need3);

    //test case4
    string param40 = "3";
    string[] ret4 = objectBinaryCode.decode(param40);
    string[] need4 = { "NONE",  "NONE" };
    assert_eq(4,ret4,need4);

    //test case5
    string param50 = "12221112222221112221111111112221111";
    string[] ret5 = objectBinaryCode.decode(param50);
    string[] need5 = ;
    assert_eq(5,ret5,need5);

};*/
