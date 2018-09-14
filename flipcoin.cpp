// 29-8-18
//https://www.codechef.com/problems/FLIPCOIN

#include<stdio.h>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	int arr[n], tree[4*n];
	for(int i = 0;i < n; i++) arr[i] = 0;
	
	// build the tree

	while(q--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a == 1) {
			// query
		}
		else{
			// update
		}
	}
}