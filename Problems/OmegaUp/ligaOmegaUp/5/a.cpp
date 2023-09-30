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
vector<lli> lim(2);
vector<lli> ac(2);
lli sum(lli idx){
    lli ans; 
    int block = lower_bound(lim.begin(),lim.end(),idx)-lim.begin();
    // cout<<block<<endl;
    // cout<<block<<" "<<lim[block]<<endl;
    if(idx == lim[block])
        ans = ac[block];
    else if(idx == lim[--block]+1){
        ans = ac[block]+(1<<(block));
    }
    else{
        ans = ac[block]+(1<<(block));
        ans+=sum(idx-(lim[block]+1));
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
    lli l,r;
	cin>>n;
    lim[0] = 0;
    lim[1] = 1;
    ac[0] = 0;
    ac[1] = 1;
    for(int i = 2;lim[lim.size()-1]<10000000000000002;i++)
        lim.push_back((lim[i-1]*2)+1); 
    for(int i = 2;i<lim.size();i++){
        ac.push_back((ac[i-1]*2)+(1ll<<i-1));
    }
    for(int i = 0;i<n;i++){
        cin>>l>>r;
        cout<<sum(r)-sum(l-1)<<endl;

    }

    return 0;
}  