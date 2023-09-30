#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

map<int,int> facts;
void prime_factors(int n) {
    while (n%2==0){
        facts[2]++;
        n /= 2;
    }
    for (int d=3;d*d<=n;d+=2) {
        while (n%d==0) {
            facts[d]++;
            n /= d;
        }
    }
    if (n>1)
        facts[n]++;

}

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1) x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}

int main(){
	int t= 1,k,x;
    cin>>t;
    while(t--){
        cin>>k>>x;
        facts.clear();
        prime_factors(x);
        int sum = 0;
        vector<int> teams(k);
        // cout<<"HI"<<endl;
        if(facts.size()>k){
            int cont = facts.size()-(k-1);
            cout<<cont<<endl;
            int x = 1;
            int y = 1;
            vector<int> pot;
            for(auto c:facts){
                pot.push_back(bin_pow(c.first,c.second));                    
            }
            for(int i = 0;i<cont;i++)
                y*=pot[i];
            sum+=y;
            teams[0] = y;
            int l = 1;
            for(int i = cont;i<pot.size();i++)
                sum+=pot[i],teams[l++] = pot[i];
        }
        else{
            int l  = 0;
            for(auto c:facts){
                sum+=bin_pow(c.first,c.second);
                teams[l++] = bin_pow(c.first,c.second);
            }
            for(int i= facts.size();i<k;i++)
                teams[i] = 1;
            
            sum+=k-facts.size();
        }
        // for(auto c:teams)cout<<c<<" ";
        // cout<<endl;
        for(int i = 1;i<=x;i++){
            int cont = 0;
            for(int j = 0;j<k;j++){
                if(i%teams[j] == 0)cont++;
            }
            // cout<<i<<" "<<cont<<endl;
            if(cont == k){ 
                if(x == i)
                    cout<<"Good"<<endl;
                else 
                    cout<<"Bad________________________HSDAUSDGHAIDJSIUHGDSUHDJSIJDISJ"<<endl;
                break;
            }
        }
        // cout<<sum<<endl;
    }
    return 0;
}  

