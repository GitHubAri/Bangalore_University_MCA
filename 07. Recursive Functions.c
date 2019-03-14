//Write a menu driven recursive program to 
//a) find factorial of a given number
//b) generate first N terms of a fibonacci sequence 
//c) GCD of three numbers. 

#include <stdio.h>
#include <stdlib.h>
long factorial(int n){
	if(n>=1)
	   return n*factorial(n-1);
	return 1;
}

int fibonacciSeris(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return (fibonacciSeris(n-1) + fibonacciSeris(n-2));
}

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
int getGCD(int arr[]) 
{ 
    int i,result = arr[0]; 
    for(i = 1; i < 4; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
} 
int main() {
	int number,arr[4];
	int ch,i,c;
	long result;
	while(1){
		printf("Factorial of a Number:                        [PRESS 1]\n");
		printf("Show first N terms of a fibonachi Sequence:   [PRESS 2]\n");
		printf("GCD of three Numbers:                         [PRESS 3]\n");
		printf("Exit:                                         [PRESS 0]\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\n\n*****Factorial of a Number*****\n\n");
				printf("Enter number:   ");
				scanf("%d", &number);
				result = factorial(number);
				printf("Facrotial of %d:   %d! = %ld\n\n",number,number,result);
				break;
			case 2:
				printf("\n\n*****Fibonachi Seris*****\n\n");
				printf("How long you want?   ");
				scanf("%d", &number);
				c = 0;
				printf("Fibonacci series\n");
				for(i= 1 ; i<=number ; i++)
				{
				   printf("%d\t", fibonacciSeris(c));
                   c++; 
                }
                printf("\n\n");
				break;
			case 3:
				printf("\n\n*****GCD of three numbers*****\n\n");
				printf("Enter three numbers\n");
				for(i = 0; i<3; i++)
				   scanf("%d", &arr[i]);
				number = getGCD(arr);
				printf("GCD = %d\n",number);
				break;
			case 0:
				exit(1);
				system("PAUSE");
			default:
				 printf("Wrong Choice !\n\n");
				 system("PAUSE");
		}
	}
	return 0;
}
