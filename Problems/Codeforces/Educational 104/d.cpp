#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    vector<lli> pre;
    pre.push_back(5);
    lli cont = 0;
    while(1){
        pre.push_back(pre.back()+8+(4*cont));
        cont++;
        if(pre.back()>=1e9)break;
    }
    while(t--){
        cin>>n;
        int idx = upper_bound(pre.begin(),pre.end(),n)-pre.begin();
        cout<<idx<<endl;
    }
    return 0;
}  

