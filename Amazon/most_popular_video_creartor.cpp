class Solution {
public:
   vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {

    vector<vector<string>> ans;
    
    unordered_map<string, long> totalView; 
    unordered_map<string, int> maxView;
    unordered_map<string, string> minId;
    
    for (int i = 0; i < c.size(); i++)
    {
        totalView[c[i]] += views[i]; 
        
        if (maxView.find(c[i]) == maxView.end() || maxView[c[i]] < views[i])
        {
            maxView[c[i]] = views[i];
            minId[c[i]] = ids[i];
        }
        else if (maxView[c[i]] == views[i])
            minId[c[i]] = min(minId[c[i]], ids[i]);
    }
    
    int maxi = 0;
    for (auto i = totalView.begin(); i != totalView.end(); i++)
    {
        if (i->second > maxi)
        {
            ans.clear();
            ans.push_back({i->first, minId[i->first]});
            maxi = i->second;
        }
        else if (i->second == maxi)
            ans.push_back({i->first, minId[i->first]});
    }
    return ans;
  }
};
