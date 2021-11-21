#include<bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int,int>> s;
    for(auto i =prices.begin(); i!=prices.end(); i++)
    {
        int price = *i;
        int days=1;
        while(!s.empty() and s.top().first<=price)
        {
            days+=s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    int arr[] = {100,80,60,70,60,75,85};
    vector<int> a (arr,arr+7);
    vector <int> res = stockspan(a);
    for(auto i=a.begin(); i!=a.end(); i++)
        cout<<*i<<" ";
    return 0;
}