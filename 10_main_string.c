//10. Write  a  menu  driven  program  to  ......
//a) find  the  length  of  a  string  
//b) concatenate  two strings 
//c) to extract a substring from a given string 
//d) finding and replacing a string by another string in a text  ( Use pointers and user-defined functions)

#include <stdio.h>
#include <stdlib.h>

int main() {
	int ch;
	
	
	while(1){
		printf("Find the length of a String:                  [PRESS 1]\n");
		printf("Concatenate  two strings:                     [PRESS 2]\n");
		printf("Extract a substring from a given string:      [PRESS 3]\n");
		printf("finding and replacing a string:               [PRESS 4]\n");
		printf("Exit:                                         [PRESS 0]\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 0:
				exit(1);
				system("PAUSE");
			default:
				 printf("Wrong Choice !\n\n");
				 system("PAUSE");
		}
	}
	system("PAUSE");
	return 0;
}
