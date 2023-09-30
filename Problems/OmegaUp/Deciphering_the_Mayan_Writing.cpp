
#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    std::ios::sync_with_stdio(0);
	int a,b,cont = 0;
	cin>>a>>b;
	char c;
	vector<char> ss(b);
	vector<int> w(60,0);
	vector<int> s(60,0);
	for(int i = 0;i<a;i++){
		cin>>c;
		w[c-'A']++;
	}
	for(int i = 0;i<b;i++){
		cin>>c;
		ss[i] = c;
	}
	for(int i = 0;i<a;i++){

		s[ss[i]-'A']++;
	}
	if(w == s)cont++;
	for(int i = 0;i+a<b;i++){
		s[ss[i+a]-'A']++;
		s[ss[i]-'A']--;
		if(w == s)cont++;

	}
	cout<<cont;
	/*#ifdef LOCAL
	cout<<"Time elapsed: "<< 1.0 * clock()/CLOCKS_PER_SEC<<endl;
	#endif
	*/
	return 0;
}