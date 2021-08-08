#include<bits/stdc++.h>
using namespace std;

int rain(vector<int> a)
{
    stack <int>st;
    int n = a.size(),ans=0;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() and a[st.top()]<a[i]){
            int cur = st.top();
            st.pop();
            if(st.empty())
                break;
            int diff = i-st.top()-1;
            ans+=(min(a[i],a[st.top()]) - a[cur])*diff;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(a,a+12);
    cout<<rain(v);
    return 0;
}