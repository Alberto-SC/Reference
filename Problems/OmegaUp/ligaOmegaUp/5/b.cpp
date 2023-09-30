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

bool comp(pair<int,int> A,pair<int,int> B){
    if(A.second == B.second)return A.first>B.first;
    return A.second<B.second;
}

vector<int> wt;
vector<int> val;
int n,f,ai;
int knapSack(int W) { 
    int i, w; 
    int K[n+1][W+1]; 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i==0 || w==0) 
                K[i][w] = 0; 
            else if (wt[i-1] <= w) 
                    K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
            else
                    K[i][w] = K[i-1][w]; 
        } 
    } 
    return K[n][W]; 
} 
int main(){
    while(cin>>n){
        wt.assign(n,0);
        val.assign(n,0);
    	for(int i = 0;i<n;i++)
            cin>>val[i]>>wt[i];
        cin>>f;
        vector<int> fr(f);
        int ans = 0;
        for(int i = 0;i<f;i++){
            cin>>ai;
            ans+=knapSack(ai);
        }
        cout<<ans<<endl;
    }
    return 0;
}  