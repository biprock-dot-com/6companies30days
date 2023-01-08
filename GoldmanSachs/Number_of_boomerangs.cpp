class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count =0;
        for(int i=0; i<points.size(); i++)
        {
            map<int,int>m;
            for(int j=0;j<points.size();j++)
            {
                int dis = pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2);
                m[dis]++;
            }

            for(auto x:m)
             if(x.second) count+=(x.second*(x.second-1));
        }
       return count;

    }
};
