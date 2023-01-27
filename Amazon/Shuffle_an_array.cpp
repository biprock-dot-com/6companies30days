class Solution {
public:
    vector<int>res;
    vector<int>shuf;

    Solution(vector<int>& nums) {
        shuf  = nums;
        res = nums;
    }
    
    vector<int> reset() {
        return res;
    }
    
    vector<int> shuffle() {
        next_permutation(shuf.begin(), shuf.end());
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
