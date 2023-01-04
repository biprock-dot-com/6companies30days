class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<int> graph[n];

        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1); 
        vector<int> time(n);     
        vector<int> visit(n);   

        queue<int> q;
        q.push(bob);
        time[bob] = 0;
        visit[bob] = 1;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : graph[x])
            {
                if (visit[y] == true)
                    continue;
                parent[y] = x;
                visit[y] = 1;
                time[y] = time[x] + 1;
                q.push(y);
            }
        }
        set<int> s; 
        int node = 0;
        while (node != -1)
        {
            s.insert(node);
            node = parent[node];
        }
        
        for (int i = 0; i < n; i++)
            if (s.find(i) == s.end())
                time[i] = -1;

        visit.assign(n, 0);
        queue<pair<int, pair<int, int>>> q2;
        int ans = INT_MIN;
        q2.push({0, {0, 0}});

        while (!q2.empty())
        {
            auto node = q2.front();
            q2.pop();
            int c_node = node.first;           
            int c_time = node.second.first;  
            int c_val = node.second.second; 

            if (visit[c_node] == true)
                continue;
            visit[c_node] = true;

            if (time[c_node] == -1)               
                c_val += amount[c_node];
            else if (c_time == time[c_node])          
                c_val += amount[c_node] / 2;
            else if (c_time < time[c_node])           
                c_val += amount[c_node];

            if (graph[c_node].size() == 1 && c_node != 0) 
                ans = max(ans, c_val);

            for (int y : graph[c_node])
                q2.push({y, {c_time + 1, c_val}});
        }
        return ans;
    }
};