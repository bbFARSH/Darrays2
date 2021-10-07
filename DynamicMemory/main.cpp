#include <iostream>
using std::cin;
using std::endl;
using std::cout;

template<typename T>T** allocate(const unsigned int rows, const unsigned int cols);
template<typename T>void clear(T** arr, const unsigned int rows);
void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxValue = 100);
void FillRand(double arr[], const unsigned int n, int minRand = 0, int maxValue = 100);
void FillRand(char arr[], const unsigned int n);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const unsigned int rows, const unsigned int cols);
template<typename T>void Print(T arr[], const unsigned int n);
template<typename T>void Print(T** arr, const unsigned int rows, const unsigned int cols);
template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* push_front(T arr[], int& n, T value1);
template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* insert(T arr[], int& n, int number, T value2);
template<typename T>T* pop_front(T arr[], int& n);
template<typename T>T* erase(T arr[], int& n, int number1);

template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** push_row_insert(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int index);
template<typename T>T** pop_row_back(T** arr, unsigned int& rows);
template<typename T>T** pop_row_front(T** arr, unsigned int& rows);
template<typename T>T** pop_row_erase(T** arr, unsigned int& rows, const unsigned int index);

template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void push_col_front(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void push_col_insert(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int  number);
template<typename T>void pop_col_back(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols);

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
	int** arr = allocate<int>(rows, cols);
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
template<typename T>T** allocate(const unsigned rows, const unsigned int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
	return arr;
}
template<typename T>void clear(T** arr, const unsigned int rows)
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
void FillRand(double arr[], const unsigned int n, int minRand, int maxValue)
{
	for (int i = 0; i < n; i++)
	{
		minRand *= 100;
		maxValue *= 100;
		arr[i] = rand() % (maxValue - minRand) + minRand;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
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
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template<typename T>void Print(T arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const unsigned int rows, const unsigned int cols)
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

template<typename T>T* push_back(T arr[], int& n, T value)
{
	Print(arr, n);
	T* buffer = new T[n + 1];
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
template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T* push_front(T arr[], int& n, T value1)
{
	T* buffer = new T[n + 1];
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
template<typename T>int* insert(T arr[], int& n, int number, T value2)
{
	T* buffer = new T[n + 1];
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
template<typename T>T* pop_front(T arr[], int& n)
{
	for (int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	n--;
	return arr;
}
template<typename T>T* erase(T arr[], int& n, int number1)
{
	for (int i = number1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return arr;
}
template<typename T>T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols)
{
	//1) Создаем буферный массив указателей
	T** buffer = new T* [rows + 1];
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
	arr[rows] = new T[cols] {};
	//6) Увелечиваем количество строк
	rows++;	
	//7) ВОзвращаем новый массив на место вызова
	return arr;
}
template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[cols] {};
	rows++;
	return arr;
}
template<typename T>T** push_row_insert(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int index)
{
	T** buffer = new T* [rows + 1];
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
	arr[index] = new T[cols] {};
	rows++;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, unsigned int& rows)
{
	T** buffer = new T* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
template<typename T>T** pop_row_front(T** arr, unsigned int& rows)
{
	for (int i = 1; i < rows; i++)
	{
		arr[i - 1] = arr[i];
	}
	rows--;
	return arr;
}
template<typename T>T** pop_row_erase(T** arr, unsigned int& rows, const unsigned int index)
{
	for (int i = index; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	rows--;
	return arr;
}
template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) СОЗДАЕМ БУФФЕРНУЮ СТРОКУ, РАЗМЕРОМ НА ОДИН ЭЛЕМЕНТ БОЛЬШЕ
		T* buffer = new T[cols + 1]{};
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
template<typename T>void push_col_front(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols+1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void pop_col_back(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
template<typename T>void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
template<typename T>void  push_col_insert(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int number)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
			buffer[j < number ? j : j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}