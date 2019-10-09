//
// Created by 78241 on 10/8/2019.
//495. 提莫攻击

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty())
            return 0;
        int sum=0;
        for(int i=0;i<timeSeries.size()-1;i++){
            if(timeSeries[i]+duration-1<timeSeries[i+1])
                sum+=duration;
            else
                sum+=timeSeries[i+1]-timeSeries[i];
        }
        sum+=duration;
        return sum;
    }
};