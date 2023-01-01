class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        
        int pass = 0,sum=0;
        for(int i=0; i<nums.size(); i++)
         pass+= nums[i]*i;

        for(int i=0; i<nums.size(); i++)
         sum+=nums[i]; 
        int ans = pass;
        for(int i=nums.size()-1; i>=0; i--)
        {
            pass+= sum - (nums.size()*nums[i]);
            ans = max(ans,pass);
        }
        return ans;
    }
};