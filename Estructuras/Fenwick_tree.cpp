#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A)for(auto c:A){print(c);}
vector<int> bit;
vector<vector<int>> bit2D;
int n,m;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
}
// ************This only can accept querys in a point*****************
void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

// Return sum over submatrix with corners (0,0), (x,y)
int sum2D(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit2D[i][j];
    return ret;
}
int sum2D(int x0,int y0,int x,int y){
    return sum2D(x,y)-sum2D(x,y0-1)-sum2D(x0-1,y)+sum2D(x0-1,y0-1);
}

void add2D(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < m; j = j | (j + 1))
            bit2D[i][j] += delta;
}

int main(){
    // ---------------------------------------------Test BIT----------------------------------------------------
    cin>>n;
    vector<int> nums(n);
    bit.resize(n);
    int i = 0;
    for(auto &c:nums){cin>>c;add(i++,c);}
    print(bit);
    cout<<sum(3,4);
    // ---------------------------------------------Test BIT2D---------------------------------------------------
    // cin>>m;
    // vector<vector<int>> matriz(n,vector<int> (m,0));
    // bit2D.resize(n,vector<int> (m,0));
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cin>>matriz[i][j];
    //         add2D(i,j,matriz[i][j]);
    //         // printM(bit2D);
    //     }
    // }
    // cout<<sum2D(0,0)<<endl;
    // cout<<sum2D(0,1,3,3)<<endl;
}