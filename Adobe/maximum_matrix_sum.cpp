class Solution {
public:
        long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long int sum = 0;
        int count = 0;
        int min_element = INT_MAX;


        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(matrix[i][j] <= 0) {
                    matrix[i][j] = -1 * matrix[i][j];
                    count++;  
                }
                sum += matrix[i][j]; 
                min_element  = min(matrix[i][j], min_element ); 
            }
        }
        if(count%2==0) return sum; 
        return sum - 2*min_element ; 
    }
};
