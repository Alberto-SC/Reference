#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    vector<lli> p_pow(max(S,T)); 
    p_pow[0] = 1; 
    for (int i = 1;i<p_pow.size();i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<lli> h(T+1,0); 
    for(int i = 0;i<T;i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    
    lli h_s = 0; 
    for(int i=0;i<S;i++) 
        h_s = (h_s+(s[i]-'a'+1)*p_pow[i])%m; 
    
    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        lli cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        string s,p;
        cin>>s>>p;
        vector<int> ans = rabin_karp(p,s);
        if(ans.size()== 0){
            cout<<"Not Found"<<endl;
        }
        else {
            cout<<ans.size()<<endl;
            for(auto c:ans)cout<<c+1<<" ";
            cout<<endl;
        }   
        if(i<t-1)cout<<endl;
    }
    return 0;
}