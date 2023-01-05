class Solution {
public:
    string longestPrefix(const string s) {
     int n = s.length(), trace = -1;
        vector<int>map(n);
        map[0] = -1;
        for (int i = 1; i < n; i ++) {
            while (trace > -1 && s.at(trace + 1) != s.at(i)) {
               trace= map[trace];
            }
            if (s.at(trace + 1) == s.at(i)) {
                trace ++;
            }
            map[i] = trace;
        }
        return s.substr(0, trace + 1);
    }
};