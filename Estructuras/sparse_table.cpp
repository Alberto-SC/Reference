#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
int ST[maxn][25];
int lg[maxn];


// NO TESTED
void build(vector<int> &A){
	lg[1] = 0;
    for(int i = 2;i<maxn;i++)
		lg[i] = lg[i/2]+1;
	for(int i = 0;i<n;i++) 
        ST[i][0] = A[i];
    for(int j = 1;j<25;j++)
		for(int i=0; i+(1<<j)<=n; i++)
			ST[i][j] = __gcd(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
}
 
int query(int l, int r){
	int j = lg[r-l+1];
	return __gcd(ST[l][j],ST[r-(1<<j)+1][j]);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    build(nums);
    cout<<query(1,3);
    return 0;
}
 