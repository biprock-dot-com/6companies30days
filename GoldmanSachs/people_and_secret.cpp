class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<int>dp(n+1);
        int const mod = 1e9 +7;
        int ans = 0;

        dp[1]=1;
        
        for(int i=1; i<=n; i++)
          for(int j=i +delay ;j<min(i+forget,n+1); j++)
           dp[j] = (dp[j]+dp[i])%mod;
        
        for(int i= n-forget+1; i<=n; i++)
         ans = (ans%mod + dp[i]%mod)%mod;
        
        return ans;
    }

};
