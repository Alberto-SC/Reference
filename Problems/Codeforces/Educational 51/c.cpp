#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> buck(101,0);
    for(auto &c:nums)cin>>c;
    for(auto c:nums)buck[c]++;
    int count = 0;
    for(int i = 1;i<=100;i++)if(buck[i] == 1)count++;
    vector<char> ans(n,'A');
    bool flag = true;
    if(count%2 == 0){
        count/=2;
        int aux = 0;
        int i = 0;
        while(aux<count){
            if(buck[nums[i]]== 1){
                ans[i] = 'B';
                aux++;
            }
            i++;
        }
    }
    else {
        int x;
        for(x = 1;x<=100;x++)if(buck[x]>2)break;   
        bool who = true;

        if(x == 101)flag = false;
        else{
            for(int i = 0;i<n;i++)
                if(buck[nums[i]] ==1)who?ans[i] = 'A':ans[i] = 'B',who^=1;
            for(int i = 0;i<n;i++){if(nums[i] == x){ans[i] = 'B';break;}}
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        for(auto c:ans)cout<<c;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}