#include<stdio.h>
	
void reOrderArray(int* array,int len) {
	int i,j,temp;
    	for(i = 0; i < len - 1; i++){
        	for(j = len - 1; j > i; j--){
            		if(array[j]%2==1 && array[j-1]%2==0){
                		temp = array[j];
                		array[j] = array[j-1];
                		array[j-1] = temp;
            }
        }
    }
}

void main()
{
	int array[10] = {4,2,1,2,5,6,7,8,5,10};
	int i;
	reOrderArray(array,10);
	for(i = 0; i < 10; i++){
		printf("%d,",array[i]);
	}
}
