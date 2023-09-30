#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int matrix[1000][1000];
int main(){
	int n,q; cin >> n >> q;
	int mxVal = 0, mxCount = 0;
	pair<int,int> mxOverall; //(i,j) -> j-i max
	int i,j; char op;
	while(q--){
		cin >> op;
        if(op=='R'){
            cin >> i >> j;
            matrix[i][j]++;
        }
        else if (op=='Q'){
            cin >> i;
            int mx = -1;
            for(int k = 1;k<=n;k++){
                mx = max(mx,matrix[i][k]);
            }
            int count = 0;
            int ans = 0;
            for(int k = 1;k<=n;k++){
                if(matrix[i][k]==mx){
                    count++;
                    ans = k;
                }
            }
            if(mx ==0)cout<<"No info"<<endl;
            else if(count>1)cout<<"Multiple"<<endl;
            else cout<<ans<<endl;
        }
        else{
            int mx = -1,ansi,ansj;
            int cont = 0;
            for(int i = 0;i<=n;i++){
                for(int j = 0;j<=n;j++){
                    mx = max(mx,matrix[i][j]);
                }
            }
            for(int i = 0;i<=n;i++){
                for(int j = 0;j<=n;j++){
                    if(matrix[i][j]==mx){
                        cont++;
                        ansi = i,ansj = j;
                    }
                }
            }
            if(cont>1)cout<<"Multiple"<<endl;
            else cout<<ansi<<" "<<ansj<<endl;
        }
		
	}

	return 0;
}
