#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<char>>  read(string s){
    vector<vector<char>> M(8,vector<char> (8));
    int x = 0,y = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='/'){
            x++;
            y =0;
        }
        else if(s[i]>='1' && s[i]<='8'){
            for(int j = 0;(j<s[i]-'0');j++){
                M[x][y] = '0';
                y++;
            }
        }
        else{
            M[x][y] = s[i]; 
            y++;
        }
    }
    return M;
}

void rotate(vector<vector<char>> &M){
    int n = 8;
    for (int i=0;i<n/2;i++) { 
        for (int j=i;j<n-i-1;j++) { 
            int temp=M[i][j]; 
            M[i][j]=M[n-1-j][i]; 
            M[n-1-j][i]=M[n-1-i][n-1-j]; 
            M[n-1-i][n-1-j]=M[j][n-1-i]; 
            M[j][n-1-i]=temp; 
        } 
    }
}

signed main(){__
    int T = 1,n;
    string s;
    vector<vector<vector<char>>> ans;
    while(cin>>s){
        vector<vector<char>> M = read(s);
        rotate(M);
        ans.push_back(M);
        for(auto c:M){
            for(int j = 0;j<c.size();j++){
                cout<<c[j];
                if(j!=c.size()-1)cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    // for(int i = 0;i<ans.size();i++){
    //     for(auto c:ans[i]){
    //         for(int j = 0;j<c.size();j++){
    //             cout<<c[j];
    //             if(j!=c.size()-1)cout<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     if(i!=ans.size()-1)cout<<endl;
    // }

    return 0;
}