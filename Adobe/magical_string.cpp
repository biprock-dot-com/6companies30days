class Solution {
public:
    int magicalString(int n) {
      if(n <= 0) return 0;
      if(n <= 3) return 1;
      int ans = 1;
      vector <int> nums(n);
      nums[0] = 1;
      nums[1] = 2;
      nums[2] = 2;
      int head = 2;
      int tail = 3;
      int num = 1;
      while(tail < n){
         for(int i = 0; i < nums[head]; i++){
            nums[tail] = num;
            if(num == 1 && tail < n) ans++;
            tail++;
            if(tail >= n) break;
         }
         num ^= 3;
         head++;
      }
      return ans;
    }
};
