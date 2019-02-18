//Q.1: Write a menu driven program to implement linear and binary search also find the
//location of its first occurrence 
#include <stdio.h>
#include <stdlib.h>

// Set of useful variables in stracture
struct st{
	int n,arr[100],key;
};

//Input data from keyboard and pass to main() 
struct st getData(){
	struct st X;
	int i;
	printf("How many numbers?   ");
	scanf("%d", &X.n);
	printf("Enter integrs one by one:   ");
	for(i = 0; i<X.n; i++){
		scanf("%d", &X.arr[i]);
	}
	printf("What you want to search?   ");
	scanf("%d", &X.key);
	return X;
}

//Execute Linear Search
void linear_Search(int key, int n, int arr[])
{
	int i,flag = 0;
	for(i = 0; i <n; i++){
		if(key == arr[i]){
			flag = 1;
	        printf("%d found at position %d.\n",key,i+1);
		}
	}
	if(flag == 0)
	   printf("%d not found in the list",key);
}

//Execute Binary Search
void binary_Search(int key, int n, int arr[])
{
	int i,j,temp;
	int low,high,mid,location;
	int flag = 0;
	for(i = 0; i<=n; ++i){
		for(j = i+1; j<=n; ++j){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
    low = 0;
    high = n-1;
    while(low<=high){
        mid = (low + high) / 2; 
		if(arr[mid] == key && n%2 == 0){
			location = mid;
            flag = 2;
            break;
        }
        else if(arr[mid] == key && n%2 != 0){
        	location = mid;
            flag = 1;
            break;
        }
        else if(arr[mid] > key)
            high = mid - 1;
		else if(arr[mid] < key)
            low = mid + 1; 
    }
    if(flag == 1)
	   printf("%d found at location %d.\n", key, location);
	else if(flag == 2)
	   printf("%d found at location %d.\n", key, location+1);
    else
	    printf("%d Not found! in the list.\n", key);
}


int main() {
	struct st X;
	int ch;
	
	//Select Choice
	while(1){
		printf("\n\n***SEARCHING***\n\n");
		printf("Linear Search: [PRESS 1]\n");
		printf("Binary Search: [PRESS 2]\n");
		printf("EXIT:          [PRESS 0]\n");
		
		scanf("%d", &ch);
		switch(ch){
			case 1:
				X = getData();
				linear_Search(X.key,X.n,X.arr);
				break;
			case 2:
				X = getData();
				binary_Search(X.key,X.n,X.arr);
				break;
		    case 0:
		    	exit(1);
		    	return 0;
		    default:
		    	printf("\nWrong Choice !\n");
		}
		
	}
	return 0;
	system("PAUSE");
}

