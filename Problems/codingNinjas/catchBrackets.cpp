#include<bits/stdc++.h>
using namespace std;

pair<int,int> dp[307][307][200];
int nxt[307][307][200];


char grid[307][307];

map<char,int> mp = {{'(',1},{')',-1}};


int n,m;
pair<int,int> solve(int row,int col,int cont){
	if(cont<0)return {-(1e9),0};
	if(row == 0 || grid[row][col]== '*'){
		if(cont != 0){
			return {-(1e9),0};
		}
        return {0,0};
	}

	pair<int,int> &x = dp[row][col][cont];
	if(x.first != -1)return x;

	pair<int,int> ans ;
	vector<pair<pair<int,int>,int>> v;
	if(col+1<m){
		int nCont = cont+mp[grid[row-1][col+1]];
		ans = solve(row-1,col+1,cont+mp[grid[row-1][col+1]]);
		ans.first += grid[row-1][col+1]== ')';
		ans.first += grid[row-1][col+1]== '(';
		v.push_back({{ans.first,nCont},+1});
	}

	if(col-1>=0){
		int nCont = cont+mp[grid[row-1][col-1]];
		ans = solve(row-1,col-1,cont+mp[grid[row-1][col-1]]);
		ans.first += grid[row-1][col-1]== ')';
		ans.first += grid[row-1][col-1]== '(';
		v.push_back({{ans.first,nCont},-1});
	}
	int nCont = cont+mp[grid[row-1][col]];
	ans = solve(row-1,col,cont+mp[grid[row-1][col]]);
	ans.first += grid[row-1][col]== ')';
	ans.first += grid[row-1][col]== '(';
	v.push_back({{ans.first,max(ans.second,nCont)},+0});

	sort(v.begin(),v.end(),[&](pair<pair<int,int>,int> a ,pair<pair<int,int>,int> b){
		return a.first>b.first;
	});


	nxt[row][col][cont] = v[0].second;

	return x = v[0].first; 
}

int main() {
    cin>>n>>m;
    int col = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='M')col = j;
            for(int l = 0;l<=n/2;l++){
                dp[i][j][l] = {-1,0};
            }
        }
    }

    auto x = solve(n-1,col,0);
    string ans = "";
    cout<<x.first<<endl;
    int cont = 0;
    for(int r = n-1;r>=0;r--){
        if(grid[r][col]=='*')break;
        if(grid[r][col]== ')' || grid[r][col]== '('){
            ans+=grid[r][col];
            if(ans.back()==')')cont--;
            else cont++;
        }

        col+=nxt[r][col][cont];

    }
    cout<<ans<<endl;
}