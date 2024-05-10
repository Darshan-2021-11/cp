#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, x, y;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
		cin >> n >> x >> y;
		vector<u32> a(n);
		for (u32 &i: a) cin >> i;
		sort(a, a + n);
	}
}

