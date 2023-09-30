#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A) for(auto c:A){print(c);}
#define x first
#define y second
#define printP(A)for(auto c:A)cout<<"("<<c.x<<","<<c.y<<")  ";cout<<endl;
#define printMP(A)for(auto c:A){printP(c);}
#define endl '\n'
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define ALL(A) A.begin(),A.end()
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
typedef long long int lli;
const int inf = 1000000007;
vector<lli> st(400007);

lli query(lli v,lli sl,lli sr,lli l,lli r){
    if(r<sl || l>sr)return inf;
    if(sl>=l && sr<=r)return st[v];
    lli m = (sl+sr)/2;
    return min(query(v*2,sl,m,l,r),query(v*2+1,m+1,sr,l,r));
}
void update(lli v,lli sl,lli sr,lli pos,lli val){
    if(sl == sr)st[v] = val;
    else{
        lli m = (sl+sr)/2;
        if(pos<=m)
            update(v*2,sl,m,pos,val);
        else    
            update(v*2+1,m+1,sr,pos,val);
        st[v] = min(st[v*2],st[v*2+1]);
    }
}
bool comp(pair<lli,lli>A,pair<lli,lli> B){
    return B.y<A.y;
}
int main(){
    lli n,m,a,b;
    cin>>n;
    vector<pair<lli,lli>> slots(n);
    vector<pair<lli,lli>> slots2(n);
    for(lli i = 0;i<100005;i++){
        update(1,0,100000,i,inf);
    }
    for(lli i = 0;i<n;i++){
        cin>>a>>b;
        slots2[i] = {b,i+1};
        lli last = query(1,0,100000,a,100000);
        if(last != inf)continue;
        update(1,0,100000,a,i+1);
    }
    cin>>m;
    vector<pair<lli,lli>>    coins(m);
    for(lli i = 0;i<m;i++){
        cin>>a>>b;
        coins[i] = {a,b};
    }

    sort(slots2.begin(),slots2.end());
    sort(coins.begin(),coins.end(),comp);
    reverse(coins.begin(),coins.end());
    lli ans=0;
    lli j = 0;
    for(lli i = 0;i<m;i++){
        while(j<n && slots2[j].x<=c  oins[i].y){j++;}
        if(j == n){
            ans += max(slots2[j].y,query(1,0,100000,coins[i].first,100000));
        }
        else{
            ans +=max(slots2[j-1].y,query(1,0,100000,coins[i].first,100000));
        }
    }
    cout<<ans<<endl;
}