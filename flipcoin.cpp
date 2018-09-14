// 29-8-18
//https://www.codechef.com/problems/FLIPCOIN

#include<stdio.h>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;

void build(int tree[], int arr[], int index, int lo, int hi) {
	if(lo == hi) {
		tree[index] = arr[lo];
		return;
	}
	int mid = hi + (hi-lo)/2;
	build(tree, arr, 2*index+1, lo, mid);
	build(tree, arr, 2*index+2, mid+1, hi);
	tree[index] = tree[2*index+1] + tree[2*index+2];
	return;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	int arr[n], tree[4*n];
	for(int i = 0;i < n; i++) arr[i] = 0;
	
	// build the tree
	int tree[4*n];
	build(tree, arr, 0, 0, n-1);
	for(int i = 0;i < 4*n; i++) printf("%d ", tree[i]);
	return 0;
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