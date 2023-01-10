class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        constexpr int mod = 1e9+7;
        long ans = 0;
        unordered_map<int,int> freq;
        for (const int x : nums) {
            int reverse_x = 0;
            int original_x = x;
            int digits = 0;
            while (original_x > 0) {
                reverse_x = reverse_x*10 + (original_x % 10);
                original_x /= 10;
                digits++;
            }
            ans += freq[x - reverse_x];
            freq[x - reverse_x]++;
            ans %= mod;
        }
        return ans;
    }
};
