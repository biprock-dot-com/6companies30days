class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));
        
        
        for(int i = 0;i<n;i++)
            for(int j = m-1;j>0;j--)
                mat[i][j-1]+=mat[i][j];
            
        
       
        for(int i = 0;i<m;i++)
            for(int j = n-1;j>0;j--)
                mat[j-1][i]+=mat[j][i];
            
        

        
        for (int i = 0; i < n; i++)
       {
        for (int j = 0; j < m; j++)
        {
            int p = max(0, i - k);
            int q = max(0, j - k);
            ans[i][j] = mat[p][q];
            if (j + k + 1 < m)
            {
                ans[i][j] -= mat[p][j + k + 1];
            }
            if (i + k + 1 < n)
            {
                if (j + k + 1 < m)
                {
                    ans[i][j] -= (mat[i + k + 1][q] - mat[i + k + 1][j + k + 1]);
                }
                else
                {
                    ans[i][j] -= mat[i + k + 1][q];
                }
            }
        }
    }
    return ans;
    }
};
