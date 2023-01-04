
#include <stdio.h>
int main(){
	int arr[5] = {3,2,1,4,0};
	int key=3;
	int c=-1;

	for (int i=0; i<5;i++){
		if (arr[i] == key){
			printf("found");
			c=1;
			break;
		}
	}
	if (c!=1){
		printf("Not Found");
	}
	return 0;
}

