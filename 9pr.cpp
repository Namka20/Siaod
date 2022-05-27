#include "iostream"
#include "windows.h"

int max_razr(int chislo)
{
 int max = 0;
 while (chislo > 1)
    {
 chislo /= 10;
 max++;
    }
 return max;
}

int velich_razr(int chislo, int razr)
{
 while (razr > 1)
    {
 chislo /= 10;
 razr--;
    }
 return chislo % 10;
}

void sort_razr(int** dop_mas, int* mas, int razr,int n)
{
 int* mas_col, i, j, temp = 0;
 mas_col = new int[n];
 for (i = 0; i < n; i++)
 mas_col[i] = 0;
 for (i = 0; i < n; i++)
    {
 int a = velich_razr(mas[i], razr);
 dop_mas[mas_col[a]][a] = mas[i];
 mas_col[a]++;
    }
 for (i = 0; i < n; i++)
    {
 for (j = 0; j < mas_col[i]; j++)
        {
 mas[temp] = dop_mas[j][i];
 temp++;
        }
    }
}

int main()
{
     setlocale(0, "rus");
 using namespace std;
 int n, col_razr = 0;
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 int razr, i, * mas, ** dop_mas;
 cout << "Введите размер последовательности: ";
 cin >> n;
 mas = new int[n];
 cout << "Введите элементы последовательности: " << endl;
 for (int i = 0; i < n; i++) //Рандом заполнение массива
    {
 mas[i] = rand() % 100; // заполняем массив случайными числами
 cout << "[" << i + 1 << "]="<<mas[i]<<endl;
    }
 dop_mas = new int* [n];
 for (i = 0; i < n; i++)
 dop_mas[i] = new int[n];
 for (i = 0; i < n; i++)
 if (col_razr < max_razr(mas[i]))
 col_razr = max_razr(mas[i]);
 for (razr = 1; razr <= col_razr; razr++)
 sort_razr(dop_mas, mas, razr,n);
 for (i = 0; i < n; i++)
 cout << mas[i] << endl;
 return 0;
}
