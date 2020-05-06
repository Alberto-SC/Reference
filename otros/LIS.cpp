#include <bits/stdc++.h>
using namespace std;
// Longest increasing secuence in o(nlogn)
vector<int> d;
int main() {
    int ans, n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for (int i = 0; i<n;i++) {
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), nums[i]);
        if (it == d.end()) d.push_back(nums[i]);
        else *it = nums[i];
    }
    cout<<"LIS ="<<d.size<<endl;
    return 0;
}
// int n, a[N], b[N], f[N], answer=0;
//   ... // enter n and a[] from keyboard

//   for (int i=1; i<=n; i++){
//       f[i]=lower_bound(b+1, b+answer+1, a[i])-b;
//       maximize(answer, f[i]);
//       b[f[i]]=a[i];
//    }

//    printf("%d\n", answer);
// If you want to print the LIS:


//    vector<int> T;

//    int require = answer;
//    for (int i=n; i>=1; i--)
//    if (f[i]==require){
//       T.push_back(a[i]);
//       require--;
//    }
//    // then print T with reversed order
//    int i=T.size();
//    while (i--) printf("%d ", T[i]);
//    printf("\n");