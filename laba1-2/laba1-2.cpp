#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <stdio.h>
#include <io.h>
#include <windows.h>

using namespace std;
 

struct Students
{
	string FIO;              
	int Date;
	int Group;
	double Physics;
	double Math;
	double Informatics;
	double Chemistry;
	double Ball;

	void Print()
	{
		cout << endl << "ФИО:" << FIO << endl;
		cout << "Дата рождения:" << Date << endl;
		cout << "Номер группы:" << Group << endl;
		cout << "Физика:" << Physics << endl;
		cout << "Математика:" << Math << endl;
		cout << "Информатика:" << Informatics << endl;
		cout << "Химия:" << Chemistry << endl;
		cout << "Средний балл:" << Ball << endl << endl;
	}
};
void create()
{
	ofstream File("information.dat");
	File.close();
}
void prosmotr()
{
	ifstream File("information.dat");
	vector<string> info;
	string line;
	Students infO;
	while (getline(File,line))
	{
		info.push_back(line);
	}
	for (int i = 0; i < info.size(); i += 8)         
	{
			infO.FIO = info[i];
			infO.Date = stoi(info[i+1]);
			infO.Group = stoi(info[i+2]);
			infO.Physics = stoi(info[i+3]);
			infO.Math = stoi(info[i+4]);
			infO.Informatics = stoi(info[i+5]);
			infO.Chemistry = stoi(info[i+6]);
			infO.Ball = (infO.Physics + infO.Math + infO.Informatics + infO.Chemistry) / 4;
			infO.Print();
				
	}
	File.close();
}
void correction()
{
	cout << "Добавление новых данных - 1\nУдаление старых данных - 2\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		Students fix;
		ofstream File("information.dat", ios::app);   
		cout << "ФИО:";
		cin >> fix.FIO;
		File << fix.FIO << endl;
		cout << "Год рождения:";
		cin >> fix.Date;
		File << fix.Date << endl;
		cout << "Номер группы:";
		cin >> fix.Group;
		File << fix.Group << endl;
		cout << "Физика:";
		cin >> fix.Physics;
		File << fix.Physics << endl;
		cout << "Математика:";
		cin >> fix.Math;
		File << fix.Math << endl;
		cout << "Информатика:";
		cin >> fix.Informatics;
		File << fix.Informatics << endl;
		cout << "Химия:";
		cin >> fix.Chemistry;
		File << fix.Chemistry << endl << endl;
		File.close();
	}
	if (choice == 2)
	{
		cout << "Выберите студента для удаления:" << endl;
		ifstream File("information.dat");
		string line;
		vector<string>correction;
		while (getline(File, line))
		{
			correction.push_back(line);
		}

		int erase = -1;

		int Number_of_Student = 0;
		for (int i = 0; i < correction.size(); i += 8)  
		{
			Number_of_Student++;
			cout << Number_of_Student << " - " << correction[i] << endl;
		}

		int Delete_number;
		cin >> Delete_number;     

		Number_of_Student = 0;

		for (int i = 0; i < correction.size(); i += 8)     
		{
			Number_of_Student++;
			if (Number_of_Student == Delete_number)
			{
				erase = i;
			}
		}

		if (erase > 0) 
		{
			correction.erase(correction.begin() + erase, correction.begin() + erase + 8);
		}

		ofstream LastVariant("information.dat");
		for (int i = 0; i < correction.size(); i++)
		{
			LastVariant << correction[i] << endl;
		}
		LastVariant.close();
		File.close();
	}
}
void variant_3()
{                                                      //Распечатать анкетные данные студентов-отличников из интересующей вас группы.
	ifstream File("information.dat");
	string line;
	vector<string>option;
	string Nomer_group;
	cout << "Введите номер интересующей вас группы:\t";
	cin >> Nomer_group;
	Students info;
	while (getline(File, line))
	{
		option.push_back(line);
	}
	cout << endl;

	ofstream Rezults("rezults.txt");
	for (int i = 2; i < option.size(); i += 8)         //номера групп начинаются с 3-ей строки и повторяются каждые 8 строк
	{
		if (option[i] == Nomer_group)
		{
			info.FIO = option[i - 2];
			info.Date = stoi(option[i - 1]);
			info.Group = stoi(option[i]);
			info.Physics = stoi(option[i + 1]);
			info.Math = stoi(option[i + 2]);
			info.Informatics = stoi(option[i + 3]);
			info.Chemistry = stoi(option[i + 4]);
			info.Ball = (info.Physics + info.Math + info.Informatics + info.Chemistry) / 4;
			if (info.Physics > 8 && info.Math > 8  && info.Informatics > 8 && info.Chemistry > 8)
			{
				info.Print();
				Rezults << info.FIO << endl << info.Date << endl << info.Group << endl << info.Physics << endl << info.Math << endl << info.Informatics << endl << info.Chemistry << endl << info.Ball << endl << endl;
			}
		}
	}
	File.close();
	Rezults.close();
}
void clear()
{
	system("CLS");
}
bool menu_check(int x)
{
	if (x == 0 || x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
	{
		return true;
	}
	else
	{
		cout << "Повторите ввод:";
		return false;
	}
}

int main()
{
	SetConsoleCP(1251); //задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль

	while (true)
	{
		cout << "Меню:\n";
		cout << "\tСоздать - 1\n\tПросмотр - 2\n\tКоррекция - 3\n\tРешение индивидуального задания - 4\n\tОчистить - 5\n\tВыход - 0" << endl;
		int menu;
		do
		{
			cin >> menu;
		} while (menu_check(menu) != 1);
		cout << endl;
		switch (menu)
		{
		case 1:
			create();
			break;
		case 2:
			prosmotr();
			break;
		case 3:
		    correction();
			break;
		case 4:
			variant_3();
			break;
		case 5:
			clear();
			break;
		case 0:
			return 0;
			break;
			
		}
	}
}
