#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> N[n];
        vector<int> total(6);
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            N[i].resize(6);
            for(int j = 0; j<x;j++){
                char c;
                cin>>c;
                N[i][c-'A']++;
                total[c-'A']++;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<6;j++){
                cout<<char(j+'A')<<":"<<N[i][j];
                if(j!=5)cout<<" ";
            }
            cout<<endl;
        }
        cout<<"TOTAL: ";
        for(int i = 0;i<6;i++){
            cout<<char(i+'A')<<":"<<total[i];
            if(i!=5)cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}  
