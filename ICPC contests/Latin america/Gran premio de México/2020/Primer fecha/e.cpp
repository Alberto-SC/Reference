#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int N = 10000000;
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
int main(){__
    int t = 1,n;
    string s;
    cin>>s;
    n = s.size();
    criba();
    lp[0] =-1;
    lli inf = 1e15;
    lli ans = inf;
    int max = pow(3,n);
    bool flag = false;
    for(int i = 0;i<=max;i++){
        int aux = i;
        vector<int> mask;
        while(aux){
            mask.push_back(aux%3);
            aux/=3;
        }    
        // cout<<i<<" ";
        reverse(mask.begin(),mask.end());
        string p1="",p2="",p3="";
        while(mask.size()<n){mask.push_back(0);}
        for(int i = 0;i<n;i++){
            if(mask[i] ==0)p1+=s[i];
            if(mask[i] ==1)p2+=s[i];
            if(mask[i] ==2)p3+=s[i];
        }
        sort(p1.begin(),p1.end());
        sort(p2.begin(),p2.end());
        sort(p3.begin(),p3.end());
        if(p1.size()== 0 || p2.size()==0 || p3.size()==0)continue;
        do{
            do{
                do{
                    lli np1=0,np2= 0,np3 =0;
                    if(p1[0] == '0'||p2[0]== '0' ||p3[0]== '0')continue;
                    np1 = stoll(p1);
                    np2 = stoll(p2);
                    np3 = stoll(p3);
                    if(lp[np1]!= np1 ||lp[np2]!= np2 ||lp[np3] !=np3)continue;
                    // cout<<p1<<" "<<p2<<" "<<p3<<endl;
                    // cout<<"Primes "<<np1<<" "<<np2<<" "<<np3<<endl;
                    ans = min(np1*np2*np3,ans);

                }while(next_permutation(p3.begin(),p3.end()));

            }while(next_permutation(p2.begin(),p2.end()));

        }while(next_permutation(p1.begin(),p1.end()));
    }
    if(ans == inf)
        cout<<"Bob lies"<<endl;
    else cout<<ans<<endl;
    return 0;
}      
