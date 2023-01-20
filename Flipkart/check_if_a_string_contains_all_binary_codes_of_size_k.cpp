class Solution {
public:
    bool hasAllCodes(string S, int K) 
    {
        int count = 1 << K;

        if (K > S.size()) return false;

        int num = K > 1 ? stoi(S.substr(S.size() - K + 1), 0, 2) << 1 : 0;

        vector<bool> visited(count, false);

        for (int i =S.size() - K; ~i; i--) 
        {
            num = (((S[i] - '0') << K) + num) >> 1;

            if (!visited[num])
            {
                visited[num] = true;
                count--;
            } 
            if (!count) return true;

            if (i < count) return false;
        }
        return false;
    }
};
