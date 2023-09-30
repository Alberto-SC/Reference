#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(2*n);
    for(auto &x: nums)cin>>x;
    for(auto c: nums)cout<<c<<" ";
    stack<int>s;
    for(int i = (2*n)-1;i>=0;i--)
        s.push(nums[i]);
    stack<int>aux;
    int moves= 0,pairs = 0;
    while(pairs != n){
        if(!s.empty()){
            cout<<"Hello"<<endl;
            while(s.top()!= aux.top()){
                int e = s.top();
                s.pop();
                aux.push(e);
                moves++;
            }
        }
        else if(!aux.empty()){
        while(s.top()!= aux.top()){
                int e = aux.top();
                aux.pop();
                s.push(e);
                moves++;
        }}
        else return cout<<"impossible"<<endl,0;
        if(aux.empty() && s.empty())return cout<<"impossible"<<endl,0;
        else{  moves++;pairs++;}
    }
    cout<<moves<<endl;
    return 0;
}