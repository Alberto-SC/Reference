#include <bits/stdc++.h>
using namespace std;
#define t second
#define x first
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
typedef long long int lli;
const int maxy = 1000007;
vector<int> bit(maxy,0);
int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx -= idx & -idx)res+=bit[idx];
    return res;
}
int sum(int a,int b){
    return sum(b)-sum(a-1);
}
void add(int idx,int value){
    for(++idx;idx<maxy;idx += idx & -idx)bit[idx]+=value;
}

bool comp (pair<pair<int,int>,pair<int,int>> A, pair<pair<int,int>,pair<int,int>>B){
    if(A.x.x==B.x.x)return A.t.t<B.t.t;
    return A.x.x < B.x.x;
}
int nextInt() {
    int x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x1,x2,y1,y2;
    n = nextInt();
    vector<pair< pair<int,int>,pair<int,int> > > lines;
    for(int i = 0;i<n;i++){
        x1 = nextInt();
        y1 = nextInt();
        x2 = nextInt();
        y2 = nextInt();
        y1++;
        y2++;
        if(y1>y2)swap(y1,y2);
        if(x1>x2)swap(x1,x2);
        if(y1==y2){
            lines.push_back({{x1,y1},{x1,1}});
            lines.push_back({{x2,y2},{x1,3}});
        }
        if(x1==x2)lines.push_back({{x1,y1},{y2,2}});
    }
    sort(lines.begin(),lines.end(),comp);
    lli ans = 0;
    for(int i = 0;i<lines.size();i++){
        if(lines[i].t.t == 1)add(lines[i].x.t,1);
        if(lines[i].t.t == 3)add(lines[i].x.t,-1);
        if(lines[i].t.t == 2)
           ans+= sum(lines[i].x.t,lines[i].t.x);
    }
    cout<<ans<<endl;
    return 0;
}