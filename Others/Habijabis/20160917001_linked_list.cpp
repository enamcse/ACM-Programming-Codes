/**
* E:\Dropbox\Code\Others\Habijabis\20160917001_linked_list.cpp
* Created on: 2016-09-17-01.58.34, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

class Student
{
public:
    string id;

    ///Default Constructor
    Student()
    {
        id = generateId();
        name="";
        address="";
        gpa=0.0;
    }
    Student(string _name,string _address, double _gpa)
    {
        id = generateId();
        name=_name;
        address=_address;
        gpa=_gpa;
    }

    ///Destructor
    ~Student(){}
    ///Getters
    string getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    double getGPA()
    {
        return gpa;
    }

    ///Setters
    void setName(string s)
    {
        name = s;
    }
    void setAddress(string s)
    {
        address = s;
    }
    void setGPA(double num)
    {
        gpa = num;
    }
    void displayStudents(Student recs[]){
        int n = sizeof(recs)/sizeof(recs[0]);
        cout << n <<" "<< sizeof(recs)<<" > "<<sizeof(recs[0]) << " ok?\n";
        n = 10;
        for (int i = 0; i<n; i++)
        {
            cout<<"Student Information for Student ID : " << recs[i].getId() << "\n";
            cout <<"---\n";
            cout <<"Name : " << recs[i].getName() << "\n";
            cout <<"Address : " << recs[i].getAddress() << "\n";
            cout <<"GPA : " << fixed <<setprecision(2) << recs[i].getGPA() << "\n";
        }
    }
private:
    string name;
    string address;
    double gpa;

    ///It generates a new student ID randomly
    string generateId()
    {
        string ret = "A";
        for (int i =0; i<8; i++)
            ret+=(char)('0'+(rand()%10));
        return ret;
    }
};

int main()
{
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    srand(time(0));
    Student stdRecords[10];
    stdRecords[0].displayStudents(stdRecords);
    cout << "Everything done!" <<endl;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
