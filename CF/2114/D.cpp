#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC, n;
	cin >> TC;
	while (TC--) {
		cin >> n;
		vector<pair<int, int>> pts(n);
		int mnx = INT_MAX, mxx = INT_MIN, mny = INT_MAX, mxy = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> pts[i].first >> pts[i].second;
			mnx = min(mnx, pts[i].first);
			mxx = max(mxx, pts[i].first);
			mny = min(mny, pts[i].second);
			mxy = max(mxy, pts[i].second);
		}

		if (n == 1) {
			cout << "1\n";
			continue;
		}

		int smnx = INT_MAX, smxx = INT_MIN;
		int smny = INT_MAX, smxy = INT_MIN;
		for (auto &p : pts) {
			int x = p.first, y = p.second;
			if (x != mnx) smnx = min(smnx, x);
			if (x != mxx) smxx = max(smxx, x);
			if (y != mny) smny = min(smny, y);
			if (y != mxy) smxy = max(smxy, y);
		}
		if (smnx == INT_MAX) smnx = mnx;
		if (smxx == INT_MIN) smxx = mxx;
		if (smny == INT_MAX) smny = mny;
		if (smxy == INT_MIN) smxy = mxy;

		int count_mnx = 0, count_mxx = 0, count_mny = 0, count_mxy = 0;
		for (auto &p : pts) {
			if (p.first == mnx) count_mnx++;
			if (p.first == mxx) count_mxx++;
			if (p.second == mny) count_mny++;
			if (p.second == mxy) count_mxy++;
		}

		int64_t oarea = int64_t(mxx - mnx + 1) * (mxy - mny + 1);
		int64_t mp = oarea;

		for (int i = 0; i < n; ++i) {
			int x_i = pts[i].first, y_i = pts[i].second;

			int64_t new_minx = mnx, new_maxx = mxx;
			if (x_i == mnx) {
				if (count_mnx > 1) new_minx = mnx;
				else new_minx = smnx;
			}
			if (x_i == mxx) {
				if (count_mxx > 1) new_maxx = mxx;
				else new_maxx = smxx;
			}

			int64_t new_miny = mny, new_maxy = mxy;
			if (y_i == mny) {
				if (count_mny > 1) new_miny = mny;
				else new_miny = smny;
			}
			if (y_i == mxy) {
				if (count_mxy > 1) new_maxy = mxy;
				else new_maxy = smxy;
			}

			int64_t W = new_maxx - new_minx + 1;
			int64_t H = new_maxy - new_miny + 1;
			int64_t area = W * H;
			int ocnt = n - 1;

			if (area > ocnt) {
				mp = min(mp, area);
			} else {
				mp = min(mp, min((W + 1) * H, W * (H + 1)));
			}
		}

		cout << min(oarea, mp) << '\n';
	}
	return 0;
}
