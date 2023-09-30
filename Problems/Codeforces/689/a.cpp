#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i =0;i<n;i++)
            cout<<char((i%3)+'a');
        cout<<endl;
    }
    return 0;
}  

