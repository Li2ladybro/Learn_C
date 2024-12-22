#include<string.h>
#include<stdio.h>
#include<math.h>
#define _CRT_SECURE_NO_DEPRECATE
int main()
{
    char ch[1000001];
    int a[200005], b[333005];
    int n, x, k1 = 0, k2 = 0;
    long long ans = 0;
    scanf("%d", &n);
    getchar();
    gets(ch);
    char* p = ch;
    while ((p = strstr(p, "Alice")) != NULL)
    {
        a[++k1] = p - ch;
        p += 5;
    }
    p = ch;
    while ((p = strstr(p, "Bob")) != NULL)
    {
        b[++k2] = p - ch;
        p += 3;
    }
    for (int i = 1, l = 1, r = 1; i <= k1; i++)
    {
        while (l <= k2 && b[l] < a[i] - n - 3) l++;
        while (r <= k2 && b[r] <= a[i] + n + 5) r++;
        ans += r - l;
    }
    printf("%lld", ans);
}