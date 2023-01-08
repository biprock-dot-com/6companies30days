class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
     sort(points.begin(), points.end());

    int n = points.size(), count = 0;
        
    for(int i=0; i<n; ++i)
    {
        unordered_map<double, int> mp;
        int y = 0;
            
        for(int j=i+1; j<n; ++j)
        {
            int y_ = points[j][1] - points[i][1];
            int x_ = points[j][0] - points[i][0];
                
            if(x_==0)
            {
                y++;
            }
            else
            {
                double slope = (double)y_/x_;
                mp[slope]++;
            }
            }
            for(auto& m : mp)
            {
                count = max(count, m.second);
            }
            count = max(count, y);
        }
        return count+1;
    }
};
