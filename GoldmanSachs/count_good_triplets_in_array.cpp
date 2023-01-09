class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>m;
        
        for(int i=0; i<n; i++)
         m[nums2[i]]=i;

        set<int>l,r;
        l.insert(m[nums1[0]]);
        
        for(int i=2; i<n; i++)
         r.insert(m[nums1[i]]);

        long long ans=0;
        
        for(int i=1; i<n-1; i++)
        {
            int x = m[nums1[i]];
            int dis = distance(l.begin(), l.lower_bound(x));
            int k = r.size() - distance(r.begin(), r.lower_bound(x));
            ans+= dis*k;
            l.insert(m[nums1[i]]);
            r.erase(m[nums1[i+1]]);
        }
        return ans;



    }
};
