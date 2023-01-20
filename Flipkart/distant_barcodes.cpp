class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int,int> m;

    for(auto bar: barcodes)
        m[bar]++;
    
    priority_queue<pair<int,int>> pq;

    for(auto p : m){
        pq.push({p.second,p.first});
    }
    vector<int> ans;

    while(pq.size()>=2)
    {
        pair<int,int> p1=pq.top(); 
        pq.pop();
        pair<int,int> p2=pq.top(); 
        pq.pop();


        ans.push_back(p1.second); p1.first--;
        ans.push_back(p2.second); p2.first--;

        if(p1.first>0)
            pq.push({p1.first,p1.second});
        if(p2.first>0)
            pq.push({p2.first,p2.second});
    }
    if(pq.size()==1){
        int x=pq.top().first;
        while(x--){
            ans.push_back(pq.top().second);
        }
    }
    return ans;
}
};
