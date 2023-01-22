class Solution {
public:

    bool isgood(int p, int i)
    {
        return(p>>i) & 1;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;

        for(int i=0; i<pow(2,n); i++)
        { 
            bool isvalid  = true;
            int count =0;

            for(int person =0; person<n; person++)
            {
                if(!isgood(i,person)) continue;
                count++;

                for(int j=0; j<n; j++)
               {
                  if((!isgood(i,j) && statements[person][j]==1) || (isgood(i,j) && statements[person][j]==0)) 
                  {
                    isvalid = false;
                    break;
                  }           
               }
            }
            if(isvalid)
             ans = max(ans,count);

        }
        

        return ans;
    }
    
};
