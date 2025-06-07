#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	map<int, vector<array<int, 4>>> m;
	string s;
	array<int, 2> location = { 0, 0 };
	int n, t{}, hour, id, exit, time, idtime{}, curtime, mntime = INT_MAX;
	bool possible = true;

	cin >> n;
	for (int i = 0; i < n; ++i) {

		cin >> id;

		cin >> s;
		exit = s[1] == 'x';
		cin >> s;
		switch(s[0]) {
			case 'r':
				location[0] = 0;
				t = 4;
				break;
			case 'p':
				location[0] = 1;
				t = 6;
				break;
			case 'c':
				location[0] = 2;
				t = 9;
				break;
		}
		location[1] = 0;
		while (t < (int)s.size()) {
			location[1] *= 10;
			location[1] += (s[t++] - '0');
		}

		cin >> s;
		hour = time = t = 0;
		while (s[t] != ':') {
			hour *= 10;
			hour += (s[t++] - '0');
		}
		++t;
		while (s[t] >= '0' && s[t] <= '9') {
			time *= 10;
			time += (s[t++] - '0');
		}
		if (s[t] == 'P' && hour != 12) hour += 12;
		time += hour * 60;
		m[id].push_back({ time, location[0], location[1], exit });

		/*
			 cout
			 << id << ' '
			 << exit << ' '
			 << location[0] << ' '
			 << location[1] << ' '
			 << hour << ' '
			 << time << '\n';
			 */
	}
	cin >> id;
	for (auto &[i, j]: m) {
		sort(j.begin(), j.end());
		//cout << i << ':';
		curtime = 0;
		if (j.size() & 1) {
			possible = false;
			goto print;
		}
		for (uint64_t k = 0; k < j.size(); ++k) {
			/*
			 cout
			 << j[k][0] << ' '
			 << j[k][1] << ' '
			 << j[k][2] << ' '
			 << j[k][3] << ','
			 << ' ';
			 */
			if (j[k][3] != int(k & 1)) {
				possible = false;
				goto print;
			}
			if (k & 1) {
				if (
						j[k][1] != j[k - 1][1] ||
						j[k][2] != j[k - 1][2]
					 ) {
					possible = false;
					goto print;
				}
				if (j[k][1] == 0) curtime += j[k][0] - j[k - 1][0];
			}
		}
		//cout << '\n';
		if (i == id) idtime = curtime;
		mntime = min(mntime, curtime);
	}
print:
	if (!possible) {
		cout << "Cannot be determined";
		return 0;
	}
	cout << ((idtime == mntime) ? "Yes" : "No");
}
