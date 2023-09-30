#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
	int n,k;
    cin>>n;
    vector<string> names(n);
    vector<int> idx;
    for(auto &c:names)cin>>c;
    int sz = 0;
    string s = "";
    idx.push_back(0);
    for(int i = 0;i<n;i++){
        sz+=names[i].size();
        s+=names[i];
        if(i)
            idx.push_back(names[i-1].size()+idx.back());
    }
    cin>>k;
    k--;
    int x = k/sz;
    x%=n;
    k-=(x*sz);
    cout<<s[(idx[x]+k)%sz]<<endl;
    return 0;
}  


// CheemsDogeWalterPerroKaren DogeWalterPerroKarenCheemsWalterPerroKarenCheemsDoge