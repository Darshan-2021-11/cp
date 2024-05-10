#include <stdio.h>

int T = 1, n, m, k, t, b_cnt[(int)1e6 + 1], a_cnt[(int)1e6 + 1], a[(int)2e5], b[(int)2e5], ans;
int main() {
  scanf("%d", &T);

  while (T--) {
    t = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d", b + i);
      ++b_cnt[b[i]];
    }
    for (int i = 0; i < m; ++i) {
      if (a_cnt[a[i]] < b_cnt[a[i]])
        ++t;
      ++a_cnt[a[i]];
    }
    ans = t >= k;
    for (int i = m; i < n; ++i) {
      if (a_cnt[a[i - m]] <= b_cnt[a[i - m]])
        --t;
      --a_cnt[a[i - m]];
      if (a_cnt[a[i]] < b_cnt[a[i]])
        ++t;
      ++a_cnt[a[i]];
      ans += (t >= k);
    }

    printf("%d\n", ans);
    for (int i = n - m; i < n; ++i) {
      --a_cnt[a[i]];
    }
    for (int i = 0; i < m; ++i) {
      --b_cnt[b[i]];
    }
  }
}

