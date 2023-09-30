#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));\
i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
vector<pair<int,int>> stmn;
vector<pair<int,int>> stmx;
#define x first
#define y second
const int minf = -1000000007;
#define printP(A)for(auto c:A)cout<<"("<<c.x<<","<<c.y<<")  ";cout<<endl;
const int inf = 1000000007;
pair<int,int> min(pair<int,int> A,pair<int,int>B){
    if(A.first<B.first)return A;
    else return B;
}
pair<int,int> max(pair<int,int> A,pair<int,int>B){
    if(A.first>B.first)return A;
    else return B;
}
void buildmin(vector<pair<int,int>> &A,int v,int l ,int r){
    if(l ==r)stmn[v] = A[l];
    else {
        int m = (l+r)/2;
        buildmin(A,v*2,l,m);
        buildmin(A,v*2+1,m+1,r);
        stmn[v] = min(stmn[v*2],stmn[(v*2)+1]);
    }
}

pair<int,int> querymin(int v,int sl,int sr,int l,int r){
    if(l>r)return {inf,-1};
    if(l == sl && r == sr)return stmn[v];
    int m = (sl+sr)/2;
    return min(querymin(v*2,sl,m,l,min(m,r)),
    querymin(v*2+1,m+1,sr,max(m+1,l),r));
}
void buildmax(vector<pair<int,int>> &A, int v,int l ,int r){
    if(l==r)stmx[v] = A[l];
    else{
        int m = (l+r)/2;
        buildmax(A,v*2,l,m);
        buildmax(A,v*2+1,m+1,r);
        stmx[v] = max(stmx[v*2],stmx[v*2+1]);
    }
}
pair<int,int> querymax(int v,int SL,int SR,int l ,int r){
    if(l>r)return {minf,-1};
    if(l == SL && r == SR)return stmx[v];
    int m = (SL+SR)/2;
    return max(querymax(v*2,SL,m,l,min(r,m)) ,querymax(v*2+1,m+1,SR,max(l,m+1),r));
}
int main(){
    	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    int n,q,l,r,x;
    cin>>n>>q;
    stmn.resize(4*n);
    stmx.resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<pair<int,int>> num(n);
    for(int i =0;i<n;i++){
        num[i] = {nums[i],i+1};
    }
    buildmin(num,1,0,n-1);
    buildmax(num,1,0,n-1);
    // auto d = querymin(1,0,n-1,1,6);
    // cout<<d.first<<" "<<d.second<<endl;
    for(int i = 0;i<q;i++){
        cin>>l>>r>>x;
        l--;
        r--;
        pair<int,int> mn = querymin(1,0,n-1,l,r);
        pair<int,int> mx = querymax(1,0,n-1,l,r);
        // error(mn.x,mn.y,mx.x,mx.y)
        if(mn.first == mx.first ){if(mx.first == x)cout<<-1<<endl; else cout<<mx.second<<endl;}
        else if(x == mn.first)cout<<mx.second<<endl;
        else if(x == mx.first)cout<<mn.second<<endl;
        else cout<<mx.second<<endl;
    }

    return 0;
}