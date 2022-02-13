//returns 1 if the param string is a Palindrome and false otherwise. The function takes a char array and the size of the char array excluding the null character 
int isPalindrome(char* string, int size)
{

	if (*string != *(string + size - 1))
	{
		return 0;
	}
	else if (string == (string + size - 1) || (string + size - 1) - string == 1 && *string == *(string + size - 1))
	{
		return 1;
	}
	else
	{
		isPalindrome(string + 1, size - 2);
	}
}