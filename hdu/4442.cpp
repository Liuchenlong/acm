#include <iostream>
#include <algorithm>
#include <cstdio>

const int maxn = 100010;
const long long mod = 365LL * 24LL * 60LL * 60LL;
std::pair<long long, long long>q[maxn];
int n;

int cmp(std::pair<long long, long long>a, std::pair<long long, long long>b) {
    return a.first * b.second < a.second * b.first;
}


int main() {
    while(true) {
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i < n; i++) {
            scanf("%I64d%I64d", &q[i].first, &q[i].second);
        }
        sort(q, q + n, cmp);
        long long ans = 0;
        long long t = 0;
        for(int i = 0; i < n; i++) {
            long long tmp = q[i].first + q[i].second * t;
            tmp %= mod;
            ans += q[i].first + q[i].second * t;
            t += tmp;
            ans %= mod;
            t %= mod;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
