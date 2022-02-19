void bubbleSort(int * arr, int size)
{
	int temp = 0;

	if (size < 2)
	{
		return;
	}
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 1; j < size -1 - i; ++j)
		{
			if (*(arr) > *(arr + 1))
			{
				temp = *(arr);

				*(arr) = *(arr + 1);

				*(arr + 1) = temp;

			}
		}
	}
}