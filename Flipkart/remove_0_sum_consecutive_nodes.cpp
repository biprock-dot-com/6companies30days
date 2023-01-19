/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {

    int sum = 0;
    ListNode node(0);
    node.next = head;

    unordered_map<int, ListNode *> m = {{0, &node}};

    for(auto h = head; h; h = h->next)
    {
      sum += h->val;
      if (!m.count(sum)) m[sum] = h;

      else
    {
        int sum1 = sum;
        for (auto s = m[sum]->next; s != h; s = s->next) {
          sum1 += s->val;
          m.erase(sum1);
        }
        m[sum]->next = h->next;
      }
    }
    return node.next;
  }
};
