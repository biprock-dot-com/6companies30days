class Solution {
vector<vector<int>>res;
public:
    int sum(vector<int>& temp)
    {
        int s =0;
        for(int i=0; i<temp.size(); i++)
         s+=temp[i];
        return s;
    }

    void solve(vector<int>& temp , int k , int n, int num)
    {
        if(!k)
        {
            if(sum(temp)==n)
             res.push_back(temp);
            return ;
        }
        if(num>9) return ;
        temp.push_back(num);
        solve(temp,k-1,n,num+1);
        temp.pop_back();
        solve(temp,k,n,num+1);
    }
    vector<vector<int>> combinationSum3(int n, int k) {
       
        vector<int>temp;
        solve(temp, n,k,1);
        return res;
    }
};