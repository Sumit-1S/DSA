#include<bits/stdc++.h>
using namespace std;
//((a+b)) return 1
//(a+b)   return 0

bool bracket(string s)
{
    stack<char> st;
    bool ans = false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')
            st.push(s[i]);
        else if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            if(st.top() == '(')
                ans = true;
            while(st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/')
                st.pop();
            st.pop();
        }
    }
    return ans;
}

int main()
{
    string s = "(a+(a+b))";
    cout<<bracket(s);
    return 0;
}