#include<stdio.h>

int main(){
	int n, q;
	scanf("%d%d", &n,&q);
	int i,a[n];
	for(i = 0;i < n; i++) a[i] = -1; 
	while(q--){
		int a, b, c, sum = 0;
		scanf("%d%d%d", &a, &b, &c);
		if(a == 0){
			for(i = b; i <= c;i++) {
				a[i] = sum+1;
				sum += 1;
			}
		}
		else{
			if(a[b] == -1)){
				if(a[c] == -1){
				
				}
				else{
				}	
			} else if(a[c] == -1) {
				
			}
		}
	}
}
