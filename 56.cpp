//
// Created by 78241 on 10/8/2019.
//56. 合并区间
//need to be improved
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return intervals;
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> res;
        res.push_back(make_pair(intervals[0][0],intervals[0][1]));
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>res.back().second)
            {
                res.push_back(make_pair(intervals[i][0],intervals[i][1]));
            } else{
                if(intervals[i][1]>res.back().second){
                    res.back().second=intervals[i][1];
                }
            }
        }
        intervals.clear();
        vector<int> temp;
        for(auto it:res){
            temp.push_back(it.first);
            temp.push_back(it.second);
            intervals.push_back(temp);
            temp.clear();
        }
        return intervals;
    }
};