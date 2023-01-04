class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    vector<int>v;

    for (int i = 0; i < nums1.size(); ++i)
      v.push_back(nums1[i] - nums2[i]);

    long long ans = 0;
    mergeSort(v, 0, v.size() - 1, diff, ans);
    return ans;
  }

 private:
  void mergeSort(vector<int>& v, int l, int r, int diff, long long& ans) {
    if (l >= r)
      return;

    const int mid = (l + r) / 2;
    mergeSort(v, l, mid, diff, ans);
    mergeSort(v, mid + 1, r, diff, ans);
    merge(v, l, mid, r, diff, ans);
  }

  void merge(vector<int>& v, int l, int mid, int r, int diff, long long& ans) {
    const int low = mid + 1;
    int high = mid + 1;  
   
    for (int i = l; i <= mid; ++i) {
      while (high <= r && v[i] > v[high] + diff)
        high++;
      ans += r - high + 1;
    }

    vector<int> sorted(r - l + 1);
    int k = 0;     
    int i = l;      
    int j = mid + 1;  
    while (i <= mid && j <= r)
      if (v[i] < v[j])
        sorted[k++] = v[i++];
      else
        sorted[k++] = v[j++];

   
    while (i <= mid)
      sorted[k++] = v[i++];

    
    while (j <= r)
      sorted[k++] = v[j++];

    copy(begin(sorted), end(sorted), begin(v) + l);
  }
};
                                                                      