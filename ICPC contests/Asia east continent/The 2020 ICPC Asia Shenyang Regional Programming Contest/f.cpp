#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
 
signed main (){__
    int n; cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i];
    }
    vector<int> vec2 = vec;
    sort(vec2.begin(), vec2.end());
 
    multiset<int> st1;
    multiset<int> st2;
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(st2.count(vec[i]))
            st2.erase(st2.find(vec[i]));
        else 
            st1.insert(vec[i]);
 

        if(st1.count(vec2[i]))
            st1.erase(st1.find(vec2[i]));
        else 
            st2.insert(vec2[i]);


        if(st2.size()==0){
            cont++;
            st2.clear();
            st2.clear();
        }
    }
 
    cout << cont << endl;
    return 0;
}