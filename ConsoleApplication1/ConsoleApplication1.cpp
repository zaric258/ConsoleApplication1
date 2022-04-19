#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <io.h> 
#include <windows.h> 
#include <direct.h>
using namespace std;


struct Film
{
	int id;
	char time[120];
	char name_film[120];
	int mest[15][10] = { 0 };
	char mest_clad[15][10]{ "0" };
	char price[120];
};

void ing_an_array(Film*& f, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Введите время начала сеанса: " << endl;
		gets_s(f[i].time, 120);
		cout << "Введите название фильма:  " << endl;
		gets_s(f[i].name_film, 120);
		cout << "Введите цену сеанса:  " << endl;
		gets_s(f[i].price, 120);
		for (size_t m = 0; m < 15; m++)
		{
			for (size_t n = 0; n < 10; n++)
			{
				f[i].mest[m][n] = 0;
			}
		}
		f[i].id = i;
	}
}

void Creating_an_array(Film*& f, int size)
{
	f = new Film[size];
	ing_an_array(f, size);
}

void Editing_elements(Film*& f)
{
	int index;
	cout << " " << endl;
	cin >> index;
	cin.ignore();
	cout << "Введите время начала сеанса: " << endl;
	gets_s(f[index].time, 120);
	cout << "Введите название фильма:  " << endl;
	gets_s(f[index].name_film, 120);
	cout << "Введите цену сеанса:  " << endl;
	gets_s(f[index].price, 120);
}

void Array_Output(Film*& f, int index)
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (size_t i = 0; i < 15; i++)
	{
		if (i <= 9)
		{
			cout << " ";
		}
		cout << i;
		for (size_t j = 0; j < 10; j++)
		{
			cout << " " << f[index].mest[i][j];
		}
		cout << endl;
	}
}

void Print(Film*& f, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Имя фильма: " << f[i].name_film << "\t";
		cout << "Время сеанса: " << f[i].time << endl;
		cout << "Цена сеанса: " << f[i].price << endl;
		Array_Output(f, i);
	}
}

void Removing_elements(Film*& f, int size)
{
	int index;
	cout << "Введите индекс: " << endl;
	cin >> index;
	int count = 0;
	Film* tmp = new Film[size - 1];
	for (size_t i = 0; i < size - 1; i++)
	{
		if (f[i].id < index)
		{
			tmp[count] = f[i];
			count++;
		}
		else if (f[i].id == index)
		{
			tmp[count] = f[i + 1];
			count++;
		}
		else
		{
			tmp[count] = f[i + 1];
			count++;
		}
	}
	size--;
	f = nullptr;
	f = new Film[size];
	f = tmp;
	tmp = nullptr;
}

Film* Deleting_an_array(Film*& f, int size)
{
	f = nullptr;
	Creating_an_array(f, size);
	return f;
}

void Save_to_file(Film* f, int size)
{
	FILE* file;
	fopen_s(&file, "ticket.txt", "w");
	for (int i = 0; i < size; i++)
	{
		fputs(f[i].name_film, file);
		fputc('\n', file);
		fputs(f[i].time, file);
		fputc('\n', file);
		fputs(f[i].price, file);
		fputc('\n', file);
		char fin[2];
		for (int k = 0; k < 15; k++)
		{
			for (int j = 0; j < 10; j++)
			{
				_itoa_s(f[i].mest[k][j], fin, 10);
				fputs(fin, file);
				fputc(' ', file);
			}
			fputc('\n', file);
		}
	}
	fclose(file);
}

void Loading_from_a_file()
{

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Film* films = nullptr;
	int size;
	int mains;
	cout << "Enter size: " << endl;
	cin >> size;


	do
	{
		cout << "\t\t\t\t\t-----Вас приветствует Кинотеатр Люкс-----" << endl;
		cout << "1 - Ввод даных;\n2 - Редактирование элементов;\n3 - Вывод массива;\n4 - Удаление элементов;\n5 - Удаление массива;\n6 - Сохранение в файл;\n7 - Загрузка из файла;\n";
		cin >> mains;
		cin.ignore();
		switch (mains)
		{
		case 1:
			Creating_an_array(films, size);
			break;

		case 2:
			Editing_elements(films);
			break;

		case 3:
			Print(films, size);
			break;

		case 4:
			Removing_elements(films, size);
			break;

		case 5:
			films = Deleting_an_array(films, size);
			break;

		case 6:
			Save_to_file(films, size);
			break;

		case 7:
			Loading_from_a_file();
			break;
		}
	} while (mains != 0);
}