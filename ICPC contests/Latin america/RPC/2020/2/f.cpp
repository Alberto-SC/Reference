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
	lli n,k;
	cin>>n>>k;
	vector<lli> nums(n);
	for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    int ans=0;
    for (int i=0,j=n-1; i<=j;)
        if (i==j or nums[i]+nums[j]>k)
            ++ans,--j;
        else
            ++ans,--j,++i;

    cout<<ans<<endl;
    return 0;
}  