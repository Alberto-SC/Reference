/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: Create the factoradic representation of a permutation or recover a permutation from its factoradic representation
 * Time:  $(n \log n)$ 
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> bit;
int n;

int sum(int idx){
    int ans = 0;
    for(++idx;idx>0 ;idx-= idx&-idx)ans+=bit[idx];
    return ans;
}

void add(int idx,int val){
    for(++idx;idx<n;idx+= idx&-idx)bit[idx]+=val;
}
int bit_search(int s){
    int sum = 0;
    int pos = 0;
    for(int i = ceil(log2(n));i>=0;i--){
        if((pos+(1<<i))<n && (sum+bit[pos+(1<<i)])<s){
            sum+=bit[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos;
}

int main(){
    int x;
    cin>>n;
    vector<int> factoradicA(n);
    vector<int> factoradicB(n);
    bit.resize(n);
    for(int i = 0;i<n;i++)
        add(i,1);
    for(int i = 0;i<n;i++){
        cin>>x;
        factoradicA[i] = sum(x-1);
        add(x,-1);
    }
    bit.assign(n,0);
    for(int i = 0;i<n;i++)
        add(i,1);
    for(int i = 0;i<n;i++){
        cin>>x;
        factoradicB[i] = sum(x-1);
        add(x,-1);
    }
    vector<int> final(n);
    int carry= 0;
    for(int i = n-1;i>=0;i--){
        int fact = (n-1)-i;
        final[i] = (factoradicA[i]+factoradicB[i])+carry;
        if(final[i]>=fact+1){
            final[i]-=fact+1;
            carry = 1;
        }
        else carry = 0;
    }
    for(int i = 0;i<n;i++)add(i,1);
    for(int i = 0;i<n;i++){
        x = bit_search(final[i]+1);
        cout<<x<<" ";
        add(x,-1);
    }
    cout<<endl;

    return 0;
}