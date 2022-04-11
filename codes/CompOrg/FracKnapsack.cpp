#include <bits/stdc++.h>
using namespace std;
 vector<pair<int,int>> v;
 vector<int>ve;
 void printVec(int n)
 {
     int i;
     for(i=0;i<n;i++)
    {
        cout<<"   "<<v[i].first<<"       "<<v[i].second<<endl;
    }
 }
 bool comp(pair<int,int> a, pair<int,int> b)
 {
     double x= (double) a.first/a.second;
     double y= (double) b.first/b.second;
     return x>y;
 }
int main()
{
    int n,i,j,knapsack;
    double sum=0.0;
    cin>>n;
    int wt,val;
    for(i=0;i<n;i++)
    {
        cin>>wt>>val;
        v.push_back(make_pair(val,wt));
    }
    cout<<"Profit   Weight"<<endl;
    printVec(n);
    sort(v.begin(),v.end(),comp);
    cout<<"Enter the capacity"<<endl;
    cin>>knapsack;
    for(i=0;i<n;i++)
    {
        if(knapsack>=v[i].second)
        {
            sum+=v[i].first;
            knapsack-=v[i].second;
            continue;
        }
        double vv= (double) v[i].first/v[i].second;
        sum+= vv*knapsack;
        knapsack=0;
        break;
    }
    cout<<"The sum will be: "<<sum<<endl;
}
