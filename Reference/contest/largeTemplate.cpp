
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A) for(auto c:A){print(c);}
#define x first
#define y second
#define printP(A)for(auto c:A)cout<<"("<<c.x<<","<<c.y<<")  ";cout<<endl;
#define printMP(A)for(auto c:A){printP(c);}
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
void Madd(int &res, int val) { if ((res += val) >= MOD) res -= MOD; }
void Mres(int &res, int val) { if ((res -= val)  <  0 ) res += MOD; }

//DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));\
i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


// Dont use #define int long long with this
//Orderded set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// ordered_set st;
// st.order_of_key();
// st.find_by_order();

//Multiset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//  For erase use: 
st.erase(st.find_by_order(st.order_of_key(x)));
// And for check if exisit use : 
int order = st.order_of_key(l);
int num = *st.find_by_order(order);
if(num == l){
	continue;
}


//Better hashmap 
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = lli(4e18 * acos(0)) | 71;
	lli operator()(lli x) const { return __builtin_bswap64(x*C); }
};s
gp_hash_table<lli,int,chash> h({},{},{},{},{1<<16});

// For CodeForces, or other places where hacking might be a problem:
struct chash { // To use most bits rather than just the lowest ones:
	const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};
__gnu_pbds::gp_hash_table<ll, int, chash> h({},{},{},{}, {1 << 16});


int main(){__
	int n;
	cin>>n;
	vector<int> nums(n);
	for(auto &c:nums)cin>>c;
	bool flag = true;
	cout << "NO\0YES\0" + 3 * flag << endl;
    return 0;
}  

