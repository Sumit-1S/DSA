#include<bits/stdc++.h>
using namespace std;

int* LPS(string s)
{
  int *arr = new int[s.length()];
  for(int k=0;k<s.length();k++) arr[k]=0;
  int i(1),j(0);
  while(i++<s.length())
  {
    j=arr[i-1];
    while(j>0 and s[i]!=s[j]) j=arr[j-1];
    if(s[i]==s[j])  j++;
    arr[i]=j;
  }
  return arr;
}

vector<int> match(string t,string s,int *arr)
{
  vector<int> v;
  int i(0),j(0);
  while(i<t.length())
  {
    if(s[j]==t[i])  i++,j++;
    else{
      if(j!=0)  j=arr[j-1];
      else      i++;
    }
    if(j==s.length()) v.push_back(i-s.length());
  }
  return v;
}
int main()
{
    string s,t;
    int i(0),j(0);
    cin>>t>>s;
    int *arr = LPS(t);
    cout<<"LPS formed is: ";
    for(int i=0;i<t.length();i++) cout<<arr[i]<<" ";
    cout<<endl;
    vector<int> v = match(t,s,arr);
    // pos>0 ? cout<<"String match found at: "<<pos<<endl
    //       : cout<<"String match not found"<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    return 0;
}