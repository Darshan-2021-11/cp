#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;
using u32 = unsigned int;
using ll = long long;
using ld = long double;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

u32 n, t;
ll ans;
vector<pair<u32, u32>> inputs;
int solve() {
	ans = 0;
	cin >> n;
	inputs.reserve(3 * n);
	for (u32 i = 0; i < n; ++i) cin >> t, inputs.push_back({ t, i });
	for (u32 i = 0; i < n; ++i) cin >> t, inputs.push_back({ t, i });
	for (u32 i = 0; i < n; ++i) cin >> t, inputs.push_back({ t, i });
	sort(inputs.begin(), inputs.begin() + n, greater<pair<u32, u32>>());
	sort(inputs.begin() + n, inputs.begin() + 2 * n, greater<pair<u32, u32>>());
	sort(inputs.begin() + 2 * n, inputs.end(), greater<pair<u32, u32>>());

	for (u32 i = 0; i < 3; ++i) {
		for (u32 j = 0; j < 3; ++j) {
			for (u32 k = 0; k < 3; ++k) {
				if (inputs[i].second != inputs[n + j].second && inputs[i].second != inputs[2 * n + k].second && inputs[n + j].second != inputs[2 * n + k].second) {
					ans = max(ans, (ll)inputs[i].first + inputs[n + j].first + inputs[2 * n + k].first);
				}
			}
		}
	}

	cout << ans << '\n';
	inputs.clear();
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << "\n";
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}

