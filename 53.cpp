//
// Created by 程致远 on 2019-10-13.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, INT_MIN);
        for(int i=nums.size()-1;i>=0;--i){
            dp[i]=max(dp[i+1]+nums[i],nums[i]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main(){
    Solution s;
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    s.maxSubArray(nums);
}