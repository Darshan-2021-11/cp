#include<bits/stdc++.h>
using namespace std;

string Solve (int N) {
	int factors[100], nf = 0;
	if (N != 1) factors[nf++] = 1;
	for (int i = 2, u; i * i <= N; ++i) {
		if (N % i) continue;
		factors[nf++] = i;
		if ((u = (N / i)) != i) factors[nf++] = u;
	}
	int sum = 0;
	for (int i = 0; i < nf; ++i) {
		sum += factors[i];
		if (sum > N) return "NO";
	}
	return sum == N ? "YES" : "NO";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++) {
        int N;
        cin >> N;
        string out = Solve(N);
        cout << out << "\n";
    }
}
