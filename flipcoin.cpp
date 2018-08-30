// 29-8-18
//https://www.codechef.com/problems/FLIPCOIN

#include<stdio.h>

int main(){
	int n, q;
	scanf("%d%d", &n,&q);
	int a[n][2];
	for (size_t i = 0; i < n; i++) {
		a[i][0] = -1;
		a[i][1] = -1;
	}
	while (q--) {
		/* code */
		int sum = 0;
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			int ans;
			if (a[y][1] == -1) {
				ans = a[z][1] == -1 ? 0 : a[z][1];
			} else {
				ans = a[y][0] == -1 ? a[z][1] - a[y][1] : a[z][1] - a[y][1] + 1;
			}
			printf("%d\n", ans);
		} else {
			for (size_t i = y; i <= z; i++) {
				/* code */
				if (a[i][0] == -1) {
					/* code */
					a[i][0] = 1;
					sum += 1;
					a[i][1] = sum;
				} else {
					a[i][0] = -1;
					a[i][1] = sum;
				}
			}
		}
	}
}
