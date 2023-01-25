class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int lo = 0, hi = n * n - 1;

        while (lo < hi) 
        {
            int mid = lo + (hi - lo) / 2;
            vector<vector<bool>> visit(n, vector<bool>(n, false));

            if (reachBottom(grid, mid, n, visit, 0, 0)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

private:
    bool reachBottom(vector<vector<int>>& grid, int m, int n, vector<vector<bool>>& visit, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || visit[i][j] || grid[i][j] > m) return false;

        visit[i][j] = true;

        if (i == n - 1 && j == n - 1) return true;

        else return reachBottom(grid, m, n, visit, i + 1, j) || reachBottom(grid, m, n, visit, i - 1, j) || reachBottom(grid, m, n, visit, i, j - 1) || reachBottom(grid, m, n, visit, i, j + 1);
    }
};
