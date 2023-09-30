#include <bits/stdc++.h> 
using namespace std; 
#define MAX 200010 
long long int lookup[MAX][100]; 
vector<long long int> spf(1000020);
long long m = 1000000007;
void sieve(){
    spf[1] = 1;
    for (int i=2; i<1000000; i++)
        spf[i] = i;
    for (int i=4; i<1000000; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<1000000; i++){
        if (spf[i] == i){
            for (int j=i*i; j<1000000; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vector<long long int> getFactorization(long long int x){
    vector<long long int> ret;
    while (x != 1){
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    for(int i = 0;i<ret.size();i++)
    //cout<<endl;
    return ret;
}

void buildSparseTable(long long int arr[], int n) { 
    for (int i = 0; i < n; i++) 
        lookup[i][0] = arr[i]; 
    for (int j = 1; (1 << j) <= n; j++) { 
        for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
                vector <long long int> a1 = getFactorization(lookup[i][j-1]);
                vector <long long int> a2 = getFactorization(lookup[i + (1 << (j - 1))][j - 1]);
                long long aa;
                aa = (lookup[i][j - 1]%m) * (lookup[i + (1 << (j - 1))][j - 1])%m;
                for(int k = 0;k<a1.size();k++){
                    //cout<<" "<<a1[i];
                    aa*= (1-(1/a1[i]))%m;
                }
                for(int k = 0;k<a2.size();k++){
                    //cout<<" "<<a2[i];
                    aa*= (1-(1/a2[i]))%m;
                }
                //cout<<endl;
                lookup[i][j] = aa%m;
        } 
    } 
} 
int query(int L, int R) { 
    int j = (int)log2(R - L + 1); 
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j]) 
        return lookup[L][j]; 
    else
        return lookup[R - (1 << j) + 1][j]; 
} 
  
int main() { 
    int n,q,i,r;
    cin>>n;
    sieve();
    long long int a[n];
    for(int j = 0;j<n;j++){
        cin>>a[j];
    }
    buildSparseTable(a, n); 
    cin>>q;
    for(int j = 0;i<q;i++){
        cin>>i>>r;
        cout<<query(i-1, r-1)<<endl; 
    }
 
    return 0; 
} 