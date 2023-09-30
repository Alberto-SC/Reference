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
int lcm(int a,int b){
    return b*(a/__gcd(a,b));
}
lli sum(lli a,lli lc, lli mx){
    if(a<mx)return 0;
    lli ans = a;
    lli how = a/lc;
    if(how>1){
        ans-=((how-1)*mx);
        ans-=mx-1;
    }
    if(how==1){
        ans-=mx-1;
    }
    lli dif = a-(lc*how);
    // error(ans,dif)
    if(dif>=mx)ans-= mx-1;
    else ans-=dif+1;
    return ans;
}
int main(){
	int t,q;
    lli x,y,a,b,l,r;
	cin>>t;
    while(t--){
        cin>>a>>b>>q;
        int lc = lcm(a,b);
        for(int i = 0;i<q;i++){
            cin>>l>>r;
            if(r <max(a,b)){cout<<0<<endl;continue;}
            else{
                cout<<sum(r,lc,max(a,b))-sum(l-1,lc,max(a,b))<<" ";

            }
        }
        cout<<endl;
    }
    return 0;
}  