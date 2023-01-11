class Solution {
public:
    int findIntegers(int n) {
        return 1 + totalvalid(1,n);
    }
private:
    int totalvalid(int num , int limit)
    {
        if(num>limit) return 0;

        if(num & 1)
          return 1 + totalvalid((num<<1)|0,limit);

        else 
          return 1 + totalvalid((num<<1)|0,limit) + totalvalid((num<<1)|1,limit);
    }
};
