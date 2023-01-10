class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        auto cmp1 = [](const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; };
        auto cmp2 = [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> minheapcapital(cmp1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp2)> maxheapprofits(cmp2);

        for (int i = 0; i < Profits.size(); i++) {
            minheapcapital.push({Capital[i], Profits[i]});
        }

        for (int i = 0; i < k; i++) {
            while (!minheapcapital.empty() && minheapcapital.top().first <= W) {
                maxheapprofits.push(minheapcapital.top());
                minheapcapital.pop();
            }

            if (maxheapprofits.empty()) {
                break;
            }

            W += maxheapprofits.top().second;
            maxheapprofits.pop();
        }
        return W;
    }
};
