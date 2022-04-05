#include<bits/stdc++.h>
using namespace std;
map<char,bool>Final;
vector<char> alphabet;
queue<set<char>>q;
set<char>a;
map<set<char>,bool>temp;
map<pair<char,char>,vector<char>>table;

int main(){
    int state;
    cout<<"Enter the number of states: "<<endl;
    cin>>state;

    char start;
    cout<<"Enter the start state: "<<endl;
    cin>>start;
    int final;
    cout<<"Enter the number of final states: "<<endl;
    cin>>final;
    cout<<"Enter the final states: "<<endl;
    
    for(int i=0;i<final;i++)
    {
        char f;
        cin>>f;
        Final[f]=true;
    }
    
    alphabet.push_back('0');
    alphabet.push_back('1');
    
    for(int i=97;i<state+97;i++)
    {
        cout<<"Transition of "<<(char)(i);
        for(auto x: alphabet)
        {
            cout<<" for "<<x<<": "<<endl;
            while(1)
            {
                char State;
                cin>>State;
                if(State=='m')break;
                table[{i,x}].push_back(State);
            }
        }
    }
    a.insert(start);
    q.push(a);
    temp[a]=true;
    cout<<"state\t0\t1"<<endl;
    while(!q.empty())
    {
	cout<<endl;
        a=q.front();
        q.pop();
        for(auto t:a)
            {
		    cout<<t;
	    }
        for(auto x:alphabet)
        {
            set<char>DFAstates;
            for(auto y:a)
            {
                for(auto z:table[{y,x}])
                {
                    DFAstates.insert(z);
                }
            }
            if(DFAstates.size()==0)
            {
                DFAstates.insert(state+97);
            }
            if(temp[DFAstates]==false)
            {
                q.push(DFAstates);
                temp[DFAstates]=true;
            }
    
           for(auto t:a)
            {
		    for(auto y:DFAstates)
		    {
		        cout<<"\t{"<<y<<"}";
		    }
	    }
            
        }
    }
}
