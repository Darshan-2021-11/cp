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

	while (T--) {
		int n;
		cin >> n;
		vector<ll> a(n), b(n);
		cin >> a[0];
		for (int i = 1; i < n; ++i) { cin >> a[i]; a[i] += a[i - 1]; }
		cin >> b[0];
		for (int i = 1; i < n; ++i) { cin >> b[i]; b[i] += b[i - 1]; }

		array<vector<ll>, 2> odd = { vector<ll>((n + 1) >> 1), vector<ll>((n + 1) >> 1) }, even = { vector<ll>(n >> 1), vector<ll>(n >> 1) };
		for (int i = 0; i < n; ++i) {
			if (i & 1) even[0][i >> 1] = a[i], even[1][i >> 1] = b[i];
			else odd[0][(i + 1) >> 1] = a[i], odd[1][(i + 1) >> 1] = b[i];
		}
		sort( odd[0].begin(),  odd[0].end());
		sort( odd[1].begin(),  odd[1].end());
		sort(even[0].begin(), even[0].end());
		sort(even[1].begin(), even[1].end());
		if (odd[0] == odd[1] && even[0] == even[1] && a[n - 1] == b[n - 1]) cout << "YES\n";
		else cout << "NO\n";
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

