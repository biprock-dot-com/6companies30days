class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int lo = 1, hi= 0;
        int max_num = INT_MIN, min_num = INT_MAX;
        for(int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j){
            if(max_num > nums[i])
                hi = i;
            else
                max_num = nums[i];
            if(min_num < nums[j])
                lo = j;
            else
                min_num = nums[j];
        }
        return hi-lo+1;
    }
};
