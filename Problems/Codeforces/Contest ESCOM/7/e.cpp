#include <bits/stdc++.h>
using namespace std;
int main(){
    int nF = 0,nFi = 0;
    string firstF, path;
    map<string, set<string>> folder;
    map<string, set<string>> files;
    while(cin>>path){
        int n = path.size(),sub = 0;
        for(int i=0; i<n ;i++){
            if(path[i]=='\\'){
                sub++;          
                if(sub==2) firstF = path.substr(0,i);
                else if(sub>2) folder[firstF].insert(path.substr(0,i));
            }
        }
        // cout<<"   "<<path<<endl;
        files[firstF].insert(path);
    }
    // cout<<folder.size()<<endl;
    for (map<string,set<string>>::iterator it=folder.begin(); it!=folder.end(); it++)
        nF = max(nF,(int)it->second.size()); 
    for (map<string,set<string>>::iterator it=files.begin(); it!=files.end(); it++)   
        nFi = max(nFi,(int)it->second.size());  
    cout<<nF<<" "<<nFi;
    return 0;
}