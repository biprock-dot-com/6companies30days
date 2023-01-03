class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string>p;
        int area = 0;

        int a1 = INT_MAX;
        int a2 = INT_MIN;
        int b1 = INT_MAX;
        int b2 = INT_MIN;

        for(auto& r : rectangles)
        {
            int x1 = r[0];
            int x2 = r[2];
            int y1 = r[1];
            int y2 = r[3];

            a1 = min(a1,x1);
            a2 = max(a2,x2);
            b1 = min(b1,y1);
            b2 = max(b2,y2);

            area+= abs(x1-x2) * abs(y1-y2);

            if(!p.erase(to_string(x1)+"#"+to_string(y1))) p.insert(to_string(x1)+"#"+to_string(y1));
            if(!p.erase(to_string(x1)+"#"+to_string(y2))) p.insert(to_string(x1)+"#"+to_string(y2));
            if(!p.erase(to_string(x2)+"#"+to_string(y1))) p.insert(to_string(x2)+"#"+to_string(y1));
            if(!p.erase(to_string(x2)+"#"+to_string(y2))) p.insert(to_string(x2)+"#"+to_string(y2));

        }
        int o_area = abs(a1-a2) * abs(b1-b2);
        if(area!= o_area) return false;
        if(p.size()!=4) return false;

        if(p.find(to_string(x1)+"#"+to_string(y1))==p.end()) return false;
        if(!p.count(to_string(x1)+"#"+to_string(y2))) return false;
        if(!p.count(to_string(x2)+"#"+to_string(y1))) return false;
        if(!p.count(to_string(x2)+"#"+to_string(y2))) return false;

        return true;

    }
};