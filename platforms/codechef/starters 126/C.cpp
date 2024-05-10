#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(20), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;

	while (T--) []() {
		u32 n, ans;
		string s, t;
		bool original = false;
		cin >> n;
		ans = n - 2;
		cin >> s;
		for (u32 i = 2; i < n; ++i) {
			if (s[i] == s[i - 2] && s[i] == s[i - 1]) original = true, --ans;
			else if (i > 2 && (s[i] == s[i - 2] && s[i] == s[i - 3])) --ans;
		}
		cout << ans + original << '\n';
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

