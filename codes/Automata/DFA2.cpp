#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> input;

int isAccept(char s[],char ch)
{
    int c=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==ch)
        {
            count++;
        }
    }
    if(count>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the table:"<<endl;
    for(int i=0;i<n;i++)
    {
        char x,y,z;
        cin>>x>>y>>z;
        input.push_back({x,y,z});
    }
    char start;
    cout<<"Enter start state:"<<endl;
    cin>>start;
    cout<<"Enter number of accepting state"<<endl;
    cin>>ac;
    char acc[ac];
    cout<<"Enter accepting states"<<endl;
    for(int i=0;i<ac;i++)
    {
        cin>>acc[ac];
    }
    cout<<"Node\t0\t1"<<endl<<endl;
    for(int i=0;i<input.size();i++)
    {
        if(isAccept(acc,input[i][0])==1)
        {
            cout<<"*";
            for(int j=0;j<input[i].size();j++)
        {
            cout<<input[i][j]<<"\t";
        }
        }
        else if(input[i][0]==start)
        {
            cout<<"->";
            for(int j=0;j<input[i].size();j++)
        {
            cout<<input[i][j]<<"\t";
        }
        }
        else
        {
            for(int j=0;j<input[i].size();j++)
        {
            cout<<input[i][j]<<"\t";
        }
        }
        cout<<endl;
    }
    char s[100];
    cout<<"Enter the string: ";
    cin>>s;
    int i=0;
    for(int k=0;k<strlen(s);k++)
    {
        char temp;
        if(s[k]=='1')
        {
            temp=input[i][2];
            for(int j=0;j<input.size();j++)
            {
                if(input[j][0]==temp)
                {
                    i=j;
                }
            }
        }
        else if(s[k]=='0')
        {
            temp=input[i][1];
            for(int j=0;j<input.size();j++)
            {
                if(input[j][0]==temp)
                {
                    i=j;
                }
            }
        }
        if(k==(strlen(s)-1) && temp!=acc)
        {
            cout<<"Not accepted!"<<endl;
        }
        else if(k==(strlen(s)-1) && temp==acc)
        {
            cout<<"Accepted!"<<endl;
        }
    }
}