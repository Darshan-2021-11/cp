#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, ans, sz, mid;
class HashedString {
  private:
    // change M and B if you want
    static const long long M = 1e9 + 9;
    static const long long B = 9973;

    // pow[i] contains B^i % M
    static vector<long long> pow;

    // p_hash[i] is the hash of the first i characters of the given string
    vector<long long> p_hash;

  public:
    HashedString(const string &s) : p_hash(s.size() + 1) {
      while (pow.size() <= s.size()) { pow.push_back((pow.back() * B) % M); }

      p_hash[0] = 0;
      for (int i = 0; i < s.size(); i++) {
        p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
      }
    }

    long long get_hash(int start, int end) {
      long long raw_val =
        (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
      return (raw_val % M + M) % M;
    }
};
vector<long long> HashedString::pow = {1};

static string s;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    ans =  0;
    cin >> s;
    sz = s.size();
    if (sz & 1) {
      cout << 0 << '\n';
      continue;
    }
    HashedString h(s);
    if (h.get_hash(0, (sz >> 1) - 1) == h.get_hash(sz >> 1, sz - 1)) ans += 2;
    for (i32 i = 1; i < (sz >> 1); ++i) {
      mid = i << 1;
      if (
          h.get_hash(0, (mid >> 1) - 1) == h.get_hash(mid >> 1, mid - 1) &&
          h.get_hash(mid, ((sz + mid) >> 1) - 1) == h.get_hash((sz + mid) >> 1, sz - 1)
         )
        ++ans;
    }
    cout << ans << '\n';
  }
}
