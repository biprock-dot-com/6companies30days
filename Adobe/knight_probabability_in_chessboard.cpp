#include <bits/stdc++.h>
using namespace std;
int dir[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
class Solution {
   public:
   double prob(int x, int y, int n, int k, vector < vector < vector < double > > >& dp){
      if(x >= n || y >= n || x < 0 || y < 0 ) return 0.0;
      if(k == 0) return 1.0;
      if(dp[k][x][y] != -1) return dp[k][x][y];
      dp[k][x][y] = 0;
      for(int i = 0; i < 8; i++){
         dp[k][x][y] += solve(x + dir[i][0], y + dir[i][1], n, k - 1, dp);
      }
      return dp[k][x][y];
   }
   double knightProbability(int n, int k, int row, int coloumn) {
      vector < vector < vector < double > > > dp (k + 1, vector < vector < double > >(n, vector < double >(n, -1))) ;
      return prob(row, coloumn, n, k, dp) / pow(8, k);
   }
};
