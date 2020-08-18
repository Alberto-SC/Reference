
#include <bits/stdc++.h>
using namespace std;
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
int main(){
    string s;
    string t;
    cin>>s;
    cin>>t;
    int n = s.size();
    int m = t.size();
    string match = s+"$"+t;
    vector<int> kmp =p_function(match);
    vector<int> ans(m-n+1);
    for(int i = 0; i < m - n + 1; i++)
        if(kmp[2 * n + i] == n)
            ans[i] = 1;
    for(auto c:kmp)cout<<c<<" ";
    cout<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}
