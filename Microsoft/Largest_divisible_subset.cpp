class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int>dp(nums.size(),1);
        vector<int>track(nums.size());

        int pivot=0;
        int dp_max = 1;

        for(int i=0; i<nums.size(); i++)
        {
            track[i]=i;
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    track[i]=j;
                }
            }
            if(dp_max<dp[i])
            {
                dp_max=dp[i];
                pivot=i;
            }
        }

        vector<int>res;
        res.push_back(nums[pivot]);
        while(track[pivot]!=pivot)
        {
            pivot = track[pivot];
            res.push_back(nums[pivot]);
        }

        return res;
    }
};