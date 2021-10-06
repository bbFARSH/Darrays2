#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, int rows);
void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxValue = 100);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value1);
int* pop_back(int arr[], int& n);
int* insert(int arr[], int& n, int number, int value2);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int number1);

int** push_row_back(int** arr,  unsigned int& rows, const unsigned int cols);
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** push_row_insert(int** arr, unsigned int& rows, const unsigned int cols, const unsigned int index);
int** pop_row_back(int** arr, unsigned int& rows);
int** pop_row_front(int** arr, unsigned int& rows);
int** pop_row_erase(int** arr, unsigned int& rows, const unsigned int index);

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols);
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols);
void push_col_insert(int** arr, const unsigned int rows, unsigned int& cols,const unsigned int number);
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols);
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols);

//#define DYNAMICMEMORY_1
#define DYNAMICMEMORY_2
void main()
{
	setlocale(LC_ALL, "Ru");
#ifdef DYNAMICMEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value1;
	cout << "Введите добавляемое значение: "; cin >> value1;
	arr = push_front(arr, n, value1);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	Print(arr, n);
	arr = pop_back(arr, n);


	int value2;
	int number;
	cout << "Введите добавляемое значение: "; cin >> value2;
	cout << "Введите индекс добавляемого элемента: "; cin >> number;
	arr = insert(arr, n, number, value2);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	int number1;
	cout << "Введите индекс удаляемого элемента: "; cin >> number1;
	arr = erase(arr, n, number1);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMICMEMORY_1
	unsigned int rows;
	unsigned int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	push_col_back(arr, rows, cols);
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	int number;
	cout << "С добавлением строки" << endl; cin >> number;
	push_col_insert(arr, rows, cols, number);
	Print(arr, rows, cols);
	cout << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

#ifdef DEBUG
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}	//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);
#endif // DEBUG

}
int** allocate(int const unsigned rows, const unsigned int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete arr;
}
void FillRand(int arr[], const unsigned int n, int minRand, int maxValue)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxValue - minRand) + minRand;
	}
}
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	Print(arr, n);
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;

}
int* push_front(int arr[], int& n, int value1)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value1;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int number, int value2)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = n - 1; i >= number; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[number] = value2;
	n++;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i--] = arr[i];
	}
	n--;
	return arr;
}
int* erase(int arr[], int& n, int number1)
{
	for (int i = number1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return arr;
}
int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	//1) Создаем буферный массив указателей
	int** buffer = new int* [rows + 1];
	//2) Копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив указателей
	delete[] arr;
	//4) Подменяем исходный массив буферным
	arr = buffer;
	//5) Добавляем в исходный массив новую строку
	arr[rows] = new int[cols] {};
	//6) Увелечиваем количество строк
	rows++;	
	//7) ВОзвращаем новый массив на место вызова
	return arr;
}
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
int** push_row_insert(int** arr, unsigned int& rows, const unsigned int cols, const unsigned int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = rows - 1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, unsigned int& rows)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int** pop_row_front(int** arr, unsigned int& rows)
{
	for (int i = 1; i < rows; i++)
	{
		arr[i - 1] = arr[i];
	}
	rows--;
	return arr;
}
int** pop_row_erase(int** arr, unsigned int& rows, const unsigned int index)
{
	for (int i = index; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	rows--;
	return arr;
}
void push_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) СОЗДАЕМ БУФФЕРНУЮ СТРОКУ, РАЗМЕРОМ НА ОДИН ЭЛЕМЕНТ БОЛЬШЕ
		int* buffer = new int[cols + 1]{};
		//2) КОПИРУЕМ ИСХОДНУЮ СТРОКУ В БУФФЕРНУЮ:
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3) Удаляем исходную строку
		delete[] arr[i];
		arr[i] = buffer;
	}
	//4) В КАЖДОЙ СТРОКЕ ДОБАВИЛОСЬ ПО ЭЛЕМЕНТУ, КОЛИЧЕСТВО СТОЛБЦОВ УВЕЛЕЧИЛОСЬ НА 1.
	cols++;
}
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
void push_col_insert(int** arr, const unsigned int rows, unsigned int& cols, const unsigned int number)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
			buffer[j < number ? j : j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}