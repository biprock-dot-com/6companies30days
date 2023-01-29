class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int ans =0;

        vector<int>dp(m+1);

        for(int i=n-1;i>=0;i--)
         for(int j=0; j<m; j++)
         {
          dp[j] = nums1[i] == nums2[j] ? dp[j+1]+1 : 0;
          ans = max(ans,dp[j]);
         }

        return ans;
    }
};
