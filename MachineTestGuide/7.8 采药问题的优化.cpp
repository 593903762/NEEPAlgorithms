#include <stdio.h>
#define INF 0x7fffffff

int max(int a, int b) {
    return a > b ? a : b;
}

struct E {
    int w;
    int v;
} list[101];

int dp[1001]; //二维数组优化为一位数组

int main() {
    int s, n;
    while (scanf("%d%d", &s, &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &list[i].w, &list[i].v);
        }
        for (int i = 0; i <= s; i++) {
            dp[i] = 0; //初始值
        }
        for (int i = 1; i <= n; i++) {
            //必须倒序更新每个dp[j]的值，j小于list[i].w的各dp[j]不作更新，保持原值，即等价于dp[i][j]=dp[i-1][j]
            for (int j = s; j >= list[i].w; j--) {
                dp[j] = max(dp[j], dp[j - list[i].w] + list[i].v); //dp[j]在原值和dp[j-list[i].w]+list[i].v中选取较大的那个
            }
        }
        printf("%d\n", dp[s]);
    }
    return 0;
}
