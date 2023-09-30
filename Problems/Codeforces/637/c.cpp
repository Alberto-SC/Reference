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
	int n,t;
	cin>>t;
    while(t--){
        cin>>n;
        map<int,int> mp;
        vector<int> nums(n);
        for(int i = 0;i<n;i++){cin>>nums[i];mp[nums[i]] =i;}
        int k = 1;
        vector<int> used(n+1,false);
        bool flag = true;
        while(k<n && flag){
            int j = mp[k++];
            used[j] = true;
            j++;
            while(j<n && !used[j]){
                if(nums[j] != nums[j-1]+1){flag = false;break;}
                used[j]= true;
                k++;
                j++;
                // cout<<"HOLA"<<endl;
            }
        }
        cout<<"No\0Yes\0"+ 3*flag<<endl;
    }
    return 0;
}  