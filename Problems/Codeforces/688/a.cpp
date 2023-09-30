#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> b(101);
        for(int i = 0;i<n;i++){
            int x;
            cin>>x,b[x]++;
        }
        for(int i = 0;i<m;i++){
            int x;
            cin>>x,b[x]++;
        }
        int cont = 0;
        for(int i = 0;i<=100;i++)
            if(b[i]==2)cont++;
        cout<<cont<<endl;
    }
    return 0;
}  

