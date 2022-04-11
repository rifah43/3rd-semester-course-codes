#include<bits/stdc++.h> 
using namespace std; 

int p[100][100],v[100],we[100];
int knap(int n, int w)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        p[i][0]=0;
    }
    for(i=0;i<=n;i++)
    {
        p[0][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(we[i]>j)
            p[i][j]=p[i-0][j];

            else
            p[i][j]= max(v[i]+p[i-1][j-we[i]],p[i-1][j]);
        }
    }
}
int main() 
{ 
    int i,j,n,w;
    //freopen("knap.txt","r",stdin);
    cout<<"Enter the number of partition: "<<endl;
    cin>>n>>w;
    cout<<"Enter the values of partitions and maximum capacity of knapsack: "<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    cout<<"Enter the weights: "<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>we[i];
    }
    knap(n,w);
    cout<<"Maximum Profit: "<<p[n][w]<<endl;
} 
