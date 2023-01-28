class Solution {
public:
    string predictPartyVictory(string senate) {
        const int n = senate.length();
        queue<int> R;
        queue<int> D;

      for (int i = 0; i < n; ++i)
        if (senate[i] == 'R')
           R.push(i);
        else
          D.push(i);

      while (!R.empty() && !D.empty()) 
      {
        const int indexR = R.front();
        R.pop();
        const int indexD = D.front();
        D.pop();
        if (indexR < indexD)
          R.push(indexR + n);
        else
         D.push(indexD + n);
      }

      return R.empty() ? "Dire" : "Radiant";
    }
};
