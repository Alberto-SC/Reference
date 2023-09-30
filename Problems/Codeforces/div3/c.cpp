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
	int n;
	cin>>n;
	vector<lli> nums(n);
    lli sum = 0;
	for(auto &c:nums){cin>>c;sum+=c;}
    // sum = accumulate(nums.begin(),nums.end(),0ll);
    vector<pair<lli,int>>copy(n);
    for(int i = 0;i<n;i++){
        copy[i] = {nums[i],i};
    }
    sort(ALL(copy));
    set<int> ans;
    for(int i = 0;i<n;i++){
        lli z = sum-nums[i];
        z = z-nums[i];
        if(z == 0)continue;
        int index = lower_bound(copy.begin(),copy.end(),make_pair(z,-100))-copy.begin();
        int index2 = lower_bound(copy.begin(),copy.end(),make_pair(z+1,-100))-copy.begin();
        if(copy[index].y ==i)continue;
        if(copy[index].x == z){for(int i = index;i<index2;i++)ans.insert(copy[i].y+1);}
    
    }
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}  