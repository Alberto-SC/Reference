#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int mod_pow(int a,int b,int mod){
    int x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

int gcd(int a,int b,int &x,int &y){
	if(b==0) {x = 1; y = 0; return a;}
	int r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}

int inverse(int a, int m){
	int x, y ;
    return mod_pow(a,m-2,m);
}

int CRT(vector<int> nums,vector<int> rem) { 
    int prod = 1; 
    for (int i = 0; i < nums.size(); i++) 
        prod *= nums[i];   
    int result = 0;   
    for (int i = 0; i < nums.size(); i++) { 
        int pp = prod / nums[i]; 
        result += rem[i] * inverse(pp, nums[i]) * pp; 
    } 
    return result % prod; 
} 

signed main(){__
    vector<int> primes;
    for(int i= 2;i<=100;i++){
        bool flag = true;
        for(int d = 2;d*d<=i;d++){
            if (i%d ==0){
                flag = false;
            }
        }
        if(flag)
            primes.push_back(i);
    }
    primes[0] = 4;
    primes[1] = 9;
    int last = 1;
    vector<int> v;
    int id = 0;
    while(1){
        if(last+primes[id]>19){
            break;
        }

        int x= last+1;
        for(int i=0;i<primes[id]-1;i++){
            v.push_back(x);
            x++;
        }
        v.push_back(last);
        last+=primes[id];
        id++;
    }

    int n = v.size(),m = 3;
    cout<<n<<endl;
    for(auto c:v){
        cout<<c<<" ";
    }
    cout<<endl;

    vector<int> b(n+1);
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    
    vector<int> md(m);
    int idx = 1;
    for(int i = 0;i<m;i++){
        if(b[idx]== idx)
            md[i] = primes[i]-1;
        else
            md[i] = b[idx]-idx-1;
        idx+=primes[i];
    }
    // for(int i = 0;i<m;i++){
    //     cout<<primes[i]<<" "<<md[i]<<endl;
    // }

    primes.resize(m);
    cout<<CRT(primes,md)<<endl;
    return 0;
}