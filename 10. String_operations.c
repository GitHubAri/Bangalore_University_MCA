//10. Write  a  menu  driven  program  to  ......
//a) find  the  length  of  a  string  
//b) concatenate  two strings 
//c) to extract a substring from a given string 
//d) finding and replacing a string by another string in a text  ( Use pointers and user-defined functions)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int string_length(char arr[]){
	int i = 0;
	while(arr[i] != '\0'){
		i++;
	}
	return i;
}

void string_concatinate(char str1[], char str2[]){
	int i = 0,j = 0;
	while(str1[i] != '\0'){
		i++;
	}
	while(str2[j] != '\0'){
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i]  = '\0';
}
char* extract_substring(char* str, int start, int end, int len) 
{ 
	char* result;
	int i,count=0;
    if (str == 0 || strlen(str) == 0 || strlen(str) < start || strlen(str) < (start+end)) 
    	return 0; 
	else
	{
		result = (char *)malloc(sizeof(len)); 
		for(i = start-1, count = 0; i<=end; i++, count++){
			result[count]= str[i];
		}
		result[i] = '\0'; 
    	return result; 	
	}
}

char *string_replace(char *str, char *str1, char *str2){
	char *result; 
    int len1, len2, i, count = 0;
	len1 = strlen(str1); 
	len2 = strlen(str2); 
	for(i = 0; str[i] != '\0'; i++){
		if(strstr(&str[i], str1) == &str[i])
		{
			count++;
			i += len1-1;
		}
	}
	result = (char *)malloc(i + count * (len2 - len1) + 1); 
    i = 0; 
    while(*str) 
    { 
        if(strstr(str, str1) == str) 
        { 
            strcpy(&result[i], str2); 
            i += len2; 
            str += len1; 
        } 
        else
            result[i++] = *str++; 
    } 
  
    result[i] = '\0'; 
    return result; 
}

int main() {
	int ch;
	int start, end;
	char str[100],str2[100],str1[100];
	char *result = NULL;
	int length,len;
	
	while(1){
		printf("Find the length of a String:                  [PRESS 1]\n");
		printf("Concatenate  two strings:                     [PRESS 2]\n");
		printf("Extract a substring from a given string:      [PRESS 3]\n");
		printf("finding and replacing a string:               [PRESS 4]\n");
		printf("Exit:                                         [PRESS 0]\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\n\n*****Length of a String *****\n");
				printf("Enter a string: \n");
				scanf("%s",str);
				length = string_length(str);
				printf("Length of String : '%s' = %d\n\n", str,length);
				break;
			case 2:
				printf("\n\n*****Concatinate two Strings *****\n");
				printf("Enter first string: \n");
				scanf("%s",str);
				strcpy(str1,str);
				printf("Enter Secand string: \n");
				scanf("%s",str2);
				string_concatinate(str, str2);
				printf("Concatination of : '%s'    &   '%s' :\t%s \n",str1, str2, str);
				break;
			case 3:
				printf("\n\n*****Extract a sustring from a Strings *****\n");
				printf("Enter a string: \n");
				scanf("%s",str);
				len = string_length(str);
				printf("\nEnter Start: ");
				scanf("%d", &start);
				printf("\nEnter End: ");
				scanf("%d", &end);
				result = extract_substring(str, start, end, len);
				if(result != 0)
					printf("Substring of String : '%s' = '%s'\n\n", str,result);
				else
				    printf("\n\nString Extraction Not possible.\n");
				break;
			case 4:
				printf("\n\n*****String Replace with Strings *****\n");
				printf("Enter a String: \n");
				scanf("%s",str);
				printf("Enter string to find: \n");
				scanf("%s",str1);
				printf("Enter string to replace: \n");
				scanf("%s",str2);
				result = string_replace(str, str1, str2);
				printf("Replaced String: '%s'\n\n", result);
				break;
			case 0:
				printf("Thanks !   EXIT \n\n");
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
