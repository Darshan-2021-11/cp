#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update>;

// mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// m is size of coins array (number of different coins)
int table[999];
int minCoins(vector<u32> coins, int m, int V) {
  // table[i] will be storing the minimum number of coins
  // required for i value.  So table[V] will have result

  // Base case (If given value V is 0)
  table[0] = 0;

  // Initialize all table values as Infinite
  for (int i = 1; i <= V; i++)
    table[i] = INT_MAX;

  // Compute minimum coins required for all
  // values from 1 to V
  for (int i = 1; i <= V; i++) {
    // Go through all coins smaller than i
    for (int j = 0; j < m; j++)
      if (coins[j] <= i) {
        int sub_res = table[i - coins[j]];
        if (sub_res != INT_MAX && sub_res + 1 < table[i])
          table[i] = sub_res + 1;
      }
  }

  if (table[V] == INT_MAX)
    return -1;

  return table[V];
}

int u(int t) {
  switch (t % 15) {
  case 0:
    return 0;
  case 1:
  case 3:
  case 6:
  case 10:
    return 1;
    break;
  case 2:
  case 4:
  case 7:
  case 9:
  case 11:
  case 12:
  case 13:
    return 2;
    break;
  default:
    return 3;
  }
}

int getVal(int n) {
	int ans = 0;
  if (n <= 15) {
    ans += n / 15, n = n % 15;
    switch (n) {
			case 0: break;
    case 1:
    case 3:
    case 6:
    case 10:
      ans += 1;
      break;
    case 2:
    case 4:
    case 7:
    case 9:
    case 11:
    case 12:
    case 13:
      ans += 2;
      break;
    default:
      ans += 3;
    }
  } else {
    ans += n / 15, n %= 15;
    switch (n) {
			case 0:
				break;
    case 1:
    case 3:
    case 6:
    case 10:
      ans += 1;
      break;
    case 2:
    case 4:
    case 7:
    case 9:
    case 11:
    case 12:
    case 13:
      ans += 2;
      break;
    case 5:
      ans += 1;
      break;
    case 8:
      ans += 2;
      break;
    default:
      ans += 3;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15),
      cout.setf(ios::fixed);

  u32 T = 1, n;
  cin >> T;

  vector<u32> coins = {1, 3, 6, 10, 15};

  while (T--) {
    u32 n, ans = 0;
    cin >> n;
//     minCoins(coins, coins.size(), 999 + 1);
//     for (u32 i = 0; i < 999; ++i) {
//       cout << table[i] << ' ' << getVal(i) - (n % 15 == 0 ? 3 : 0) << ' ' << i << ' ' << (getVal(i) - table[i])
//       << '\n';
//   }
    cout << getVal(n) << '\n';
  }
#ifndef ONLINE_JUDGE
  cout << '\n'
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)"
       << '\n';
#endif
}
