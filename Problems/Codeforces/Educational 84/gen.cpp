// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min()+10, numeric_limits<int>::max()-10);

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int myrand(int i ){return dis(rng)%i;}

int main(int argc, char* argv[]) {

    srand(atoi(argv[1])); 
    int t,n;
    t = rand(1, 1);
    cout<<t<<endl;
    while(t--){
        n = rand(1,20000);
        cout<<n<<endl;
        vector<int> nums(n);
        for(int i = 0;i<n;i++){
            nums[i] = i+1;
        }
        random_shuffle(nums.begin(),nums.end());
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    }
}
    
