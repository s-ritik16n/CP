// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/

// building a segment tree
// complexity -> O(N)
void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = A[start];
    }
    else{
        int mid = (start+end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

// updating a segment tree
// complexity -> O(logN)
void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        A[idx] += val;
        tree[node] += val;
    }
    else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            update(2*node, start, mid, idx, val);
        } else {
            update(2*node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

// querying a segment tree
// complexity -> O(logN)
int query()