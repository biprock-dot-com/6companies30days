class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26);
        for(auto& c:s)
            freq[c-'a']++;
        
        string ans;
        for(auto& c:order)
        {
            while(freq[c-'a']-- > 0)
                ans.push_back(c);
            
        }
        for(char c='a';c<='z';c++)
        {
            while(freq[c-'a']-- > 0)
                ans.push_back(c);
            
        }
        return ans;
    }
};
