#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1007;
int DP[maxn][maxn][2]
int solve(int a,int b,int turn = 0,int last = -1){
    int &x = DP[a][b][turn];
    if(x!=-1)return x;
    if(a|| b)
        x = 

}

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int a = 0,b =0 ;
        for(int i = 0;i<n/2;i++){
            if(s[i]== '0'&&s[n-i-1]=='1')
                a++;
            else if(s[i]== '1'&&s[n-i-1]=='0')
                a++;
            else if(s[i]== '1'&&s[n-i-1]=='0')
                b++;
            
        }
    }
    return 0;
}  
