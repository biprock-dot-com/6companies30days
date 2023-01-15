class Solution 
{
public:
    
    int solveQuery(int trim, int k, vector<pair<string,int>> &v, int &len)
    {
        if(len!=trim)
        {
            for(int it=0;it<v.size();it++)
            {
                string num = v[it].first;
                string trimmednum = num.substr(len-trim);
                v[it].first = trimmednum;
            }
            sort(v.begin(), v.end());
            len = trim;
        }
        return v[k-1].second;
    }
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        vector<int> res(queries.size(),-1);
        int index = 0;

        int n = nums[0].size();
        
        vector<pair<string,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        
        map<pair<int,int>, vector<int>> q_map;
        for(int i=0;i<queries.size();i++)
        {
            int q = queries[i][0];
            queries[i][0] = queries[i][1];
            queries[i][1] = q;
            q_map[{queries[i][0],queries[i][1]}].push_back(i);
        }
        sort(queries.rbegin(), queries.rend());
        
        for(auto &qu: queries)
        {
            int q = solveQuery(qu[0],qu[1],v,n);
            for(int i = 0;i<q_map[{qu[0],qu[1]}].size();i++)
                res[q_map[{qu[0],qu[1]}][i]] = q;
        }
        
        return res;
    }
};
