class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> inDeg(numCourses, 0);
        
        for(int i = 0; i<prerequisites.size(); i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDeg[prerequisites[i][0]]++;
        }
        

        queue<int>q;
        
        for(int i = 0; i<inDeg.size(); i++){
            if(inDeg[i] == 0){
                q.push(i);
                numCourses--;
            }
        }
        
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i = 0; i<g[now].size(); i++){
                int x = g[now][i];
                inDeg[x]--;
                if(inDeg[x] == 0){
                    q.push(x);
                    numCourses--;
                }
            }
        }
        
        return numCourses == 0;
    }
};