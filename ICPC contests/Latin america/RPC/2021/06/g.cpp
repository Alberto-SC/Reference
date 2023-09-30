#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<vector<int>> bit2D;
int n,m;
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

void print(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<sum2D(i,j,i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

signed main(){ 
    int k,c;
    cin>>n>>m>>k;
    bit2D.resize(n,vector<int>(m,0));
    vector<int> current(m);
    print();
    int turn = 0;
    vector<int> diagonals[n+m];
    for(int i = 0;i<n*m;i++){
        cin>>c;
        c--;
        int row = (n-current[c])-1;
        if(turn){|
            add2D(row,c,-1);
            int a = left1(row,c,0)
            int b = rigth1(row,c,0)
            int c = down1(row,c,0)
            int d = up1(row,c,0)
            int e = upleft1(row,c,0)
            int f = uprigth1(row,c,0)
            int g = downleft1(row,c,0)
            int h = downrigth1(row,c,0)
        }
        else{
            add2D(row,c,1);
        }    
        current[c]++;
        print();
        // cout<<sum2D(0,0)<<endl;
        // cout<<sum2D(0,1,3,3)<<endl;
        turn^=1;
    }
    return 0;
}  
