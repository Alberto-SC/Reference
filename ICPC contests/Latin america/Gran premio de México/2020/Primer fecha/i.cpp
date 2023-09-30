#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;
typedef long long int lli;

int main(){__

	set<char> special = {'.', '#', '$', '%', '/', '(', '&', ')'};
    int t; cin >> t;
	for(int caso=1; caso <= t; caso++){
		string password; cin >> password;
		bool isLow = false;
		bool isUp = false;
		bool isNum = false;
		bool isTwoNum = false;
		bool isSpecial = false;
		bool isTen = false;

		for(char c:password){
			if(islower(c))
				isLow = true;
			if(isupper(c))
				isUp = true;
			if(isdigit(c))
				isNum = true;
			if(special.count(c) > 0)
				isSpecial = true;
		}

		for(int i=1; i<password.size(); i++){
			if(isdigit(password[i-1]) && isdigit(password[i])){}
				if(password[i-1]-'0' == password[i]-'0'-1){
					isTwoNum = true;
				}
		}
		
		isTen = (password.size() >= 10)?true:false;

		int total = 0;
		total += (isTwoNum == false && isNum == true);
		total += isLow;
		total += isUp;
		total += isSpecial;
		total += isTen;

		cout << "Assertion number #" << caso << ": ";
		if(total == 5){
			cout << "Strong";
		}else if(total == 4){
			cout << "Good";
		}else if(total == 3){
			cout << "Weak";
		}else{
			cout << "Rejected";
		}
		cout << endl;
	}

    return 0;
}
