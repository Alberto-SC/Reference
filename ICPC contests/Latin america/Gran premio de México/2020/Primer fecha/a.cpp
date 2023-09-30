#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int n,q; cin >> n >> q;

	int mxVal = 0, mxCount = 0;
	pair<int,int> mxOverall; //(i,j) -> j-i max
	vector< set<pair<int,int>> > maxPref(n+1); //jPreference, j
	vector<map<int,int>> prefCounter(n+1); //j, jPreference
	vector<map<int,int>> freqPref(n+1); //prefCount, prefCountFreq
	int i,j; char op;
	while(q--){
		cin >> op;
		switch(op){
			case 'R':
				cin >> i >> j;
				maxPref[i].erase({prefCounter[i][j], j});
				if(prefCounter[i][j] != 0){
					freqPref[i][ prefCounter[i][j] ]--;
				}
				prefCounter[i][j]++;
				freqPref[i][ prefCounter[i][j] ]++;
				maxPref[i].emplace(prefCounter[i][j], j);
				if(prefCounter[i][j] > mxVal){
					mxVal = prefCounter[i][j];
					mxCount = 1;
					mxOverall = {i,j};
				}else if(prefCounter[i][j] == mxVal){
					mxCount++;
				}
			break;

			case 'Q':
				cin >> i;
				if(maxPref[i].size() == 0){
					cout << "No info" << endl;
				}else{
					auto it = maxPref[i].end();
					it--;
					if(freqPref[i][ (*it).first ] > 1){
						cout << "Multiple" << endl;
					}else{
						cout << (*it).second << endl;
					}
				}
			break;

			case 'B':
				if(mxCount == 1){
					cout << mxOverall.first << " " << mxOverall.second << endl;
				}else{
					cout << "Multiple" << endl;

				}
			break;
		}
	}

	return 0;
}
