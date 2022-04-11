#include <bits/stdc++.h>
using namespace std;
 vector<pair<int,int>> v;
 void printVec(int n)
 {
     int i;
     for(i=0;i<n;i++)
    {
        cout<<"      "<<v[i].first<<"              "<<v[i].second<<endl;
    }
 }
int main()
{
    int n,i,j,count=1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    cout<<"Starting time   Ending time"<<endl;
    printVec(n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(v[i].second>v[j].second)
            {
                swap(v[i],v[j]);
            }
        }
    }
    int temp=v[0].second;
    for(i=0;i<n;i++)
        {
            if(v[i].first>temp)
            {
                count++;
                temp=v[i].second;
            }
        }
    cout<<"Accepting conditions: "<<count<<endl;
}
