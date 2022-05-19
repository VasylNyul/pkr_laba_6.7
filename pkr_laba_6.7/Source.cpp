#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct StElem1
{
	StElem1* link;
	int potnumber;
	int time;
	int numberk;
};

void CreateList1(StElem1*& first1, StElem1*& last1, int N);
void AddElem(StElem1*& first1, StElem1*& last, int potnumber1, int time);
void Print(StElem1* first, int i);
void Scanning(StElem1*& first1, StElem1*& last1, StElem1*& first2, StElem1*& last2, int x1, int x2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	StElem1* first1 = NULL,
		* last1 = NULL;
	StElem1* first2 = NULL,
		* last2 = NULL;

	int N;
	int x1;
	int x2;

	cout << "Введіть кількість потягів в списку: "; cin >> N;
	cout << endl;
	CreateList1(first1, last1, N);
	cout << endl;
	for (int i = 0; i < 3; i++)
		Print(first1, i);
	cout << endl;
	cout << "Вивід потягів які прибули у діапазоні часу :" << endl;
	cout << "З : "; cin >> x1; 
	cout << "До : "; cin >> x2;
	cout << "Потяги, які прибули в вказаному діапазоні часу:" << endl;

	cout << endl;
	Scanning(first1, last1, first2, last2, x1, x2);
	for (int i = 0; i < 3; i++)
		Print(first2, i);

	system("pause");
	return 0;
}

void CreateList1(StElem1*& first1, StElem1*& last1, int N)
{
	int potnumber;
	int time;
	for (int i = 0; i < N; i++)
	{
		cin.sync();
		cout << "Номер потяга: "; cin >> potnumber;
		do
		{
			cout << "Час прибуття потяга: "; cin >> time;
		} while (!(0 < time && time < 24));
		AddElem(first1, last1, potnumber, time);
		cout << endl << endl;
	}
}


void AddElem(StElem1*& first1, StElem1*& last1, int potnumber, int time)
{
	StElem1* tmp = new StElem1;
	tmp->potnumber = potnumber;
	tmp->time = time;
	tmp->numberk = NULL;
	tmp->link = NULL;
	if (last1 != NULL)
		last1->link = tmp;
	last1 = tmp;
	if (first1 == NULL)
		first1 = tmp;
}

void Print(StElem1* first, int i)
{
	while (first != NULL)
	{
		if (i == 0)
			cout << "| " << setw(8) << first->potnumber << " ";
		else if (i == 1)
			cout << "| " << setw(8) << first->time << " ";
		else
			cout << "| " << setw(8) << first->numberk << " ";



		first = first->link;
	}
	cout << "|" << endl;
}

void CreateSecondList(StElem1*& first2, StElem1*& last2, int potnumber, int time)
{
	int numberk;
	cout << "Номер колії: "; cin >> numberk;
	StElem1* tmp = new StElem1;
	tmp->potnumber = potnumber;
	tmp->time = time;
	tmp->numberk = numberk;
	tmp->link = NULL;
	if (last2 != NULL)
		last2->link = tmp;
	last2 = tmp;
	if (first2 == NULL)
		first2 = tmp;
}

void Scanning(StElem1*& first1, StElem1*& last1, StElem1*& first2, StElem1*& last2, int x1, int x2)
{
	while (first1 != NULL)
	{
		if (x1 <= first1->time && first1->time <= x2)
		{
			CreateSecondList(first2, last2, first1->potnumber, first1->time);
		}
		first1 = first1->link;
	}
}



