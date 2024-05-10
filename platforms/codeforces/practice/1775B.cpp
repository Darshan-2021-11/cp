#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 a[(u32)2e5], T = 1, n, p, t;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
		cin >> n;
		vector<vector<u32>> k(n);
		for (u32 i = 0; i < n; ++i) {
		  cin >> p;
		  k[i].reserve(p);
			for (u32 j = 0; j < p; ++j) { cin >> t; k[i].emplace_back(t), ++a[t]; }
		}
		bool allPresent = true;
		for (u32 i = 0; i < n; ++i) {
			allPresent = true;
			for (u32 j = 0; j < k[i].size(); ++j) allPresent &= a[k[i][j]] > 1;
			if (allPresent) {
				break;
			}
		}
		cout << (allPresent ? "YES\n": "NO\n");
		for (u32 i = 0; i < n; ++i) {
			for (u32 j = 0; j < k[i].size(); ++j) a[k[i][j]] = 0;
		}
	}
}

