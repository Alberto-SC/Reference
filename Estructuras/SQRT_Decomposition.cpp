// FIND de fist and last ocurrence of x in an array with lazy updates
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



const lli inf = 1000000000;
struct block{
    int l,r;
    int size;
    vector<pair<lli,lli>>A;
    lli plus = 0;
    block(int _l,int _r,int _size): l(_l), r(_r),size(_size){A.resize(size,{-1,-1});}
    void st(){
        sort(A.begin(),A.end());
    }
    void add(int a,int b,lli v){
        if(a>b || b<l ||a>r)return;
        if(a<l)a = l;
        if(b>r)b = r;
        // error(l,r,a,b)
        if(a == l&& b == r){plus+=v;return; }
        for(int i = 0;i<size;i++)
            if(A[i].y>=a && A[i].y<=b)A[i].first+=v;
        st();
    }
    pair<lli,lli> find(lli z){
        z-=plus;
        int index = lower_bound(A.begin(),A.end(),make_pair(z,-inf))-A.begin();
        if(A[index].x!= z)return{inf,-1};
        int index2 = lower_bound(A.begin(),A.end(),make_pair(z+1,-inf))-A.begin();
        index2--;
        // error(index,index2)
        return {A[index].second,A[index2].second};
    }
};

int main(){
    int n,m,t,v,l,r,z;
    cin>>n>>m;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int raiz = ceil(sqrt(n*1.0));
    vector<block> bloques(raiz,block(0,0,0));
    vector<vector<pair<int,int>>> sq(raiz);
    for(int i = 0;i<raiz;i++){
        bloques[i] = block(i*raiz,((i*raiz)+raiz)-1,raiz);
        for(int j = 0;j<raiz;j++){
            if(i*raiz+j<n)
                bloques[i].A[j] = {nums[(i*raiz)+j],(i*raiz)+j};
        }
        bloques[i].st();
    }
    for(int i = 0;i<m;i++){
        cin>>t;
        if(t ==1){
            cin>>l>>r>>v;
            l--;
            r--;
            for(int i = 0;i<raiz;i++)
                bloques[i].add(l,r,v);
            
        }
        else{
            cin>>z;
            lli mn = n+2,mx = -1;
            for(int j = 0;j<raiz;j++){
                auto c = bloques[j].find(z);
                mn = min(c.x,mn);
                mx = max(c.y,mx);
                // error(c.x,c.y);
            }
            // error(mx,mn)
            if(mx == -1)cout<<-1<<endl;
            else cout<<mx-mn<<endl;
        }
    }
    // for(int i = 0;i<raiz;i++){printP(bloques[i].A);cout<<endl;}
    return 0;
}