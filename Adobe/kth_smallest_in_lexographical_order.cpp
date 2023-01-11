class Solution {
public:

    int getlevel(long long n , long long num1 , long long num2)
    {
        int ans =0;

        while(num1<=n)
        {
            ans+=min(n+1,num2)-num1;
            num1*=10;
            num2*=10;
        }

        return ans;
    }
    
    int findKthNumber(int n, int k) {
        int num =1;
        k--;

        while(k)
        {
            int level = getlevel(n,num,num+1);
            if(level<=k)
            {
                k-=level;
                num++;
            }
            else
            {
                num*=10;
                k--;
            }
        }

        return num;
    }
};
