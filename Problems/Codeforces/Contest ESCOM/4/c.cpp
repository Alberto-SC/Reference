#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	std::ios::sync_with_stdio(0);
    ios::sync_with_stdio(false), cin.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> array(n);
        for(int i = 0;i<n;i++)
            cin>>array[i];
        int ind = -1;
        for (int i=0;i<n;i++){
			if (array[i] != -1) {
				ind = i;
				break;
			}
        }
        if(ind != -1){
            for (int i = ind + 1; i < n; ++i)
                array[i] = (array[i-1] + 1) % m;
            for (int i = ind - 1; i >= 0; --i)
                array[i] = ((array[i+1] - 1) % m + m) % m;
        }
		for (int i = 0; i < n; i++)
			cout<<array[i]<<" ";
        cout<<endl;
    }
    return 0;

}