class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    
    if (k == 0 || n >= k - 1 + maxPts)
      return 1.0;

    double prob = 0.0;

    vector<double> dp(n + 1);  
    dp[0] = 1.0;

    double point = dp[0];  

    for (int i = 1; i <= n; ++i) 
    {
      
      dp[i] = point / maxPts;

      if (i < k)
        point += dp[i];

      else  
        prob += dp[i];

      if (i - maxPts >= 0)
        point -= dp[i - maxPts];
    }

    return prob;
  }
};
