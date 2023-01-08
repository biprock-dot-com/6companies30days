class Solution {
public:

    int getdis(vector<int>&p1, vector<int>& p2)
    {
        return pow((p1[0]-p2[0]),2) + pow((p1[1]-p2[1]),2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12 = getdis(p1,p2);
        int d13 = getdis(p1,p3);
        int d14 = getdis(p1,p4);
        int d23 = getdis(p2,p3);
        int d24 = getdis(p2,p4);
        int d34 = getdis(p3,p4);

        if(d12 ==0 || d13 ==0 || d14 ==0 || d23 ==0 || d24 ==0 || d34 ==0)
          return false;
        
        if(d12 == d13 && d14 == d12+d13)return d24==d34;
        else if(d12 == d14 && d13 == d12+d14) return d34==d23;
        else if(d13 == d14 && d12 == d13+d14) return d23==d24;
        else return false;
    }
};
