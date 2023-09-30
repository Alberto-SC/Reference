#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

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

int main(){__
	int n;
    string s,t,a;
    cin>>s>>t;
    a = string(t.size(),'$');
    a+=s;
    a+= string(t.size(),'$');
    int mn = t.size()+1;
    for(int i = 0;i<a.size()-t.size();i++){
        int cont = 0;
        for(int j = 0;j<t.size();j++){
            if(a[i+j]== t[j])cont++;
        }
        mn = min((int)t.size()-cont,mn);
    }

    cout<<mn<<endl;
    return 0;
}  

