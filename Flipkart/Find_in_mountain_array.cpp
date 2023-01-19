/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int BSl( MountainArray &mountainArr,int l , int r , int target)
    {
         while(l<=r)
         {
             int mid = l+(r-l)/2;
             if(mountainArr.get(mid)==target) return mid;
             else if(mountainArr.get(mid)>target) r= mid-1;
             else l = mid+1;
         }
         return -1;
    }

    int BSr( MountainArray &mountainArr,int l , int r , int target)
    {
        while(l<=r)
         {
             int mid = l+(r-l)/2;
             if(mountainArr.get(mid)==target) return mid;
             else if(mountainArr.get(mid)>target) l=mid+1;
             else r=mid-1;
         }
         return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l =0, r = n-1;

        int peak;

        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                l=mid+1;
                peak = mid+1;
            }
            else r = mid;

        }

        int left = BSl(mountainArr,0,peak,target);
        int right = BSr(mountainArr,peak,n-1,target);

        return left>=0? left:right;
    }
};
