#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n,x;
    cin>>n;
    stack<pair<int,int>> st;
    while(n--){
        string t;
        cin>>t;
        if(t == "PUSH"){
            cin>>x;
            pair<int,int> tp = {1e9,1e9};
            if(!st.empty())
                tp = st.top();
            st.push({x,min(tp.second,x)});
        }
        else if(t =="POP"){
            if(!st.empty())
                st.pop();
            else 
                cout<<"EMPTY"<<endl;
        }
        else {
            if(st.empty())
                cout<<"EMPTY"<<endl;
            else 
                cout<<st.top().second<<endl;
        }
    }
    return 0;
}