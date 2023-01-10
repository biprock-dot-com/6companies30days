class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
	set<int> res;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; i - k >= 0 && i + k < n && j + 2 * k < m; k++) {
				int current = grid[i][j];
				int x = i, y = j;
				for (int count = 0; count < k; count++)
					current += grid[--x][++y];
				for (int count = 0; count < k; count++)
					current += grid[++x][++y];
				for (int count = 0; count < k; count++)
					current += grid[++x][--y];
				for (int count = 0; count < k - 1; count++)
					current += grid[--x][--y];
				res.insert(current);
				if (res.size() > 3)
					res.erase(res.begin());
			}
		}
	}
	return vector<int>(res.rbegin(), res.rend());
    }
};
