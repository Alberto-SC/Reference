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
    vector<lli> pre;
    for(int i = 0;i<=18;i++){
        for(int j = 1;j<=9;j++){
            lli num;
            string s = string(i,'0');
            s = to_string(j)+s;
            num = stoll(s);
            pre.push_back(num);
        }
    }
    // for(int i = 0;i<pre.size();i++)cout<<pre[i]<<" ";
    // cout<<endl;
	lli n;
	cin>>n;
    int index = lower_bound(pre.begin(),pre.end(),n)-pre.begin();
    if(n == pre[index])cout<<n<<endl;
    else {
        lli num1 = pre[index];
        lli num2 = pre[index-1];
        // cout<<abs(n-num1)<<" "<<abs(n-num2)<<endl;
        if(abs(n-num1)<=abs(n-num2))cout<<num1<<endl;
        else cout<<num2<<endl;
    }
    return 0;
}  