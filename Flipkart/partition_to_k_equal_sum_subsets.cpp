class Solution {
public:

    bool partition(vector<int>& nums , vector<int>&subsetsum, vector<bool>&used,int subset,int k, int curr_index,int limit)
    {
        if(subsetsum[curr_index]==subset)
        {
            if(curr_index==k-2) return true;

            return  partition(nums,subsetsum,used,subset,k,curr_index+1,nums.size()-1);
        }

        for(int i=limit ; i>=0; i--)
        {
            if(used[i]) continue;

            int temp = subsetsum[curr_index]+nums[i];

            if(temp<=subset)
            {
                used[i]=true;
                subsetsum[curr_index]+=nums[i];
                bool next =  partition(nums,subsetsum,used,subset,k,curr_index,i-1);

                used[i]=false;
                subsetsum[curr_index]-=nums[i];

                if(next) return true;

            }
        }
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1) return true;
        if(nums.size()<k) return false;

        int sum =0;

        for(int i=0; i<nums.size(); i++)
         sum+=nums[i];
        
        if(sum%k!=0) return false;

        int subset = sum/k;
        vector<int>subsetsum(k);
        vector<bool>used(nums.size());

        for(int i=0; i<k ;i++)
         subsetsum[i]=0;
        
        for(int i=0; i<nums.size(); i++)
         used[i] = false;

        subsetsum[0] = nums[nums.size()-1];
        used[nums.size()-1]= true;

        return partition(nums,subsetsum,used,subset,k,0,nums.size()-1);
    }
};
