  
#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	string orgFilename, path, aux; cin >> orgFilename;
	getline(cin, aux);
	getline(cin, path);
	int returnCode, timeLimit, executionTime;
	cin >> returnCode >> timeLimit >> executionTime;
	
	int solSize; cin >> solSize;
	getline(cin, aux);
	vector<string> sol(solSize);
	for(auto &x:sol) getline(cin, x);

	int subSize; cin >> subSize;
	getline(cin, aux);
	vector<string> sub(subSize);
	for(auto &x:sub) getline(cin, x);

	if(path.size() == 0){
		cout << "Compile Error" << endl;
		return 0;
	}

	string submitedFilename, extension;
	bool isExtension = true;
	if(path.back() == '\"') path.pop_back();
	for(int i=path.size()-1; i>=0; i--){
		if(path[i] == '.'){
			isExtension = false;
			continue;
		}

		if(isExtension)
			extension.push_back(path[i]);
		else
			submitedFilename.push_back(path[i]);
	}

	reverse(extension.begin(), extension.end());
	reverse(submitedFilename.begin(), submitedFilename.end());

	set<string> validFileExtensions;
	validFileExtensions.insert("c");
	validFileExtensions.insert("cpp");
	validFileExtensions.insert("java");
	validFileExtensions.insert("py");
	
	if(validFileExtensions.count(extension) == 0 || submitedFilename != orgFilename){
		cout << "Compile Error" << endl;
		return 0;
	}

	if(returnCode != 0){
		cout << "Run-Time Error" << endl;
		return 0;
	}

	if(executionTime > timeLimit){
		cout << "Time Limit Exceeded" << endl;
		return 0;
	}

	if(solSize != subSize){
		cout << "Wrong Answer" << endl;
		return 0;
	}

	for(int i=0; i<solSize; i++){
		if(sol[i] != sub[i]){
			cout << "Wrong Answer" << endl;
			return 0;
		}
	}

	cout << "Correct" << endl;
	return 0;
}