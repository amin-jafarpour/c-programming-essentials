#include<stdio.h>
#include<string.h>

//This function accepts a string and a substring and returns the index position where the substring starts
//in the string. If the string does not contain the substring, this function simply returns negative one.
int sunstringIndex(char *string, char *substring)
{
	int index = -1, loopKey = 1;

	//the string must be greater or equal to the substring. If this is not true, simply return negative one
	if(strlen(string) < strlen(substring))
	{
		return index;
	}

	for(int i = 0, j = 0; string[i] && loopKey; ++i)
	{
		if(substring[j] == '\0')//if reached the end of the substring end the loop
		{
			loopKey = 0;
		}
		else if(string[i] == substring[j])
		{
			++j;

			index = (index == -1) ? i : index; 
		}
		else
		{
			index = -1;
			j = 0;
		}

		
	}
	
	return index;
}

int main()
{
	return 0;
}