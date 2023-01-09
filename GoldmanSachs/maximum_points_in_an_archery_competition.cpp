class Solution {
private:
    int totalPoint(int mask) 
    {
        int point= 0;
        for (int i=0; i < 12; ++i) 
        {
            if (mask & (1<<i)) point += i;
        }
        return point;
    }
    
    int arrowsNeeded(int mask, vector<int> &aliceArrows) 
    {
        int arrows= 0;
        for (int i=0; i < 12; ++i) 
        {
            if (mask & (1<<i)) 
            {

                arrows += aliceArrows[i]+1;
            }
        }
        return arrows;
    }

public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int maxPoint= 0, maxMask;
        for (int mask=0; mask < (1<<12); ++mask) 
        {
            if (totalPoint(mask) > maxPoint && arrowsNeeded(mask, aliceArrows) <= numArrows) 
            {
                maxPoint= totalPoint(mask);
                maxMask= mask;
            }
        }
        vector<int> ans(12,0);
        int count= numArrows;
        for (int i=1; i < 12; ++i) {
            if (maxMask & (1<<i)) {
                ans[i]= aliceArrows[i]+1;
                count -= ans[i];
            }
        }
        ans[0]= count;
        return ans;
    }
};
