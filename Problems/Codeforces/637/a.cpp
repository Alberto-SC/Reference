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

int main(){
	int t,n,a,b,c,d;
	cin>>t;
    while(t--){
        cin>>n>>a>>b>>c>>d;
        int mn = (a-b)*n;
        int mx = (a+b)*n;
        int diff = (c-d)-mn;
        if(mx<c-d || mn > c+d){cout<<"No"<<endl;continue;}
        if(diff <=0 || (diff< ((a+b)-(a-b))*n)){cout<<"Yes"<<endl;continue;}
        diff = mx-(c+d);
        
        if(diff <=0 || (diff< ((a+b)-(a-b))*n))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}  