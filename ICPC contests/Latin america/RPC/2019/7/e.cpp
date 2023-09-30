#include <bits/stdc++.h>
using namespace std;
vector<bool> Criba(int n) {
    int raiz = sqrt(n);
    vector<bool> criba(n + 1,true);
    for (int i = 4; i <= n; i += 2)
        criba[i] = false;
    for (int i = 3; i <= raiz; i += 2)
        if (criba[i])
            for (int j = i * i; j <= n; j += i)
                if (!criba[j]) criba[j] = false;
    return criba;
}
bool prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main(){
    int t;
    string sa,sb;
    cin>>t;
    vector<bool> pr = Criba(100000);
    while(t--){
        cin>>sa>>sb;
		if (sa == sb) {
			cout << "2 2" << endl;
			continue;
		}
		int m1 = 0, m2 = 0;
		if (sa.find('.') != -1)
			m1 = sa.length() - sa.find('.') - 1;
		if (sb.find('.') != -1)
			m2 = sb.length() - sb.find('.') - 1;
		while (m1 < m2)
			sa.push_back('0'), m1++;
		while (m2 < m1)
			sb.push_back('0'), m2++;
		if (sa.find('.') != -1)
			sa.erase(sa.begin() + sa.find('.'));
		if (sb.find('.') != -1)
			sb.erase(sb.begin() + sb.find('.'));
		int a = stoi(sa);
		int b = stoi(sb);
		int g = __gcd(a, b);
		a /= g, b /= g;
		if (prime(a) && prime(b))cout<<a<<" "<<b<< endl;
		else
		    cout<<"impossible"<< endl;
	}
    return 0;
}