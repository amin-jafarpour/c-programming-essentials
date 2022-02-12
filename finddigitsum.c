//finds the sum of the digits of an integer recursively
int findDigitSum(int number)
{
	if (number < 10)
	{
		return number;
	}
	else
	{
		return findDigitSum(number / 10) + findDigitSum(number - (number / 10) * 10);
	}
}