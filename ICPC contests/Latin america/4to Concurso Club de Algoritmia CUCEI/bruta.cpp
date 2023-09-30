#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const lli mod = 1e9+7;
lli bin_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

vector<int> p_function(const string& v){
    int n = v.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && v[j] != v[i]){
            j = p[j - 1];
        }
        if(v[j] == v[i])
            j++;
        p[i] = j;   
    }
    return p;
}
int get_frec(string s,string t){
    string aux = s+'$'+t;
    vector<int> p = p_function(aux);
    int cont = 0;
    int n = aux.size();
    for(int i = s.size();i<n;i++)
        if(p[i]==s.size())cont++;
    return cont;
}

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    set<string> diff;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            diff.insert(s.substr(i,(j-i)+1));
        }
    }
    lli ans = 0;
    for(auto c:diff){
        int x = get_frec(c,s);
        ans+= bin_pow(x,k);
    }
    cout<<ans<<endl;
    return 0;
}