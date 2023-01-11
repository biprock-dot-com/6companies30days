class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0,k=s.size();

        unordered_map<string,int>mp;

        for(int i=0;i<words.size();i++)
            mp[words[i]]++;
        
        for(auto x: mp)
        {
           int l=0,r=0;
            string m=x.first;
            int p=m.size();
            while(l<k && r<p)
            {
                if(s[l]==m[r])
                {
                    l++;
                    r++;
                }
                else
                    l++;
            }
            if(r==p){
                ans+=x.second;
            }
        }
        return ans;
    }
};
