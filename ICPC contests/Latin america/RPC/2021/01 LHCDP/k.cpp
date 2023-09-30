#include <bits/stdc++.h>
using namespace std;
int block,total = 0;
int numbers[1000005];
struct query{
    int L, R,id;
};
bool comp(query x, query y){
    int aux = x.L/block;
    if (aux != y.L/block)
        return x.L < y.L;
    if(aux & 1)
		return x.R < y.R;
	return x.R > y.R;
}
 
void add(int x){
    numbers[x]++;
    if(numbers[x] == 1)
        total++;
}
 
void rem(int x){
    numbers[x]--;
    if(numbers[x] == 0){
        total--;
    }
}
 

int main(){
    int n,k,x,y;
    cin>>n>>k;
    vector<int> nums(n);   
    for(auto &c:nums)cin>>c;
    vector<int> copy = nums;
    vector<int> uniques;
    sort(copy.begin(),copy.end());
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 0;i<n;i++){
        if(copy[i]!=last){
            last =copy[i];
            uniques.push_back(last);
        }
    }
    for(int i =0;i<n;i++){
        nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
    }
    map<int,vector<int>> mp;
    for(int i = 0;i<n;i++){
        mp[nums[i]].push_back(i);
    }
    vector<query> q;
    int z = 0;
    for(auto c:mp){
        if(c.second.size()>=k){
            int l = 0,r = k-1;
            while(r<c.second.size()){
                q.push_back({c.second[l],c.second[r],z++});
                l++,r++;
            }
        }
    }
    block = (int)(sqrt(n));
    sort(q.begin(),q.end(),comp);
    int l = 0, r = -1;
    int mn = n+1;
    for (int i=0; i < q.size(); i++){
        int L = q[i].L, R = q[i].R;
        while (l > L){
            l--;
            add(nums[l]);
        }
        while (r < R){
            r++;
            add(nums[r]);
        }
        while (l < L){
            rem(nums[l]);
            l++;
        }
        while (r > R){
            rem(nums[r]);
            r--;
        }
        mn = min(total-1,mn);
    }
    if(mn ==n+1)
        cout<<-1<<endl;
    else
        cout<<mn<<endl;
    return 0;
}
