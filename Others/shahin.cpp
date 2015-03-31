//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
//#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
//#include <algorithm>


using namespace std;

string searching (string filename, string word)
{
    ifstream dataFile;
    dataFile.open(filename.c_str());
    string line, words;
    int line_no=0, len, esterik=-1;
    len = word.size();
    bool flag = false;
    if(word[len-1]=='*') esterik=len-1;

    while(getline(dataFile,line))
    {

        istringstream wordline(line);
        while(wordline>>words)
        {
            if(esterik==-1)
            {
                int i;
                for (i=0; i<word.size(); i++)
                {
                    if(words[i]!=word[i])
                    {
                        break;
                    }
                }
                if(i==word.size()&&(word.size()==words.size()||(word.size()+1==words.size()&&(words[ words.size() - 1 ] == '.'|| words[ words.size() - 1 ] == ',' || words[ words.size() - 1 ] == '/'))))
                {
                    line_no++;
                    flag = true;
                    cout<<"Found on line "<<line_no<<": "<<words<<endl;
                    cout<<line<<endl<<endl;
                }
            }
            else
            {
                int i;
                for (i=0; i<esterik; i++)
                {
                    if(words[i]!=word[i])
                    {
                        break;
                    }
                }
                if(i==esterik)
                {
                    line_no++;
                    flag = true;
                    cout<<"Found on line "<<line_no<<": "<<words<<endl;
                    cout<<line<<endl<<endl;
                }
            }
        }

    }

    if(!flag) cout<<word+" not found"<<endl;
    dataFile.close();
    char lineNo[100];
    sprintf(lineNo,"%d",line_no);
    return "I found the word "+words+" at line "+lineNo+": "+line;
}

string replacing (string filename, string word, string newWord)
{
    ifstream dataFile;
    dataFile.open(filename.c_str());
    string line, words, newLines="";
    int len,w;
    len = word.size();

    while(getline(dataFile,line))
    {
        w=0;
        istringstream wordline(line);
        while(wordline>>words)
        {
            int i;
            for (i=0; i<word.size(); i++)
            {
                if(words[i]!=word[i])
                {
                    break;
                }
            }
            if(i==word.size()&&(word.size()==words.size()||(word.size()+1==words.size()&&(words[ words.size() - 1 ] == '.'|| words[ words.size() - 1 ] == ',' || words[ words.size() - 1 ] == '/'))))
            {
                if(w)
                {
                    newLines+=" ";
                    newLines+=newWord;
                }
                else
                    newLines+=newWord;
            }
            else
            {
                if(w)
                {
                    newLines+=" ";
                    newLines+=words;
                }
                else
                    newLines+=words;
            }
            w++;
        }
        newLines+="\n";
    }
    dataFile.close();
    ofstream dataFileW;
    dataFileW.open(filename.c_str());
    dataFileW<<newLines;
    dataFileW.close();
    return newLines;
}


void view(string filename)
{
    ifstream dataFile;
    dataFile.open(filename.c_str());
    string line;
    while(getline(dataFile,line))
    {
        cout<<line<<endl;
    }
    dataFile.close();
    return;
}

int main()
{
    string  in_, out_;
    char s;
    do
    {
        cout<<"Enter Choice (Insert, Delete, View, Find, Replace, Statistics, Quit)"<<endl;
        cin>>s;
        switch(s)
        {
        case 'f':
        case 'F':
            cout<<"Enter a word:"<<endl;
            cin>>in_;
            searching("input.txt",in_);
            break;
        case 'r':
        case 'R':
            cout<<"Enter the word to replace: ";
            cin>>in_;
            cout<<"Enter the new word: ";
            cin>>out_;
            replacing("input.txt", in_, out_);
            break;
        case 'v':
        case 'V':
            view("input.txt");
        }
    }
    while(s!='Q'&&s!='q');


    return 0;
}
