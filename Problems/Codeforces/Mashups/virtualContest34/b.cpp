#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        vector<vector<int>> s(9,vector<int>(9));
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                char x;
                cin>>x;
                s[i][j] = (int)x-'0';
            }
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                s[(3*i)+j][(3*j)+i]=s[(3*i)+j][(3*j)+i]+1;
                if(s[(3*i)+j][(3*j)+i]==10)s[(3*i)+j][(3*j)+i] = 1;
            }
        }
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++)
                cout<<s[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}  
