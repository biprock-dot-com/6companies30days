class Solution {
 public:
  int distinctEchoSubstrings(string text) {

    unordered_set<string> s;

    for (int k = 1; k <= text.length() / 2; ++k) 
    { 
      int same = 0;
      for (int l = 0, r = k; r < text.length(); ++l, ++r) 
      {
        if (text[l] == text[r])
          same++;
        else
          same = 0;
        if (same == k) 
        {
          s.insert(text.substr(l - k + 1, k));
          
          same--;
        }
      }
    }

    return s.size();
  }
};
