#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve()
{
	int n, tmp = 0;
	string s;
	cin >> n;
	cin >> s;
	cout << "original: "<< s << '\n';

	bool isSok = true;

	// edge case
	if((!s[0] - '0') && (s[0] != s[n - 1])) {
		if(n != 2)
			cout << "-1\n";
		else
			cout << "0\n\n";
		return 0;
	}

	if(n != 1) {
		for(int i = 0; i <= (n >> 1); ++i) {
			if(s[i] != s[n - i - 1]) {
				isSok = false;
				break;
			}
		}
	}
	// if already pallindrome
	if(isSok) {
		cout << "0\n\n";
		return 0;
	}

	// actual solution
	vector<int> v;
	while(tmp <= (s.length() >> 1)) {
		if(s[tmp] != s[s.length() - tmp - 1]) {
			if(s[tmp] - '0') {
				v.push_back(tmp);
				s.insert(s.length() - tmp - 1, "01");
				cout << v.size() << ' ' << s << '\n';
			}
			else {
				v.push_back(tmp);
				s.insert(tmp - 1, "01");
				cout << v.size() << ' ' << s << '\n';
			}
		} else
			++tmp;
		if(s[tmp] == s[s.length() - tmp])
			++tmp;
		if(v.size() > 300) {
			cout << "-1\n";
			return 0;
		}
	}
	for(int i = 0; i <= (s.length() >> 1); ++i) {
		if(s[i] != s[n - i]) {
			isSok = false;
			break;
		}
	}
	if(!isSok) {
		cout << s << '\n';
		cout << "-1\n";
		return 0;
	}
	else {
		cout << v.size() << '\n';
		for(int i = 0; i < v.size(); ++i) {
			cout << v[i] << ' ';
		}
	}
	cout << '\n';
	return 0;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
