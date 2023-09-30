#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int last = 0;
        char ans[n][m];
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                ans[i][j] = '?';
        if(n&1){    
            if(k%(m/2) || (k%(m/2)==0 && (k/(m/2))%2==0)){
                cout<<"NO"<<endl;
            }
            else {
                for(int i = 0;i<n;i++){
                    if(!k)break;
                    for(int j = 0;j<m;j+=2){
                        if(!k)break;
                        ans[i][j] =char(last%26+'a');
                        ans[i][j+1] =char(last%26+'a');
                        last++;
                        k--;
                        if(!k)break;
                    }
                    if(!k)break;
                }
                bool flag = true;
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<m;j++){
                        if(ans[i][j]=='?'){
                            ans[i][j] =char(last%26+'a');
                            if(i+1==n || ans[i+1][j]!='?')
                                flag = false;
                            else 
                                ans[i+1][j] =char(last%26+'a');
                            last++;
                        }
                    }
                }
                if(flag && k==0){
                    cout<<"YES"<<endl;
                    for(int i = 0;i<n;i++){
                        for(int j = 0;j<m;j++)
                            cout<<ans[i][j];
                        cout<<endl;
                    }
                
                }
                else cout<<"NO"<<endl;
            }
            continue;
        }
        for(int i = 0;i<m;i+=2){
            if(i+1==m)break;
            if(k>=n){
                for(int j = 0;j<n;j++){
                    ans[j][i] =char(last%26+'a');
                    ans[j][i+1] =char(last%26+'a');
                    last++;
                }
                k-=n;
            }
            else{
                if(n&1 && k&1){
                    for(int j = 0;j<k;j++){
                        ans[j][i] =char(last%26+'a');
                        ans[j][i+1] =char(last%26+'a');
                        last++;
                    }
                    for(int j = k;j<n;j+=2){
                        ans[j][i] = char(last%26+'a');
                        ans[j+1][i] = char(last%26+'a');
                        last++;
                        ans[j][i+1] = char(last%26+'a');
                        ans[j+1][i+1] = char(last%26+'a');
                        last++;
                    }
                    k= 0;
                }
                else if(n&1 && k%2==0){
                    for(int j = 0;j<k-1;j++){
                        ans[j][i] =char(last%26+'a');
                        ans[j][i+1] =char(last%26+'a');
                        last++;
                    }
                    for(int j = k-1;j<n;j+=2){
                        ans[j][i] = char(last%26+'a');
                        ans[j+1][i] = char(last%26+'a');
                        last++;
                        ans[j][i+1] = char(last%26+'a');
                        ans[j+1][i+1] = char(last%26+'a');
                        last++;
                    }
                    k-=k-1;
                }
                else if(n%2==0 && k&1){
                    for(int j = 0;j<k-1;j++){
                        ans[j][i] =char(last%26+'a');
                        ans[j][i+1] =char(last%26+'a');
                        last++;
                    }
                    for(int j = k-1;j<n;j+=2){
                        ans[j][i] = char(last%26+'a');
                        ans[j+1][i] = char(last%26+'a');
                        last++;
                        ans[j][i+1] = char(last%26+'a');
                        ans[j+1][i+1] = char(last%26+'a');
                        last++;
                    }
                    k-=k-1;
                }
                else if(n%2==0 && k%2==0){
                    for(int j = 0;j<k;j++){
                        ans[j][i] =char(last%26+'a');
                        ans[j][i+1] =char(last%26+'a');
                        last++;
                    }
                    for(int j = k;j<n;j+=2){
                        ans[j][i] = char(last%26+'a');
                        ans[j+1][i] = char(last%26+'a');
                        last++;
                        ans[j][i+1] = char(last%26+'a');
                        ans[j+1][i+1] = char(last%26+'a');
                        last++;
                    }
                    k=0;
                }
            }
            if(!k)break;
        }
        bool flag = true;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(ans[i][j]=='?'){
                    ans[i][j] =char(last%26+'a');
                    if(i+1==n || ans[i+1][j]!='?')
                        flag = false;
                    else 
                        ans[i+1][j] =char(last%26+'a');
                    last++;
                }
            }
        }
        if(flag && k==0){
            cout<<"YES"<<endl;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
        
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}  
