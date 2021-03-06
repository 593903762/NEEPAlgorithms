#include <stdio.h>

int main() {
    long long a, b; //使用数据类型long long确保不会溢出
    int m;
    while (scanf("%d", &m) != EOF) {
        if (m == 0)
            break; //当m等于0时退出
        scanf("%lld%lld", &a, &b); //用%lld对long long变量赋值
        a = a + b;
        int ans[50], size = 0; //ans用来保存依次转换得到的各个数位数字的值，size表示其个数
        //当a不为0时依次求各个数位上的数字值
        while (a != 0) {
            ans[size++] = a % m; //对m求模
            a /= m; //除以m
        }
        for (int i = size - 1; i >= 0; i--)
            printf("%d", ans[i]); //从高位到低位输出
        printf("\n");
    }
    return 0;
}
