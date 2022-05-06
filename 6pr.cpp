#include <iostream>
#include <fstream>
using namespace std;

int pos(const char* s, const char* p, int n)
{
	int i, j; // Счетчики для циклов
	int lenC, lenS; // Длины строк

	//Находим размеры строки исходника и искомого
	for (lenC = 0; p[lenC]; lenC++);
	for (lenS = 0; s[lenS]; lenS++);

	for (i = 0; i <= lenS - lenC; i++) // Пока есть возможность поиска
	{
		for (j = 0; s[i + j] == p[j]; j++); // Проверяем совпадение посимвольно
		// Если посимвольно совпадает по длине искомого
		// Вернем из функции номер ячейки, откуда начинается совпадение
		// Учитывать 0-терминатор  ( '\0' )
		if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) return i;
		if (j == lenC)
			if (n - 1) n--;
			else return i;
	}
	//Иначе вернем -1 как результат отсутствия подстроки
	return -1;
}

int main()
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	string a;
	char buff[5000]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("С:\\text.txt"); // открыли файл для чтения "указать путь к имени файла"
	while (!fin.eof())//Цикл для считывания файла
	{
		fin.getline(buff, sizeof(buff));
		cout << buff << endl;
	}
	cin >> a;//Вводим строку
	const char* s = buff;//Должен быть текст
	const char* p = a.c_str();//Вводилось с клавы
	int i, n = 0;
	for (i = 1; n != -1; i++)//Вывод позиций строки
	{
		n = pos(s, p, i);

		if (n >= 0)
			cout << n << endl;
	}
} 