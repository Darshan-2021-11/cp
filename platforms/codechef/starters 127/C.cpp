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
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;
	u32 n, i, idx;
	int t;
	string a, b;
	bool possible;

	while (T--) [&]() {
		possible = true;
		cin >> n >> a >> b;
		queue<u32> idxa;
		for (i = 0; i < n; ++i) {
			if (a[i] == b[i]) {
				if (a[i] == 'b') idx = i;
			} else if (a[i] == 'a' && b[i] == 'c') idxa.push(i);
			else if (a[i] == 'c' && b[i] == 'a') {
				if (idxa.size() == 0 || idxa.front() >= idx) {
					possible = false;
					break;
				} else {
					idxa.pop();
				}
			} else {
				possible = false;
				break;
			}
		}
		if (possible) cout << "YES\n";
		else cout << "NO\n";
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

