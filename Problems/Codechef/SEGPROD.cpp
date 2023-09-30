#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAX_SIZE = 2 * 1000005;
const int MAX_LEVEL = 23;
int A[MAX_SIZE];
int N;
int maxLevel;
int P;
int st[MAX_LEVEL][MAX_SIZE];
void build(int L = 0, int R = N, int level = 0) {
    int M = (L + R) / 2;
    if (L + 1 == R) {
        st[level][M] = A[M] % P;
        return;
    }
    st[level][M] = A[M] % P;
    for (int i = M - 1; i >= L; i--)
        st[level][i] = (long long)A[i] * st[level][i + 1] % P;

    st[level][M + 1] = A[M + 1] % P;
    for (int i = M + 2; i < R; i++)
        st[level][i] = (long long)A[i] * st[level][i - 1] % P;
    build(L, M, level + 1);
    build(M, R, level + 1);
}

int query(int L, int R) {
    if (L == R)
        return A[L] % P;
    int k2 = __builtin_clz(L^R) ^ 31;
    int level = maxLevel - k2 - 1;
    int ans = st[level][L];
    if (R % (1 << k2))
        ans = (long long)ans * st[level][R] % P;
    return ans;
}
int main(){
    int t,q,n;
    cin>>t;
    while(t--){
        cin>>n>>P>>q;
        N = n;
        maxLevel = __builtin_clz(n) ^ 31;		// floor(log_2(n))
        if((1<<maxLevel) != n)
            N = 1<<++maxLevel;
        for(lli i = 0;i<n;i++)
            cin>>A[i];
        vector<int> b((q/64)+2);
        build();
        for(auto &c:b)cin>>c;
        int x = 0;
        int L = 0,R =0;
        for(lli i = 0;i<q;i++){
            if(i%64 == 0)
                L = (b[i>>6]+x)%n, R = (b[(i>>6)+1]+x)%n;
            else 
                (L += x) %= n, (R += x) %= n;
            if(L>R)swap(L,R);
            // cout<<L<<" "<<R<<endl;
            x = (query(L,R)+1)%P;
        }
        cout<<x<<endl;
    }        
    return 0;
}