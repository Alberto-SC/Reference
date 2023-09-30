#include <bits/stdc++.h>
 
using namespace std;
const int N = 20000043;
int t[N];
int nxt[N][2];
 
int szt = 1;
 
int new_vertex(){
	nxt[szt][0] = nxt[szt][1] = -1;
	t[szt] = 0;
	return szt++;
}
 
int go(int x, int y){
	if (nxt[x][y] == -1)
		nxt[x][y] = new_vertex();
	return nxt[x][y];
}
 
void add_number(int x, int val){
	int cur = 0;
	t[cur] += val;
	for(int i = 29; i >= 0; i--){
		int z = ((x >> i) & 1);
		cur = go(cur, z);
		t[cur] += val;
	}
}
 
int descend(int x){
	int ans = 0;
	int cur = 0;
	for(int i = 29; i >= 0; i--){
		int z = ((x >> i) & 1);
		int k;
		if(nxt[cur][z] != -1 && t[nxt[cur][z]] > 0)
			k = z;
		else
			k = z ^ 1;
		ans ^= (k << i);
		cur = go(cur, k);
	}
	return ans;
}
int n;
 
const int M = 300043;

int a[M];
int p[M];
 
 
 
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> p(n);
    nxt[0][0] = nxt[0][1] = -1;
    for(auto &c:a)cin>>c;
    for(auto &c:p)cin>>c;
	for(auto c:p) add_number(c,1);
	for(int i = 0;i<n;i++){
		int z = descend(a[i]);
		cout<<a[i]^z<<" ";
		add_number(z, -1);				
	}
	return 0;

}