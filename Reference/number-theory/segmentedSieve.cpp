#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 

/**
   * Description: Segmented sieve , get primes in range[L,R] with complexity O(max(sqrt(R)log(sqrt(R)),R-L)) ??? ;
    Also is one of the fastest sieve get all primes in range [1-n] with n = 1e9 in 8.62s and for 
    n = 1e8 in 0.76s 
    [TESTED:]
        [SPOJ: PRIME1 - Prime Generator]

*/
vector<int> PrimesInRange;
void calcPrimes(int l ,int r) {
    auto sum = l<=2?2:0;
    if(l<=2)PrimesInRange.push_back(2);
    int cnt = 1;
 
    const int S = round(sqrt(r));
    vector<char> sieve(S + 1, true);
    vector<array<int, 2>> cp;
    for (int i = 3; i <= S; i += 2) {
        if (!sieve[i])
            continue;
        cp.push_back({i, (i * i - 1) / 2});
        for (int j = i * i; j <= S; j += 2 * i){
            sieve[j] = false;
        }
    }
    vector<char> block(S);
    int high = (r - 1) / 2;
    int x = l/S;
    int L = (x/2)*S;
    for(auto &i:cp){
        int p = i[0],idx = i[1];
        if(idx>L){
            i[1]-=L;
        }
        else{
            int X = (L-idx)/p;
            if((L-idx)%p)X++;
            if(X>=1 && idx<=L)
                i[1] = (idx+(p*X))-L;
        }
    }
    for (int low =(x/2)*S; low <= high; low += S) {
        fill(block.begin(), block.end(), true);
        for (auto &i : cp) {
            int p = i[0], idx = i[1];
            for (; idx < S; idx += p){
                block[idx] = false;
            }
            i[1] = idx - S;
        }
        if (low == 0)
            block[0] = false;
        for (int i = 0; i < S && low + i <= high; i++){
            if (block[i] && (((low+i)*2)+1)>=l){
                // push the primes here if needed 
                ++cnt, sum += (low + i) * 2 + 1;
            }
        }
    };
	// cout << "sum = " << sum << endl;
	// cout << "cnt = " << cnt << endl;
}
 

signed main(){__
    int l,r,t,id = 1;
    cin>>t;
    while(t--){ 
        if(id>1)cout<<endl;
        PrimesInRange.clear();
        cin>>l>>r;
        calcPrimes(l,r);
        // for(auto c:primes)
        //     cout<<c<<endl;
        id++;
    }
	return 0;
}