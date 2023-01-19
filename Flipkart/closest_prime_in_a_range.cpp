class Solution {
  public:
    vector <int> closestPrimes (int left, int right) {
      constexpr int max = 1000000 + 420;
      
      vector <int> primes;
      vector <bool> sieve (max, true);
      
      sieve[0] = false;
      sieve[1] = false;
      
      for (int i = 2; i < max; ++i) {
        if (sieve[i]) {
          primes.push_back(i);
          for (int j = 2 * i; j < max; j += i)
            sieve[j] = false;
        }
      }
      
      int l = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
      int r = upper_bound(primes.begin(), primes.end(), right) - primes.begin() - 1;
      int a = -max, b = max;
      
      for (int i = l; i < r; ++i) {
        if (primes[i + 1] - primes[i] < b - a) {
          a = primes[i];
          b = primes[i + 1];
        }
      }
      
      if (a == -max) {
        a = -1;
        b = -1;
      }
      
      return {a, b};
    }
};
