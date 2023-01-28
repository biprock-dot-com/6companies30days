class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int max_sum = INT_MIN;

        for(int i=0; i<n-2; i++)
         for(int j=0; j<m-2; j++)
         {
          int sum = (grid[i][j] + grid[i][j+1]+ grid[i][j+2]) + grid[i+1][j+1] + (grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]);
          max_sum = max(max_sum, sum);
         }

        return max_sum;
    }
};
