#include "bits/stdc++.h"
using namespace std;
//767. 重构字符串
string reorganizeString(string S) {
    vector<pair<char,int>> counter(26,make_pair('a',0));
    for(int i=0;i<26;i++){
        counter[i].first+=i;
    }
    for(int i=0;i<S.length();i++){
        counter[S[i]-'a'].second++;
    }
    for(int i=0;i<26;i++){
        if(counter[i].second>(S.length()+1)/2)
            return "";
    }
    sort(counter.begin(),counter.end(),[](auto a,auto b){return a.second>b.second;});
    int size=counter[0].second,index=0;
    vector<string> part(size);
    for(int i=0;i<26;i++){
        int n=counter[i].second;
        for(int j=0;j<n;j++){
            part[index++%size].push_back(counter[i].first);
        }
    }
    string res;
    for(int i=0;i<size;i++){
        res+=part[i];
    }
    return res;
}

int main() {
    cout<<reorganizeString("snnnnbpngobwznvnnnlnwhvnnnnfjnnlnnnnnnbnknnqkndzefncknnnnnaiqrntnndnnnjninnnunnunqhndnnqnnsjqnnpiqshntnnncnvnnnncnnqenlnninyndnnnljongnnjwnnnngllnnngkbnllnnnnontlbpngjnnenqnsnnnnnjeqqghnfpngepnodnnnnnnvnsrnughbnipvnhqmnzonoonnnjotnnonoennnpnfnnkdnnbmnmnpnqninnxronnnnvnlanlnnnebnnnlnvnfknsnbincnttnmnguqenhnnxunnnntnnnnhnqnzehvunfnvnndvnjnnnbnnpxnqipwnmnonnndlnsnonnninnxnnnjnnnnnesennmyiednnnnnnnnnhimtnnnonjlicnwnwvnntaxmnrntnnnnsnbnanninnecbcfjxncnnkvnnqgnunensanpnngjnzxjnopnnyvnnxskniyytnsnnnnx");
    return 0;
}