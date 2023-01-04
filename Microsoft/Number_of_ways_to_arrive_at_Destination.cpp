class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long  mod = (long long )(1e9+7);

        vector<pair<long long ,long long>>graph[n];
        for(auto r : roads) {
            graph[r[0]].push_back({r[1],r[2]});
            graph[r[1]].push_back({r[0],r[2]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long ,long long>>,greater<pair<long long,long long>>>pq;

        vector<long long >distance(n,INT_MAX),ways(n,0);

        distance[0]=0,ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()) {
            long long  d = pq.top().first;
            long long  node = pq.top().second;

            pq.pop();

            for(auto x : graph[node]) {
               long long   a_node = x.first;
                long long  e = x.second;

                if(d+e < distance[a_node]) {
                    distance[a_node]= d+e;
                    pq.push({d+e,a_node});
                    ways[a_node]=ways[node];
                } 
                else if(d+e == distance[a_node]) {
                    ways[a_node]= (ways[a_node]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
