#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t ans = 0;
	int TC = 0, i, j, an, bn;
	char a[N], b[N], c;
	while ((c = getchar()) != '\n') TC = TC * 10 + (c - '0');
	while (TC--) {
		ans = an = bn = 0;
		while ((a[an] = getchar()) != '\n') ++an;
		while ((b[bn] = getchar()) != '\n') ++bn;

		if (an < bn) {
			ans = -1;
			goto print;
		}


print:
		printf("%lld\n", ans);
	}
}
