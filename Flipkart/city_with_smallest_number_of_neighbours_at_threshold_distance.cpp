class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++)
        {
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        vector<int>neighbors(n,0);   
        int min_neighbors=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(j!=i && dist[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            neighbors[i]=count;
            min_neighbors=min(min_neighbors,count);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(neighbors[i]==min_neighbors)
                return i;
        }
        return -1;
    }
};
