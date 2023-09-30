#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,c0,c1,h;
    cin>>t;
    while(t--){
        cin>>n>>c0>>c1>>h;
        string s;
        cin>>s;
        int total = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== '0'){
                if(h+c1<=c0)
                   total+=h+c1;
                else total+=c0;
            }
            else{
                if(h+c0<=c1)
                    total+=h+c0;
                else total+=c1;
            }
        }
        cout<<total<<endl;

    }
    return 0;
}  

