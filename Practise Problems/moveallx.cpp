#include<iostream>
using namespace std;

string moveall(string s,char c)     //Move all character c to last
{
    if(s.length()==0)
        return "";

    char ch = s[0];
    string str = moveall(s.substr(1),c);

    if(ch==c)
        return str+ch;
    return ch+str;
}

int main()
{
    cout<<moveall("axabxbdkxnskx",'x');
    return 0;
}