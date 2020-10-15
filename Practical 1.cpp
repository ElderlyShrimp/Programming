// Практическая работа №1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// 1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.

	cout << setw(15) << "int " << sizeof(int) << " байта" << endl;
	cout << setw(15) << "short int " << sizeof(short int) << " байта" << endl;
	cout << setw(15) << "long int " << sizeof(long int) << " байта" << endl;
	cout << setw(15) << "float " << sizeof(float) << " байта" << endl;
	cout << setw(15) << "double " << sizeof(double) << " байт" << endl;
	cout << setw(15) << "long double " << sizeof(long double) << " байт" << endl;
	cout << setw(15) << "char " << sizeof(char) << " байт" << endl;
	cout << setw(15) << "bool " << sizeof(bool) << " байт" << endl;

	// 2) Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.
	
	int n;
	unsigned IMask = 1 << 31;
	cout << "Введите число типа int: ";
	cin >> n;
	for (int i = 0; i < 32; i++)
	{
		if (i == 0)
		{
			putchar(n & IMask ? '1' : '0');
			cout << " ";
		}
		else
			putchar(n & IMask ? '1' : '0');
		n <<= 1;
	}
	cout << endl;

	// 3) Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.

	union {
		float fl;
		int t;
	};
	unsigned FMask = 1 << 31;
	cout << "Введите число типа float: ";
	cin >> fl;
	for (int i = 0; i < 32; i++)
	{
		if (i == 0 || i == 8)
		{
			putchar(t & FMask ? '1' : '0');
			cout << " ";
		}
		else
			putchar(t& FMask ? '1' : '0');
		t <<= 1;
	}
	cout << endl;

	// 4) Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. (*)

	union {
		double db;
		int j[2];
	};
	unsigned DMask = 1 << 31;
	cout << "Введите число типа double: ";
	cin >> db;
	for (int i = 0; i < 32; i++)
	{
		putchar(j[1] & DMask ? '1' : '0');
		if (i == 0 || i == 11) cout << "  ";
		j[1] <<= 1;
	}

	for (int i = 32; i < 65; i++)
	{
		putchar(j[0] & DMask ? '1' : '0');
		j[0] <<= 1;
	}
	return 0;
}