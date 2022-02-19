#include<stdio.h>
#include<string.h>

//Recursively reverses strings that are delimited with the space character. 
//This function accepts the string in question and the size of that string.
//This function makes use of the string library functions: strtok, strcpy, and strcat.
void reverseString(char *str, int size)
{
	char word[21];//assumes that words are at most 20 characters long
	char* strtokInput = NULL;
	char* substrPtr;

	//if calling the 'strtok' function for the first time the actaul string must be passed to the function.
	//if the 'strtok' function has been called before, pass NULL for the next call.
	strtokInput = (size) ? str: NULL;
	
	substrPtr = strtok(strtokInput, " ");

	//if 'strtok' function returns NULL, it has reached the end of the original string.
	//When that happens, override the original string with the null character and return.
	if(substrPtr == NULL)
	{
		strcpy(str, "\0");
		return;
	}
	else//if the end of the original string has not been reached,
	{
		strcpy(word, substrPtr);//copy the word returned from 'strtok' function to 'word' variable.
	
		//call the function again and this time pass 0 as the size, so when 'strtok' function is called 
		//again it is called with NULL not the input string.
		reverseString(str, 0);

		//Once we return, concat the content of 'word' to the original string passed by the user.
		strcat(str, word);
	}

	//if size is 0 or in other words the function has been called at least once append a space character 
	if(!size)
	{
		strcat(str, " ");
	}
}

int main()
{
	return 0;
}

