#include<bits/stdc++.h>
using namespace std;

int max_area(vector<int> v)
{
    int n = v.size(),ans = 0,i = 0;
    stack<int> st;
    v.push_back(0);
    while (i<n)
    {
        while(!st.empty() and v[st.top()]>v[i])
        {
            int t = st.top();
            int h = v[t];
            st.pop();
            if(st.empty())
                ans = max(ans,h*i);
            else{
                int len = i-st.top()-1;
                ans = max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}


int main()
{
    int arr[] = {2,1,5,6,2,3};
    vector<int> v(arr,arr+6);
    cout<<max_area(v);
    return 0;
}