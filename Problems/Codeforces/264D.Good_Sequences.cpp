#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
map<int,int> mp;

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(auto &c:nums)cin>>c;
	for(int i = 0;i<n;i++){
		mp[nums[i]]++;
		int mx = -1;
		for(int j = 2;j*j<=nums[i];j++){
			if(nums[i]%j == 0){
				// if(mp.count(j))
					mx = max(mx,mp[j]);
				if(nums[i]/j!= j )
					mx = max(mx,mp[nums[i]/j]);
			}
		}
		if(mx == -1)continue;
		mp[nums[i]] = mx+mp[nums[i]];
		for(int j = 2;j*j<=nums[i];j++){
			if(nums[i]%j == 0 ){
				mp[j] = mp[nums[i]];
				if(nums[i]/j!= j)
					mp[nums[i]/j] = mp[nums[i]];
			}
		}
	}
	int mx = -1;
	for(auto c:mp){
		// cout<<c.first<<" "<<c.second<<endl;
		mx = max(mx,c.second);
	}
	cout<<mx<<endl;
	return 0;
}

