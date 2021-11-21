#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++)
        {
            int st,ed;
            cin>>st>>ed;
            v.push_back(make_pair(ed,st));
        }
        sort(v.begin(),v.end());
        int end_prev=-1,count=0;
        for(int i=0;i<n;i++)
        {
            if(end_prev<=v[i].second)
            {
                count++;
                end_prev=v[i].first;
            }
        }
        cout<<"Number of Activities that can be performed at a time in uniprocessor: "<<count<<endl;
    }
    return 0;
}