#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,aux;
    long long int res=0;
    std::vector<int> nums;
    cin>>N;
    int cube[N];
    cube[N-1]=0;
    set<int> right,left;
    for(int i=0; i<N; i++){
        cin>>aux;
        nums.push_back(aux);
    }
    int cont=0;
    for(int i=N-1; i>0 ;i--){
        if(left.find(nums[i])!= left.end()){
            cube[i-1] = cont;
        }else{
            cube[i-1] = ++cont;
        }
        left.insert(nums[i]);
    }
    for(int i=0; i<N-1; i++){
        if(right.find(nums[i])!= right.end())
            continue;
        res+= cube[i];
        right.insert(nums[i]);
    }

    cout<<res<<"\n";
    return 0;
}
