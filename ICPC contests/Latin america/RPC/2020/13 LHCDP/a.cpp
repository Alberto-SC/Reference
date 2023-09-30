
#include <bits/stdtr1c++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;
const int N = 1000007;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

lli fs,fp,fc,ft,n;

bool check(lli s,lli p,lli c,lli n){
    int i,cont;
    for(i = s,cont = 0;cont<ft;cont++,i++){
        if(i>n)i = 1;
        if(lp[i]== i)
            p++;
        else 
            c--;
        if(c ==0)c = n;
        if(p>n)p = 1;  
        
    }
    if(i>n)i = 1;
    return fs==i && p == fp && c == fc;
}

void menor(long long s,long long p,long long c,long long t,long long n,lli primes,lli composite){
    (s-=t)%=n;
    if(s<=0)s+=n;
    for(int i= s,cont = 0;cont<t;cont++,i++){
        if(i>n)i = 1;
        if(lp[i] == i){
            primes++;
            if(p == 0)p = n;
        }
        else{
            composite++;
            if(c>n)c = 1;
        }
    }
    (p-=primes)%=n;
    if(p<=0)p+=n;
    c+=composite;
    if(c>n)c%=n;
    if(c == 0)c = n;
    cout<<s<<" "<<p<<" "<<c<<endl;
    // if(check(s,p,c,n))cout<<"CORRECTO"<<endl;
    // else cout<<"Incorrecto"<<endl;
}

int main(){__
    lli t,n,s,p,c;
    cin>>n>>t;
    cin>>s>>p>>c;
    lli primes =0;
    criba();
    for(int i= 2;i<=n;i++)
        if(lp[i]== i)primes++;
    
    fs = s,fp = p,fc = c;
    ft = t;  
    // cout<<lp[15]<<endl;
    if(t<n) 
        menor(s,p,c,t,n,0,0);
    else{
        lli x = t/n;
        lli primes2 = primes*x;
        lli composite = ((n*x)-(primes2));
        t = t%n;
        menor(s,p,c,t,n,primes2,composite);
    }
    
    return 0;
}