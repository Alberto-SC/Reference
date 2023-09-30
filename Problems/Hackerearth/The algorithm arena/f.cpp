#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    string s;
    cin>>s;
    istringstream in(s);
    vector<string> words;
    string w;
    while(getline(in, w, '.')){
        words.push_back(w);
    }
    for(int i = words.size()-1;i>=0;i--){
        cout<<words[i];
        if(i!=0)cout<<".";
    }
    cout<<endl;
}


