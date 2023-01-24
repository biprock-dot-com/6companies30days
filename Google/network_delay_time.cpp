
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<vector<int>>dist(n+1,vector<int>(n+1,1e9));
    for(int i = 1 ; i<=n ;i++)
        for(int j = 1 ; j<=n ;j++)
            if(i==j)dist[i][j] = 0;
        
    
    for(int i  = 0 ; i<times.size() ;i++)
    {
        int u = times[i][0];
        int v = times[i][1];
        int wt = times[i][2];
        dist[u][v] = wt;
    }

    for(int k = 1; k<=n ;k++)
        for(int i = 1; i<= n ; i++)
            for(int j = 1; j<=n ;j++)
                if(dist[i][k]!=1e9 and dist[k][j] != 1e9)
                    dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);
                    
                
            
        
    int maxi = 0;
    for(int i = 1; i<=n ;i++)
        maxi = max(maxi,dist[k][i]);
        
    return maxi!=1e9 ? maxi : -1; 
    }
};
