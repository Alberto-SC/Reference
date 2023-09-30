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

vector<int> b(2000007);
int can(int am){
	int C=0;
	for (int i=1;i<=200000;i++){
		C+=b[i]/am;
	}
	return C;
}
 
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> nums(n);
	for(auto &c:nums){cin>>c;b[c]++;}
    vector<int> ans;
    int l = 1,r = n;
    while(l<r){
        int m = l+r+1;
        m/=2;
        if(can(m)>=k)
            l = m;
        else r = m-1;
    }
    for(int i = 1;i<2000000;i++){
        for(int j = 0;j<b[i]/r;j++){
            if(ans.size()<k)
                ans.push_back(i);
        }
    }    
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}  