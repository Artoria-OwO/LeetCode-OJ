class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
         heights.push_back(0);
         stack<int> stk;
         int maxArea = 0;
         for(int i = 0;i<heights.size();i++)
         {
             while(!stk.empty() && heights[i]<heights[stk.top()])
             {
                 int top= stk.top();
                 stk.pop();
                 maxArea = max(maxArea,heights[top]*(stk.empty()? i:(i - stk.top() -1)));
             }
             stk.push(i);
         }
         return maxArea;
         */
        return solve(heights,0,heights.size()-1);
    }
    int solve(const vector<int>& heights,int left,int right){
        if(left>right)
            return 0;
        if(left==right)
            return heights[left];
        int minidx=left;
        bool sorted= true;
        for (int i= left+1; i<=right; i++) {
            if (heights[i]<heights[i-1])
                sorted= false;
            if (heights[i]<heights[minidx])
                minidx= i;
        }
        if (sorted) {
            int p_max=0;
            for (int i=left; i<=right; i++)
                p_max= max(p_max, heights[i]*(right-i+1));
            return p_max;
        }
        return max(heights[minidx]*(right-left+1),max(solve(heights,left,minidx-1),solve(heights,minidx+1,right)));
    }
};
