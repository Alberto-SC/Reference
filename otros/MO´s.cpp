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
    int n,m,x,y;
    cin >> n;
    vector<int> nums(n);   
    for(auto &c:nums)cin>>c;
    cin >> m;
    vector<query> q(m);
    for (int i=0;i<m;i++){
        cin>>x>>y;
        q[i]={x-1,y-1,i};
    }
    block = (int)(sqrt(n));
    sort(q.begin(),q.end(),comp);
    vector<int> ans(m);
    int l = 0, r = -1;
    for (int i=0; i < m; i++){
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
        ans[q[i].id] = total; 
    }
    for(auto c:ans)cout<<c<<endl;
    return 0;
}
