#include <bits/stdc++.h>
using namespace std;

const int N = 200'005;
int bit[N], tmp[N];

int get_parity(int *arr, int m) {
	for (int i = 0; i < m; i++)
		tmp[i] = arr[i];
	sort(tmp, tmp + m);
	int sz = unique(tmp, tmp + m) - tmp;
	for (int i = 1; i <= sz; i++)
		bit[i] = 0;
	auto upd = [&](int i) {
		for (i++; i <= sz; i += i & -i)
			bit[i]++;
	};
	auto qry = [&](int i) {
		int s = 0;
		for (i++; i > 0; i -= i & -i)
			s += bit[i];
		return s;
	};
	int p = 0;
	for (int i = m - 1; i >= 0; i--) {
		int x = lower_bound(tmp, tmp + sz, arr[i]) - tmp;
		p ^= (qry(x - 1) & 1);
		upd(x);
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int a[N], ev[N], od[N], sev[N], sod[N], res1[N], res2[N], ans[N];

	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		cin >> n;
		int ne = 0, no = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if ((i & 1) == 0)
				ev[ne++] = a[i];
			else
				od[no++] = a[i];
		}
		for (int i = 0; i < ne; i++) sev[i] = ev[i];
		for (int i = 0; i < no; i++) sod[i] = od[i];
		sort(sev, sev + ne);
		sort(sod, sod + no);
		int pe = get_parity(ev, ne);
		int po = get_parity(od, no);
		if (pe == po) {
			for (int i = 0, ie = 0, io = 0; i < n; i++) {
				if ((i & 1) == 0) ans[i] = sev[ie++];
				else ans[i] = sod[io++];
			}
		} else {
			for (int i = 0; i < ne; i++) res1[i] = sev[i];
			if (ne >= 2) swap(res1[ne - 1], res1[ne - 2]);
			for (int i = 0; i < no; i++) res2[i] = sod[i];
			for (int i = 0, ie = 0, io = 0; i < n; i++) {
			}
			for (int i = 0, ie1 = 0, io1 = 0; i < n; i++) {
				if ((i & 1) == 0) ans[i] = res1[ie1++];
				else ans[i] = sod[io1++];
			}
			for (int i = 0; i < n; i++) res1[i] = ans[i];
			for (int i = 0; i < ne; i++) res2[i] = sev[i];
			for (int i = 0; i < no; i++) res2[ne + i] = sod[i];
			if (no >= 2) swap(sod[no - 1], sod[no - 2]);
			for (int i = 0, ie2 = 0, io2 = 0; i < n; i++) {
				if ((i & 1) == 0) ans[i] = sev[ie2++];
				else ans[i] = sod[io2++];
			}
			for (int i = 0; i < n; i++) {
				if (ans[i] < res1[i]) {
					break;
				} else if (ans[i] > res1[i]) {
					for (int j = 0; j < n; j++)
						ans[j] = res1[j];
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}
