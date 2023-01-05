class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());
     
        int g=numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++){
            g=__gcd(g, numsDivide[i]);
        }
        

        int count=0;

        if(nums[0]>g)return -1;
        for(int i=0; i<nums.size(); i++){
            if(g%nums[i]==0){
                return count;
            }
            count++;
        }
        return -1;
    }
};