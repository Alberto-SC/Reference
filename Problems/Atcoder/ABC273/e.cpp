#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x,q;
    cin>>q;
    vector<*vector<int>> A;
    A.push_back({});
    int id = 0;
    map<int,int> mp;
    while(q--){
        string t;
        cin>>t;
        if(t=="DELETE"){
            if(A[id]->size())A[id]->pop_back();
            if(A[id]->size())cout<<A[id]->back()<<" ";
            else cout<<-1<<" ";
        }
        else if(t == "ADD"){
            cin>>x;
            A[id]->push_back(x);
            cout<<A[id]->back()<<" ";
        }
        else if(t == "LOAD"){
            cin>>x;
            if(mp.count(x))A[id] = A[mp[x]];
            else A[id] = {};
            if(A[id]->size())cout<<A[id]->back()<<" ";
            else cout<<-1<<" ";
        }
        else{
            cin>>x;
            mp[x] = id++;
            A->push_back(A[id-1]);
            if(A[id]->size())cout<<A[id]->back()<<" ";
            else cout<<-1<<" ";
        }
    }
    cout<<endl;
    return 0;
}