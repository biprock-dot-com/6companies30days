class Solution {
public:
    int numberOfCombinations(string num) {

        if (num[0] == '0') return 0;


        long ans = 0, mod = 1e9 + 7;
        long n = num.size();

        vector<vector<long>> dp(n+ 1, vector<long>(n + 1)), dp1(n + 1, vector<long>(n + 1));

        for (int i = n - 1; i >= 0; i--) 
            for (int j = n- 1; j >= 0; j--) 
                if (num[i] == num[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
            
        auto len = [&](int k, int i, int j) 
        {
            int length = dp[k][i];
            return length >= j + 1 - i || num[k + length] < num[i + length];
        };

        for (int j = 0; j < n; j++) 
          dp1[0][j] = 1;

        for (int i = 1; i < n; i++) 
        {
            if (num[i] == '0') continue;

            for (int j = i, k = i - 1, sum = 0; j < n; j++) 
            {
                dp1[i][j] = sum;
                if (k < 0) 
                 continue; 

                if (num[k] > '0' && len(k, i, j)) 
                 dp1[i][j] = (dp1[i][j] + dp1[k][i - 1]) % mod;

                sum = (sum + dp1[k][i - 1]) % mod; 
                k--;
            }
        }
        for (int i = 0; i < n; ++i) ans = (ans + dp1[i][n - 1]) % mod;
        return ans;
    }
};
