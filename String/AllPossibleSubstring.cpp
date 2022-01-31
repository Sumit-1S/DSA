#include<bits/stdc++.h>
using namespace std;



int main()
{
  string s;
  cin>>s;
  int start = 0;
    int max = 1;
    for(int len=1;len<s.size();len++)
    {
        for(int i=0;i<s.size()-len;i++)
        {
            int j=i+len-1;
            for(int k=i;k<=j;k++)
                cout<<s[k];
            cout<<endl;
        }
    }
  return 0;
}