#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    vector<int> b(n,0);
    vector<int> array2(n,0);
    map<int,int> m;
    int cont = 0;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        if(m.find(nums[i])== m.end()){
            m[nums[i]] = cont;
            cont++;
        }
    }
    for(int i = 0;i<n;i++)
        b[m[nums[i]]]++;
    for(int i = 0;i<n;i++){
        array2[i] = b[m[nums[i]]];
    }
    for(auto c:array2)cout<<c<<" ";
    cout<<endl;
    int count = 0;
    for(int i = n-1;i>=0;i--){
        if(array2[i] ==1)count++;
        else break;
    }
    cout<<count<<endl;
    cout<<n-(count+1)<<endl;
}