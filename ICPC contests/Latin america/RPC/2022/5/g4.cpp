#include <bits/stdc++.h>
 
#define endl '\n'
#define lli long long int
#define ld long double
#define forn(i,n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define fastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())

using namespace std;

typedef vector<lli> VLL;
typedef vector<int> VI;


#define i128 __int128

i128 powerMod(i128 a, i128 b, i128 mod) {
    i128 res = 1; 
    while(b) {
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}


//22
bool isPrimeMillerRabin(lli n)
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if( ~n & 1) return false;
    lli d = n-1, s = 0; //n-1 = 2^s*k
    for(;(~d&1); d>>=1, s++); //d = k
    for(lli a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if(n == a) return true;
        i128 residuo = powerMod(a, d, n);
        if(residuo == 1 or residuo == n-1) continue;
        lli x = s;
        while(--x)
        {
            residuo = residuo * residuo % n;
            if(residuo == n-1) break;
        }
        if(x==0) return false;
    }
    return true; //Probability = 1 - (1/4)^size_of(vector_a)
}

bool isPal(lli number) {
    // cout << number << endl;
    string s_number = to_string(number);
    string s_number2 = to_string(number);
    reverse(all(s_number2));
    return s_number == s_number2;
}


vector<lli> pal, palPrimes;
const lli maxN = 12;
void getAllPal() {

    for(int d0 = 0; d0 <= 9; d0++) {
        for(int d1 = 0; d1 <= 9; d1++) {
            for(int d2 = 0; d2 <= 9; d2++) {
                for(int d3 = 0; d3 <= 9; d3++) {
                    for(int d4 = 0; d4 <= 9; d4++) {
                        for(int d5 = 0; d5 <= 9; d5++) {
                            
                            string s_number = to_string(d0) + to_string(d1) + to_string(d2) + to_string(d3) + to_string(d4) + to_string(d5);

                            if(d4 || d3 || d2 || d1 || d0) s_number += to_string(d4);
                            if(d3 || d2 || d1 || d0) s_number += to_string(d3);
                            if(d2 || d1 || d0) s_number += to_string(d2);
                            if(d1  || d0) s_number += to_string(d1);
                            if(d0) s_number += to_string(d0);
                                            

                            lli number = stoll(s_number);
                            pal.push_back(number);
                        }
                    }
                }
            }
        }
    }


}


lli g(lli idx) {
    lli ans = 0;
    if(idx >= 11) ans++;

    for(auto x: palPrimes) {
        if(x <= idx) ans++;
    }

    cout << idx << " " << ans << " ";
    cout << endl;

    return ans;
}

lli f(lli idx) {
    lli ans = (--upper_bound(all(palPrimes), idx) - palPrimes.begin()) + 1;

    if(idx >= 11) ans++;

    // cout << idx << " " << ans << " ";
    // cout << endl;
    
    return ans;
}



int main () {
	//fastIO();

    // time_t begin = clock();
    
    getAllPal();
    // cout << SZ(pal) << endl;

    for(auto x: pal) {
        
        if(isPrimeMillerRabin(x)) {
            palPrimes.push_back(x);
        }
    }

    // cout << (double)(clock() - begin)/CLOCKS_PER_SEC << endl;

    

    lli L, H; cin>>L>>H;


    cout << f(H) - f(L-1) << endl;
    // cout << g(H) - g(L-1) << endl;

	return 0;
}
