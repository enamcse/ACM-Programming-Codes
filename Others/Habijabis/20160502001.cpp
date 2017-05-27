/**
* E:\Dropbox\Code\Others\Habijabis\20160502001.cpp
* Created on: 2016-05-02-06.12.42, Monday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

    #include <iostream>
    #include <string>
    #include <fstream>

    using namespace std;


    int main()
    {
        ifstream fin ("data1.txt");
        int ID;
        string name;
        int test1, test2, test3;

        char answer;
        cin >> answer;
        while (answer == 'Y')
        {

            fin >> ID;
            fin.ignore();
            getline(fin, name);
            cout << name << endl;
            fin >> test1>> test2>> test3;

            cout << ID << endl;


            cout << test1 << "\t" << test2 << "\t" << test3 << "\t";
            cin >> answer;

        }
    }
