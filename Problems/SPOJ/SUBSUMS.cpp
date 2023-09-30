#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";
vector<long long> X;
vector<long long> Y;
void Subsums(vector<long long> A ,int n,int start ,vector<long long> &Z){
    for(int i = 0;i<(1<<n);i++){
        int sum = 0;
        for(int j = 0;j<n;j++)
            if(i&(1<<j))
                sum+=A[start+j];
        Z.push_back(sum);
    }
}

int main(){
    int n;
    long long A,B,ai;
    cin>>n>>A>>B;
    vector<long long> vec;
    for(int i= 0;i<n;i++){
        cin>>ai;
        vec.push_back(ai);
    }
    Subsums(vec,n/2,0,X);
    Subsums(vec,n-(n/2),n/2,Y);
    sort(Y.begin(),Y.end());
    long long ans = 0;
    vector<long long>::iterator low, high; 
    for(int i = 0;i<X.size();i++){
        low = lower_bound(Y.begin(), Y.end(), A - X[i]); 
        high = upper_bound(Y.begin(), Y.end(), B - X[i]); 
        ans += (high - low); 
    }
    cout<<ans;
    return 0;
}