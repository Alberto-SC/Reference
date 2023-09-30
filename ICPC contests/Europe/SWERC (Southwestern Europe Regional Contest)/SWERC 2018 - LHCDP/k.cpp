#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
bool equal(string &a,string &b){
    int n = a.size();
    for(int i = 0;i<n;i++)
        if(a[i] != b[(n-1)-i])return false;
    
    return true;
}
const int maxn = 707;
int DP[maxn][maxn];
string s;
const int inf = 100000;
vector<int> kmp(const string& v){
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

int possible(int l,int r){
    string t = "";
    for(int i = l;i<r;i++)
        t+=s[i];
    vector<int> p = kmp(t);
    // for(auto c:p)cout<<c<<" ";
    // cout<<endl;
    int sz = r-l;
    for(int i= 1;i<=sz;i++){
        if(sz%i == 0){
            if(p.back()== ((sz/i)-1)*i)return i;
        }
    }
    return sz;
}

int solve(int l,int r){
    // cout<<l<<" "<<r<<endl;
    int &x = DP[l][r];
    if(x!= inf)return x;
    for(int i = l+1;i<r;i++){
        int y = solve(l,i)+solve(i,r);
        // cout<<"L "<<l<<" "<<"R: "<<r<<" "<<" Div: "<<i<<" RES: "<<y<<endl;
        x = min(x,y);
    }
    
    int z = possible(l,r);
    // cout<<"L "<<l<<" "<<"R: "<<r<<" "<<" X: "<<x<<" z: "<<z<< " DP: "<<DP[l][l+z]<<endl;
    // cout<<z<<endl;
    if(z!= r-l){
        x = min(x,DP[l][l+z]);  
    }
    return x;
}

int main(){
    int n;
    cin>>n;
    cin>>s;
    memset(DP,inf,sizeof(DP));
    for(int i = 0;i<maxn;i++)
        for(int j = 0;j<maxn;j++)
            DP[i][j] = inf;
    for(int i = 0;i<n-1;i++)
        DP[i][i+1] =1;
    // cout<<possible(0,n)<<endl;
    cout<<solve(0,n)<<endl;
    return 0;
}  
// 16
// abbcabbc
// abcabc