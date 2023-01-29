class Solution {
public:
    vector<std::string> topKFrequent(vector<string>& words, int k) {
   
        unordered_map<string, int> m;

        for (const auto& str : words) 
        {
            if (m.find(str) != m.end()) 
                m[str] += 1;
            else 
               m[str] = 1;
            
        }

        auto compare = [](const pair<string, int>& a, const pair<string, int>& b) 
        { 
            return a.second < b.second || ((a.second == b.second) && (a.first.compare(b.first) > 0)) ; 
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> pq(compare);

        for (const auto& pair : m) {
            pq.push(pair);   
        }

        vector<string>ans;

        for (int i = 0; i < k ; ++i)  {
            ans.push_back(pq.top().first);
            pq.pop();
        }
				
        return ans;
    }
};
