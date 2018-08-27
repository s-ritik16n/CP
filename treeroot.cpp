#include<stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--){
        int sum = 0, a[30][2], i, n;
        scanf("%d",&n);
        for(size_t i = 0; i < n; i++){
            scanf("%d%d", &a[i][0], &a[i][1]);
            sum += a[i][0] - a[i][1];
        }
        printf("%d\n", n);
    }
    return 0;
}