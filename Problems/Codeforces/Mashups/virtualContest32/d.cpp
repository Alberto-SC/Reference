#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct ST{
    int n;
    vector<int> st;
    ST(int n):n(n){
        st.resize(2*n,inf);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x >>=1 ; st[x] = st[x<<1]^st[x<<1|1]);
	}
	inline int query(int l, int r) {
		int ans =0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans ^=st[l];
			if (~r & 1) ans ^=st[r];
		}
		return ans;
	}
};

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        ST st(n);
        for(int i = 0;i<n;i++)
            st.update(i,nums[i]);
        cin>>q;
        for(int i = 0;i<q;i++){
            cin>>l>>r;
            l--,r--;

        }
    }
    return 0;
}  

1 2 4 8 7 9
1^2 , 2^4 , 4^8 , 8^7

1^2 ^ 2^4 , 2^4 ^ 4^8 , 4^8 ^ 8^7
1^2 ^ 2^4 ^ 2^4 ^ 4^8, 2^4 ^ 4^8 ^ 4^8 ^ 8^7

1^2 ^ 2^4 ^ 2^4 ^ 4^8 ^ 2^4 ^ 4^8 ^ 4^8 ^ 8^7
  

1 2 4 8 7 9
1^2 , 2^4 , 4^8 , 8^7 ,7^9

1^2^2^4 , 2^4^4^8 , 4^8^8^7, 8^7^7^9
1^2^2^4^2^4^4^8, 2^4^4^8^4^8^8^7 , 4^8^8^7^8^7^7^9
1^2^2^4^2^4^4^8^2^4^4^8^4^8^8^7 , 2^4^4^8^4^8^8^7^4^8^8^7^8^7^7^9

1^7^2^9


1 2 4 8 7 9 10 
1^2 , 2^4 , 4^8 , 8^7 ,7^9 ,9^10

1^4 , 2^8 , 4^7, 8^9, 7^10

1^4^2^8 ,2^8^4^7, 4^7^8^9 ,8^9^7^10

1^7, 2^9 ,4^10
1^7^2^9, 2^9^4^10

1^7^4^10


  
1 2 3 4 5 6 7 8

1^2 , 2^3 , 3^4 , 4^5 , 5^6 , 6^7 , 7^8

1^3 , 2^4 , 3^5 , 4^6 , 5^7 , 6^8

1^2^3^4, 2^3^4^5 , 3^4^5^6 , 4^5^6^7 , 5^6^7^8 

1^5, 2^6 ,3^7 ,4^8

1^2^5^6, 2^3,6^7 , 3^4^7^8  

1^5^3^7 , 2^4^6^8

