#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> st;
vector<lli> lazy;
// #define endl '\n'
const int inf  = 1000000007;
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
void propagate(lli v,lli SL,lli SR){
    if(!lazy[v])return ;
    // cout<<"HI "<<v<<" "<<SL<<" "<<SR<<endl;
    st[v] += lazy[v];
    if(SL!= SR){
        lazy[v*2]+=lazy[v];
        lazy[v*2+1]+=lazy[v];
    }
    lazy[v] = 0;
}

void build(vector<lli> &A,lli v,lli l,lli r){
    if(l== r)st[v] = A[l];
    else{
        lli m = (l+r)/2;
        build(A,v*2,l,m);
        build(A,v*2+1,m+1,r);
        st[v] = min(st[v*2],st[v*2+1]);
    }
}

void update(lli v,lli SL ,lli SR,lli l,lli r,lli val){
    propagate(v,SL,SR);
    // error(v,SL,SR,l,r)
    // cout<<endl;
    if(SL>SR || l>SR || r<SL)return ;
    if(SL>= l && SR<=r){
        lazy[v] +=val;
        propagate(v,SL,SR);  
        return ;
    }
    lli m = (SL+SR)/2;
    update(v*2,SL,m,l,r,val);
    update((v*2)+1,m+1,SR,l,r,val);
    st[v] = min(st[v*2],st[v*2+1]);
}

lli query(lli v,lli SL,lli SR,lli l,lli r){
    propagate(v,SL,SR);
    if(SL>SR || l>SR || r<SL)return inf;
    if(SL>= l && SR<=r)return st[v];
    lli m = (SL+SR)/2;
    return min(query(v*2,SL,m,l,r), query(v*2+1,m+1,SR,l,r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli n,m,a,b,c;
    cin>>n;
    st.resize(4*n);
    lazy.resize(4*n,0);
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    build(nums,1,0,n-1);
    // for(lli i = 0;i<8;i++)cout<<st[i]<<" ";
    // cout<<endl;
    // update(1,0,n -1,3,3,1);
    cin>>m;
    cin.ignore();
    for(lli i = 0;i<m;i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss>>a>>b;
        if(ss>>c){
            if(a<=b)
                update(1,0,n-1,a,b,c);
            else{
                update(1,0,n-1,0,b,c);
                // cout<<"HI"<<endl;
                // for(lli i = 0;i<8;i++)cout<<lazy[i]<<" ";
                // cout<<endl;
                // for(int i = 0;i<8;i++)cout<<st[i]<<" ";
                // cout<<endl;
                update(1,0,n-1,a,n-1,c);
            }
        }
        else{
            if(a<=b)
                cout<<query(1,0,n-1,a,b)<<endl;
            else 
                cout<<min(query(1,0,n-1,0,b),query(1,0,n-1,a,n-1))<<endl;
        }
       
    }
    return 0;
}