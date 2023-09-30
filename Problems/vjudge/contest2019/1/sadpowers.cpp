#include<iostream>
#include<bits/stdc++.h>
// iteration and input/output stream
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define printarr(x) rep(i,0,x.size()) cout<<x[i]<<" "; cout<<endl;

#define si(x) int x; scanf("%d", &x)
#define sll(x) ll x; scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pll(x) printf("%lld", x)
#define nl prinf("\n")
#define tr(cont,it) \
for(decltype(cont.begin()) it = cont.begin(); it!= cont.end() ; it++)

#define tc() int tcase; cin >> tcase ; rep(tc,1,tcase+1)
//STL shortcuts
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define F first
#define S second
#define MP make_pair

// Error detection
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

using namespace std;

typedef long long int ll; // 64 bit integer
typedef unsigned long long int  ull; // 64 bit unsigned integer
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

inline void smax(int &x , int y) { x = max(x , y) ; }
inline void smin(int &x , int y) { x = min(x , y) ; }

#define MOD 1000000007
#define inf 4000000000000000000LL
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);

ll gcd(ll a,ll b){ return ((b==0)? a:gcd(b,a%b) ); }
#define int ll

ll floorSqrt(ll x)
{
    // Base cases
    if (x == 0 || x == 1)
       return x;

    // Do Binary Search for floor(sqrt(x))
    ll start = 1, en = sqrt(x)+10, ans;
    while (start <= en)
    {
        ll mid = (start + en) / 2;

        // If x is a perfect square
        if (mid*mid == x)
            return mid;

        //trace3(mid*mid,mid,x);
        // Since we need floor, we update answer when mid*mid is
        // smaller than x, and move closer to sqrt(x)
        if (mid*mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid is greater than x
            en = mid-1;
    }
    return ans;
}

int32_t main()
{
    SYNC

    vector<ll> all;
    set<ll> tmp;
    for(ll i=2;i<=1000000;i++)
    {
        ll val = i*i*i;
        ld ch = i*i*i;
        while(ch < inf)
        {
            ll x = floorSqrt(val);

            if(val != x*x)
            tmp.insert(val);

            ch*= i;
            val*=i;
            //trace1(val);
        }
    }
    tr(tmp,it)
    all.pb(*it);

    tc()
    {
        ll l,r;
        cin>>l>>r;
        ll b1 = floorSqrt(l);
        ll b2 = floorSqrt(r);
        if(b1*b1 < l)
            b1++;
        //trace2(b1,b2);
        ll ans = b2-b1+1;
        ans += (upper_bound(all.begin(),all.end(),r) - upper_bound(all.begin(),all.end(),l-1));
        cout<<ans<<endl;
    }
}