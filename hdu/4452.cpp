#include <iostream>
#include <cstdio>
#include <cstring>

const int V[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int n;
int x1, y1, x2, y2;
int d1, d2, t1, t2;
int s1, s2;
int K;
char buf[100];

int get(char x) {
    if(x == 'E') return 0;
    if(x == 'N') return 1;
    if(x == 'W') return 2;
    return 3;
}

int main() {
    while(true) {
        scanf("%d", &n);
		if(!n) break;
        scanf("%s%d%d", buf, &s1, &t1);
        d1 = get(buf[0]);
        scanf("%s%d%d", buf, &s2, &t2);
        d2 = get(buf[0]);
        scanf("%d", &K);
        x1 = 1; y1 = 1;
        x2 = n; y2 = n;
        for(int i = 1; i <= K; i++) {
            for(int j = 0; j < s1; j++) {
                int tx;
                int ty;

                while(true) {
                    tx = x1 + V[d1][0];
                    ty = y1 + V[d1][1];
                    if(1 <= tx && tx <= n && 1 <= ty && ty <= n) break;
                    else d1 = (d1 + 2) % 4;
                }
                x1 = tx;
                y1 = ty;
            }


            for(int j = 0; j < s2; j++) {
                int tx;
                int ty;
                while(true) {
                    tx = x2 + V[d2][0];
                    ty = y2 + V[d2][1];
                    if(1 <= tx && tx <= n && 1 <= ty && ty <= n) break;
                    else d2 = (d2 + 2) % 4;
                }
                x2 = tx;
                y2 = ty;
            }

            if(x1 == x2 && y1 == y2) {
                std::swap(d1, d2);
            }
            else {
                if(i % t1 == 0) {
                    d1 = (d1 + 1) % 4;
                }
                if(i % t2 == 0) {
                    d2 = (d2 + 1) % 4;
                }
            }
            //std::cout << "SB1  " << x1 << " " << y1 << " " << d1 << std::endl;
            //std::cout << "SB2  " << x2 << " " << y2 << " " << d2 << std::endl;
        }
        //std::cout << std::endl;
        printf("%d %d\n", x1, y1);
        printf("%d %d\n", x2, y2);
        //std::cout << std::endl;
	}
}
