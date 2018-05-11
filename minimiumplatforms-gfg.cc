#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    int timeline[2400];
	    scanf("%d", &n);
	    int arr[n], dep[n];
	    int plats = 1;
	    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	    for(int i = 0; i < n; i++) scanf("%d", &dep[i]);
	    for(int i = 0; i < 2400; i++) timeline[i] = 0;
	    for(int i = 0; i < n; i++){
	        int arrt = arr[i];
	        int dept = dep[i];
	        if(timeline[arrt] < plats && timeline[dept] < plats) {
	            if(arrt < dept) for(int i = arrt;i < dept; i++) timeline[i]++;
	            else {
	                for(int i = arrt; i < 2400; i++) timeline[i]++;
	                for(int i = 0;i < dept; i++) timeline[i]++;
	            }
	        } else {
	            plats++;
	            if(arrt < dept) for(int i = arrt;i < dept; i++) timeline[i]++;
	            else {
	                for(int i = arrt; i < 2400; i++) timeline[i]++;
	                for(int i = 0;i < dept; i++) timeline[i]++;
	            }
	        }
	    }
	    printf("%d", plats);
	}
	return 0;
}
