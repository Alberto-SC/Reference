#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

map<int,int> DP;
int solve(int n,int turn  = 0){ 
    if(n == 1)return !turn;
    if(n == 0)return turn;
    if(DP.count(n))return DP[n];
    int divs = 0;
    int ans = 0;
    for(int i = 1;i*i<=n;i++){
        if(n%i == 0){
            divs++;
            ans+=solve(n-i,!turn);
            if(n%i != i){
                divs++;
                ans+=solve(n-(n/i),!turn);
            }
        }
    }
    int x = 0;
    if(!turn)x = ans<divs?1:0;
    else x = ans?1:0;
    return DP[n]= x;
}

int main(){__
	int t= 1,n;
    char c;
    cin>>t;
    // for(int i = 1;i<10;i++)
        // cout<<DP[i]<<" ";
    cout<<endl;
    while(t--){
        cin>>n;
        cin>>c;
        DP.clear();    
        if(c == 'T')
            if(solve(n))
                cout<<"T-Series"<<endl;
            else    
                cout<<"PewDiePie"<<endl;
        else
            if(solve(n))
                cout<<"PewDiePie"<<endl;
            else
                cout<<"T-Series"<<endl;
    }
    return 0;
}  


