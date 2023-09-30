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
    string n;
	cin>>n;
    if(n.size()==1){
        int i = 0;
        for(i = stoi(n);i<=100;i++){
            int x = (3*i*i)+i;
            x/=2;
            // cout<<x<<endl;
            if((x%100)%4 == 0)break;
        }
        cout<<i<<endl;
        return 0;
    }
    string s = n.substr(n.size()-2),ans;
    int i;
    int num  = stoi(s);
    if(num== 0)num++;
    // cout<<num<<endl;
    for(i = num;i<1000;i++){
        int x = (3*i*i)+i;
        x/=2;
        // cout<<x<<endl;
        if((x%100)%4 == 0)break;
    }
    if(num>=10)
    ans = n.substr(0,n.size()-2);
    else if(num<10 && i>=10)ans = n.substr(0,n.size()-2);
    else{ans = n.substr(0,n.size()-1);}
    
    ans+= to_string(i);
    cout<<ans<<endl;
    return 0;
}  