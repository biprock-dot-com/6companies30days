class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {

        long mod = 1e9 + 7;
		long ans = 0;
		nums.push_back(-1);
		int length = nums.size();
		
		stack<int> st;

		vector<long> dp(length);
		dp[0] = nums[0];
		for (int i = 1; i < length-1; i++) { 
			dp[i] = dp[i - 1] + nums[i]; 
		}
		for (int i = 0; i < length; i++) {
			while (!st.empty() && nums[i] < nums[st.top()]) {
				int top = st.top();
				st.pop();

				if (!st.empty()) {
					long x = dp[i - 1] - dp[st.top()];
					
					ans = (x * nums[top]) > ans ? (x * nums[top]) : ans;
				}
				else {
					
					long x = dp[i-1];
					ans = (x * nums[top]) > ans ? (x * nums[top]) : ans;
				}
			}
			st.push(i);
		}
		return ans % mod;
    }
};
