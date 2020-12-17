#include<iostream>
#include<algorithm>
#include<string>

#define sizeLine 2
#define sizeColumn 9

void SortArr(int arr[][sizeColumn])
{
	for (int i = 1; i < sizeColumn; i++)
	{
		for (size_t j = i; j > 0 && arr[1][j - 1] > arr[1][j] | arr[1][j - 1] == arr[1][j]; j--)
		{
			std::swap(arr[1][j - 1], arr[1][j]);
			std::swap(arr[0][j - 1], arr[0][j]);
		}
	}
}

void PrintArr(int arr[][sizeColumn])
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

long long Reverse(long long num)
{
	long long reverse = 0;

	while (num > 0)
	{
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}

	return reverse;
}

long long MaxNumber(int cash, int arr[][sizeColumn])
{
	SortArr(arr);

	if (cash < arr[1][0])
	{
		return -1;
	}	

	PrintArr(arr);	

	long long max = 0;
	int size = cash / arr[1][0];
	int presentCost = arr[1][0];
	int presentNum = arr[0][0];
	int nextCost = arr[1][0];
	int nextNum = arr[0][0];

	if (cash % arr[1][0] == 0)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (cash == 0)
			{
				break;
			}

			max = max * 10 + presentNum;
			cash -= presentCost;
		}
	}
	else
	{
		for (size_t j = 0; j < sizeColumn; j++)
		{
			if (presentCost < arr[1][j] && presentNum < arr[0][j])
			{
				nextCost = arr[1][j];
				nextNum = arr[0][j];
				break;
			}
		}

		for (size_t i = 0; i < size; i++)
		{
			if (cash == 0)
			{
				break;
			}

			//if ((cash - presentCost) - nextCost >= presentCost || (cash - presentCost) - nextCost == 0)
			if(cash > nextCost*(size-1))
			{
				max = max * 10 + presentNum;
				cash -= presentCost;
			}
			else
			{
				if (cash - nextCost >= 0 && presentNum < nextNum)
				{
					max = max * 10 + nextNum;
					cash -= nextCost;
					continue;
				}

				max = max * 10 + presentNum;
				cash -= presentCost;
			}
		}
	}	

	return Reverse(max);
}

int main()
{
	int cash = 0;
	int arr[sizeLine][sizeColumn]{ {1, 2, 3, 4, 5, 6, 7, 8, 9} };

	std::cin >> cash;
	std::cin >> arr[1][0] >> std::skipws >> arr[1][1] >> std::skipws >> arr[1][2] >> std::skipws >> arr[1][3];
	std::cin >> arr[1][4] >> std::skipws >> arr[1][5] >> std::skipws >> arr[1][6] >> std::skipws >> arr[1][7] >> std::skipws >> arr[1][8];	

	std::cout << MaxNumber(cash, arr);	
	

	system("pause");
	return 0;
}