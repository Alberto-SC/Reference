#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,ai;
    cin>>n;
    vector<lli> nums(n);
    vector<pair<lli,lli>> negativepos;
    vector<lli> zerospos;
    vector<pair<lli,lli>> positives;
    for(int i = 0;i<n;i++){
        cin>>ai;
        if(ai<0)negativepos.push_back({ai,i+1});
        else if(ai == 0)zerospos.push_back(i+1);
        else positives.push_back({ai,i+1});
        nums[i] = ai;
    }
    sort(zerospos.begin(),zerospos.end());
    sort(negativepos.rbegin(),negativepos.rend());
    
    for(int i = 0;i<zerospos.size()-1;i++)
        cout<<1<<" "<<zerospos[i]<<" "<<zerospos[i+1]<<endl;
    if(negativepos.size()&1 && zerospos.size()>1)cout<<1<<" "<<negativepos[0].second<<" "<<zerospos[zerospos.size()-1]<<endl;
    else if(negativepos.size() == 1 && zerospos.size() == 0)cout<<2<<" "<<negativepos[0].second<<endl;
    if(zerospos.size()>0 && zerospos.size()<n-1)cout<<2<<" "<<zerospos[zerospos.size()-1]<<endl;
    lli ansp = 1;
    for(int i = 0;i<positives.size()-1;i++){
        ansp*=positives[i].first;
        cout<<1<<" "<<positives[i].second<<" "<<positives[i+1].second<<endl;
    }
    if(positives.size()>0)
        ansp*=positives[positives.size()-1].first;

    int i;
    lli ansn = 1;
    for(negativepos.size()&1? i = 1: i = 0;i<negativepos.size()-1;i++){
        ansn*=negativepos[i].first;
        cout<<1<<" "<<negativepos[i].second<<" "<<negativepos[i+1].second<<endl;
    }
    if(negativepos.size()>1)
        ansn*=negativepos[negativepos.size()-1].first;
    if(positives.size()>0 && negativepos.size()>1)
        cout<<1<<" "<<positives[positives.size()-1].second<<" "<<negativepos[negativepos.size()-1].second<<endl;

    return 0;   
}