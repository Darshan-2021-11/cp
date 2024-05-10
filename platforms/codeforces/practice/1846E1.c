#include <stdio.h>
#include <stdbool.h>
typedef unsigned int u32;

u32 T = 1, n;
bool possible[(u32)1e6 + 1];
int main() {
  for (u32 i = 2, j; (j = i * i + i + 1) < (u32)1e6 + 1; ++i)
    do possible[j] = true; while((j = j * i + 1) < (u32)1e6 + 1);
  scanf("%d", &T);

  while (T--) {
    scanf("%d", &n);
    printf("%s", possible[n] ? "YES\n" : "NO\n");
  }
}
