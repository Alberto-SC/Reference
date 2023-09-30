#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int M[3007][3007];
int n,m;

bool isCenter(int x,int y){
    if(M[x-1][y]-M[x-1][y-1]!= M[x-1][y+1]-M[x-1][y])return false;
    if(M[x][y]-M[x][y-1]!= M[x][y+1]-M[x][y])return false;
    if(M[x+1][y]-M[x+1][y-1]!= M[x+1][y+1]-M[x+1][y])return false;
}

int brute(){
    
}
signed main(){__
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>M[i][j];

        vector<vector<int>> mx(n,vector<int>(m,0));
        cout<<endl;
        for(int i= 1;i<n;i++){
            for(int j = m-2;j>=1;j--){
                if(isCenter(i,j))
                    mx[i][j] = mx[i][j+1]+1;             
                       
            }
            for(auto c: mx[i])cout<<c<<" ";
            cout<<endl;
        }

        cout<<endl;
        int ans = 4;
        for(int i = 1;i<m-1;i++){
            vector<int> lf(n,-1),rg(n,n);
            stack<pair<int,int>> st;

            for(int j = 0;j<n;j++){
                while(st.size() && st.top().first>mx[j][i]){
                    auto s = st.top();
                    rg[s.second] = j;
                    st.pop();
                }
                st.push({mx[j][i],j});
            } 
            stack<pair<int,int>> st2;

            for(int j = n-1;j>=0;j--){
                while(st2.size() && st2.top().first>mx[j][i]){
                    auto s = st2.top();
                    rg[s.second] = j;
                    st2.pop();
                }
                st2.push({mx[j][i],j});
            } 

            for(auto c:lf)cout<<c<<" ";
            cout<<endl;
            for(auto c:rg)cout<<c<<" ";
            cout<<endl;
            cout<<endl;
        }

    }

    return 0;
}