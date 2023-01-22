class Solution {
 public:
  int totalFruit(vector<int>& fruits) {

    int max_fruit = 0;

    unordered_map<int, int> count;

    for (int l = 0, r = 0; r < fruits.size(); ++r) 
    {
      count[fruits[r]]++;

      while (count.size() > 2) 
      {
        if (--count[fruits[l]] == 0)
          count.erase(fruits[l]);

        l++;
      }
      max_fruit = max(max_fruit, r - l + 1);
    }

    return max_fruit;
  }
};
