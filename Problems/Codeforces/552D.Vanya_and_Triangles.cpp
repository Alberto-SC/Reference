#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define x first
#define y second
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    for(auto &[a,b]:points)cin>>a>>b;
    map<pair<pair<int,int>,pair<int,int>>,int> M;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i == j)continue;
            int num = (points[i].y-points[j].y);
            int dem = (points[i].x-points[j].x);
            int gcd = __gcd(dem,num);
            dem/=gcd;
            num/=gcd;
            M[{{points[i].x,points[i].y},{num,dem}}]++;
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int num = (points[i].y-points[j].y);
            int dem = (points[i].x-points[j].x);
            int gcd = __gcd(dem,num);
            dem/=gcd;
            num/=gcd;
            ans+=n-1-(M[{{points[i].x,points[i].y},{num,dem}}]);
        }
    }
    cout<<ans/3<<endl;
    return 0;
}