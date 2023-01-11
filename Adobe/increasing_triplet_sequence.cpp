class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;

        int first_min = INT_MAX, second_min =INT_MAX;

        for(int n : nums)
        {
            if(n<first_min) first_min =n;
            if(n>first_min) second_min = min(second_min,n);
            if(n>second_min) return true;
        }
        return false;
    }
};
