#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();


#include <bits/extc++.h> /** keep-include */
// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = lli(4e18 * acos(0)) | 71;
	lli operator()(lli x) const { return __builtin_bswap64(x*C); }
};
// gp_hash_table<int,pair<int,int>,chash> last({},{},{},{},{1<<16});
int main(){
    clock_t begin = clock();
    string s;
    cin>>s;
    getline(cin,s);
    getline(cin, s);
	istringstream in(s);
	vector<int> nums;
	string w;
	while(getline(in, w, ',')){
		nums.push_back(stoi(w));
    }
    int n = nums.size();
    map<int,pair<int,int>> last;

    int prev;
    for(int i = 0;i<n;i++){
        last[nums[i]].first = i+1;
        last[nums[i]].second = -1;
        prev = nums[i],cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(int i = n;i<30000000;i++){
        if(last[prev].second != -1){
            // cout<<"HI"<<endl;
            // cout<<last[prev].second<<" "<<last[prev].first<<endl;
            prev = last[prev].second-last[prev].first;
            if(last.find(prev)== last.end()){
                last[prev].first = i+1;
                last[prev].second = -1;
            }
            else if(last[prev].second ==-1)
                last[prev].second = i+1;
            else{
                last[prev].first =last[prev].second;
                last[prev].second = i+1;
            }
        }
        else {
            // cout<<"HELLO"<<endl;
            prev = 0;
            if(last.find(prev)== last.end()){
                last[prev].first = i+1;
                last[prev].second = -1;
            }
            else if(last[prev].second ==-1)
                last[prev].second = i+1;
            else{
                last[prev].first =last[prev].second;
                last[prev].second = i+1;
            }
        }
        // cout<<"TURN "<<i+1<<" "<<prev<<endl;
    }
    cout<<prev<<endl;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<time_spent<<endl;
    return 0;
}