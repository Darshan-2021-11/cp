#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int64_t TC = 1, q, n, v, type, head, a[N], nxt[N], prev[N], sum, w_sum;
	bool flip;
	cin >> TC;
	while (TC--) {
		flip = false;
		sum = w_sum = n = 0;
		nxt[n] = prev[n] = head = 0;
		cin >> q;
		while (q--) {
			cin >> type;
			if (type == 1) {
				if (flip)
					head = nxt[head];
				else
					head = prev[head];
				w_sum += sum - a[head] * n;
			} else if (type == 2) {
				flip = !flip;
				w_sum = sum * (n + 1) - w_sum;
				if (flip) head = prev[head];
				else head = nxt[head];
			} else {
				cin >> v;
				sum += v;
				a[n] = v;
				if (flip) {
					int r = nxt[head];
					nxt[head] = n;
					prev[n] = head;
					nxt[n] = r;
					prev[r] = n;
				} else {
					int l = prev[head];
					nxt[l] = n;
					prev[n] = l;
					prev[head] = n;
					nxt[n] = head;
				}
				n++;
				w_sum += v * n;
			}
			/*
				 for (int i = 0; i < n; ++i) cout << a[i] << ' ';
				 cout << '\n';
				 for (int i = 0; i < n; ++i) cout << nxt[i] << ' ';
				 cout << '\n';
				 for (int i = 0; i < n; ++i) cout << prev[i] << ' ';
				 cout << '\n';
				 cout << head << ' ' << flip << ' ';
				 */
			cout << w_sum << '\n';
		}
	}
}
