
#include<bits/stdc++.h>

using namespace std;

bool isPrime(long long int n){
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}


bool validNum(string num){
    for(char ch : num) {
        if (std::isdigit(ch) == 0)
            return false;
    }


    if(num[0]-'0' == 0 || num[0] == '-' || num[0] == '+') return false;
    return true;
}

vector<string> splitString(string str){
    vector<string> res;
    istringstream ss(str);
    string word;
    while (ss >> word) {
        res.push_back(word);
    }
    return res;
}

bool containsNonvalid(string str){
    for(char a : str)
        if(a!=' ' or !isdigit(a))
            return false;
    return true;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    vector<string> numbs;
    // a=b=c="-1";
    bool res=false;
    string str;
    while(getline(cin, str)){
        cin.ignore();
        if(str.size()>0 and containsNonvalid(str)){
            // cout<<"hastab\n";
            res = false;
            break;
        }

        vector<string> row_values = splitString(str);
        for(string a: row_values)
            numbs.push_back(a);

        // cout<<a<<" "<<b<<" "<<c<<endl;
        if(numbs.size()==3 and validNum(numbs[0]) and validNum(numbs[1]) and validNum(numbs[2])){
            // res=true;
            // cout<<"check\n";
            if( (numbs[0].length()>11) || stoll(numbs[0])%2==1 || stoll(numbs[0])>1000000000 || stoll(numbs[0])<=3 || stoll(numbs[0]) != stoll(numbs[1])+stoll(numbs[2])  
            || !isPrime(stoll(numbs[1])) || !isPrime(stoll(numbs[2])))
                res= false;
            else{
                res = true;
            }
        }else if(row_values.size()>0){
            // cout<<"check no\n";
            res=false;
        }
        // a=b=c="-1";
        // cout<<str<<endl;

    }
    if(res) cout<<"1\n";
    else cout<<"0\n";
    return 0;
}
