#include <bits/stdc++.h>
using namespace std;
// delete spaces/tabs in head and tail of str
bool isBlankLine(char const* line){
    for ( char const* cp = line; *cp; ++cp ){
        if ( !isspace(*cp) ) return false;
    }
    return true;
}

bool isBlankLine(std::string const& line){
   return isBlankLine(line.c_str());
}
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
int main(){
    string s;
    vector<string> ss;
    vector<string> passport;
    map<string,int> mp;
    mp["byr"] = 0; 
    mp["iyr"] = 1; 
    mp["eyr"] = 2; 
    mp["hgt"] = 3; 
    mp["hcl"] = 4; 
    mp["ecl"] = 5; 
    mp["pid"] = 6; 
    mp["cid"] = 7; 
    int cont = 0;
    while(getline(cin,s)){

        if(isBlankLine(s)){
            cout<<"NEW"<<endl;
            vector<bool> bk(8,false);
            bool flag = true;
            for(auto d:passport){ 
                cout<<d<<endl;
                // cout<<d.substr(0,3)<<endl;
                if(d.substr(0,3)== "byr"){
                    int num = stoi(d.substr(4));
                    cout<<num<<endl;
                    if(num<1920 || num>2002)flag = false;
                }
                else if(d.substr(0,3)== "iyr"){
                    int num = stoi(d.substr(4));
                    cout<<num<<endl;
                    if(num<2010 || num>2020)flag = false;
                }
                else if(d.substr(0,3)== "eyr"){
                    int num = stoi(d.substr(4));
                    cout<<num<<endl;
                    if(num<2020 || num>2030)flag = false;
                }
                else if(d.substr(0,3)== "hgt"){
                    string b = d.substr(4);
                    if(b[b.size()-1]==13){
                        cout<<"SALTO"<<endl;
                        b.pop_back();
                    }
                    cout<<"HGT___"<<endl;
                    cout<<b<<endl;
                    cout<<b[b.size()-1]<<endl;
                    cout<<b[b.size()-2]<<endl;
                    if(b[b.size()-2]== 'c' && b[b.size()-1]=='m'){
                        cout<<"CM"<<endl;
                        int num = stoi(b.substr(0,3));
                        if(num<150 || num>193)flag = false;
                    }
                    else if(b[b.size()-2]== 'i' && b[b.size()-1]=='n'){
                        int num = stoi(b.substr(0,3));
                        cout<<"IN"<<endl;
                        cout<<num<<endl;
                        if(num<59 || num>76)flag = false;
                    }
                    else flag = false,cout<<"FALSE"<<endl;
                }
                else if(d.substr(0,3)== "hcl"){
                    if(d[4]== '#'){
                        string b = d.substr(5);
                        if(b[b.size()-1]==13){
                            cout<<"SALTO"<<endl;
                            b.pop_back();
                        }
                        cout<<b<<endl;
                        if(b.size()!=6)flag = false;
                        else{
                            for(int k = 0;k<6;k++)
                                if(b[k]<'a' && b[k]>'9' ||b[k]>'f' ||b[k]<'0')
                                    flag = false;
                            }
                    }
                    else flag = false;
                }
                else if(d.substr(0,3)== "ecl"){
                    string b = d.substr(4);
                    if(b[b.size()-1]==13){
                        cout<<"SALTO"<<endl;
                        b.pop_back();
                    }
                    cout<<b<<endl;
                    if(b!= "amb" && b!= "blu" && b!= "brn" &&  
                    b!="gry" && b!= "grn" && b!="hzl" &&  b!="oth")
                        flag = false;
                }
                else if(d.substr(0,3)== "pid"){
                    string b = d.substr(4);
                    if(b[b.size()-1]==13){
                        cout<<"SALTO"<<endl;
                        b.pop_back();
                    }
                    cout<<b<<endl;
                    if(b.size()!=9)flag = false;
                    else{
                        for(int i = 0;i<9;i++){
                            if(b[i]<'0' || b[i]>'9')flag = false;
                        }
                    }
                }
                cout<<"FLAG "<<flag<<endl;
                bk[mp[d.substr(0,3)]] = true;
            }
            int z = 0;
            for(int i = 0;i<8;i++){
                if(bk[i])z++;
                cout<<bk[i]<<" ";
            }
            if((z == 8 ||(z == 7 && bk[7]==false)) && flag)
                cont++;
            cout<<"Cont "<<cont<<endl;
            passport.clear();
        }
        else{
            istringstream in(s);
            vector<string> words;
            string w;
            while(getline(in, w, ' ')){
                passport.push_back(w);
            }
            // cout<<s<<endl;
            // passport.push_back(s);
        }
    }
    cout<<cont<<endl;
    cout<<"NEW"<<endl;
            vector<bool> bk(8,false);
            bool flag = true;
            for(auto d:passport){ 
                cout<<d<<endl;
                // cout<<d.substr(0,3)<<endl;
                if(d.substr(0,3)== "byr"){
                    int num = stoi(d.substr(4));
                    cout<<num<<endl;
                    if(num<1920 || num>2002)flag = false;
                }
                else if(d.substr(0,3)== "iyr"){
                    int num = stoi(d.substr(4));
                    cout<<num<<endl;
                    if(num<2010 || num>2020)flag = false;
                }
                else if(d.substr(0,3)== "eyr"){
                    int num = stoi(d.substr(4));
                    cout<<num<<endl;
                    if(num<2020 || num>2030)flag = false;
                }
                else if(d.substr(0,3)== "hgt"){
                    string b = d.substr(4);
                    if(b[b.size()-1]==13){
                        cout<<"SALTO"<<endl;
                        b.pop_back();
                    }
                    cout<<"HGT___"<<endl;
                    cout<<b<<endl;
                    cout<<b[b.size()-1]<<endl;
                    cout<<b[b.size()-2]<<endl;
                    if(b[b.size()-2]== 'c' && b[b.size()-1]=='m'){
                        cout<<"CM"<<endl;
                        int num = stoi(b.substr(0,3));
                        if(num<150 || num>193)flag = false;
                    }
                    else if(b[b.size()-2]== 'i' && b[b.size()-1]=='n'){
                        int num = stoi(b.substr(0,3));
                        cout<<"IN"<<endl;
                        cout<<num<<endl;
                        if(num<59 || num>76)flag = false;
                    }
                    else flag = false,cout<<"FALSE"<<endl;
                }
                else if(d.substr(0,3)== "hcl"){
                    if(d[4]== '#'){
                        string b = d.substr(5);
                        if(b[b.size()-1]==13){
                            cout<<"SALTO"<<endl;
                            b.pop_back();
                        }
                        cout<<b<<endl;
                        if(b.size()!=6)flag = false;
                        else{
                            for(int k = 0;k<6;k++)
                                if(b[k]<'a' && b[k]>'9' ||b[k]>'f' ||b[k]<'0')
                                    flag = false;
                            }
                    }
                    else flag = false;
                }
                else if(d.substr(0,3)== "ecl"){
                    string b = d.substr(4);
                    if(b[b.size()-1]==13){
                        cout<<"SALTO"<<endl;
                        b.pop_back();
                    }
                    cout<<b<<endl;
                    if(b!= "amb" && b!= "blu" && b!= "brn" &&  
                    b!="gry" && b!= "grn" && b!="hzl" &&  b!="oth")
                        flag = false;
                }
                else if(d.substr(0,3)== "pid"){
                    string b = d.substr(4);
                    if(b[b.size()-1]==13){
                        cout<<"SALTO"<<endl;
                        b.pop_back();
                    }
                    cout<<b<<endl;
                    if(b.size()!=9)flag = false;
                    else{
                        for(int i = 0;i<9;i++){
                            if(b[i]<'0' || b[i]>'9')flag = false;
                        }
                    }
                }
                cout<<"FLAG "<<flag<<endl;
                bk[mp[d.substr(0,3)]] = true;
            }
            int z = 0;
            for(int i = 0;i<8;i++){
                if(bk[i])z++;
                cout<<bk[i]<<" ";
            }
            if((z == 8 ||(z == 7 && bk[7]==false)) && flag)
                cont++;
            cout<<"Cont "<<cont<<endl;
    cout<<cont<<endl;
    return 0;
}