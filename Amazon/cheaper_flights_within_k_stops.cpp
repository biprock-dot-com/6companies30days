class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> distance(n, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(vector<int> &f : flights) {
            int u    = f[0];
            int v    = f[1];
            int cost = f[2];
            
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;
        
        int level = 0;
        
        while(!q.empty() && level <= k) {
            int n= q.size();
            
            while(n--) {
                int u = q.front().first;
                int d = q.front().second;
                q.pop();
                
                for(pair<int, int> &P : adj[u]) {
                    
                    int v    = P.first;
                    int cost = P.second;
                    
                    if(distance[v] > d + cost) {
                        distance[v] = d + cost;
                        q.push({v, d+cost});
                    }
                    
                }
                
            }
            level++;
        }
        
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
