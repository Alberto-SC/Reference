#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr(4);
    double s = 0;
    for(int i  = 0; i < 4; ++i) {
        cin >> arr[i];
        s += arr[i];
    }
    s /= 2;
    double area = (s-arr[0])*(s-arr[1])*(s-arr[2])*(s-arr[3]);
    area = sqrt(area);
    cout << setprecision(8) << fixed << area << '\n';
    return 0;
} 