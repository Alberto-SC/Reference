#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    int x = 0,y = 0,x0,y0;
    cin>>t;
    while(t--){
        cin>>x0>>y0;
        string s;
        cin>>s;
        vector<int> cont(4);
        for(int i = 0;i<s.size();i++){
            if(s[i]== 'L')
                cont[0]++;
            else if(s[i]== 'R')
                cont[1]++;
            else if(s[i]== 'U')
                cont[2]++;
            else 
                cont[3]++;
        }
        bool flag = true;
        if(x0>0){
            if(cont[1]<x0)flag = false;
            if(y0>0){
                if(cont[2]<y0)flag = false;
            }
            else{
                if(cont[3]<abs(y0))flag = false;
            }
        }
        else{
            if(cont[0]<abs(x0))flag = false;
            if(y0>0){
                if(cont[2]<y0)flag = false;
            }
            else{
                if(cont[3]<abs(y0))flag = false;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  

