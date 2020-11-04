#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <stdio.h>
#include <io.h>
#include <windows.h>

using namespace std;

bool check(int x)
{
	if (x == 1 || x == 2)
	{
		return true;
	}
	else
	{
		cout << "Повторите ввод:";
		return false;
	}
}
struct Date_base
{
	string FIO;
	int Group;
	int sr_ball;
	int money_mam;
	int money_dad;


	void Print()
	{
		cout << endl << "ФИО:" << FIO << endl;
		cout << "Номер группы:" << Group << endl;
		cout << "Средний балл:" << sr_ball << endl;
		cout << "Доход мамы:" << money_mam << endl;
		cout << "Доход папы:" << money_dad << endl<<endl;
		
		
	}
};
void quickSort(vector<Date_base>& database, int key, int low, int high) {
	int i = low;
	int j = high;

	if (key == 1) 
	{
		int x = database[(i + j) / 2].sr_ball;

		while (i <= j) {
			while (database[i].sr_ball > x)i++;
			while (database[j].sr_ball < x)j--;
			if (i <= j) 
			{
				swap(database[i], database[j]);
				i++;
				j--;
			}
		}
		if (j > low)quickSort(database, key, low, j);
		if (i < high)quickSort(database, key, i, high);
	}
	if (key == 2) 
	{
		int x = database[(i + j) / 2].Group;

		while (i <= j) {
			while (database[i].Group > x)i++;
			while (database[j].Group < x)j--;
			if (i <= j)
			{
				swap(database[i], database[j]);
				i++;
				j--;
			}
		}
		if (j > low)quickSort(database, key, low, j);
		if (i < high)quickSort(database, key, i, high);
	}
	if (key == 3)
	{
		int x = database[(i + j) / 2].money_mam;

		while (i <= j) {
			while (database[i].money_mam > x)i++;
			while (database[j].money_mam < x)j--;
			if (i <= j)
			{
				swap(database[i], database[j]);
				i++;
				j--;
			}
		}
		if (j > low)quickSort(database, key, low, j);
		if (i < high)quickSort(database, key, i, high);
	}
	if (key == 4)
	{
		int x = database[(i + j) / 2].money_dad;

		while (i <= j) {
			while (database[i].money_dad > x)i++;
			while (database[j].money_dad < x)j--;
			if (i <= j)
			{
				swap(database[i], database[j]);
				i++;
				j--;
			}
		}
		if (j > low)quickSort(database, key, low, j);
		if (i < high)quickSort(database, key, i, high);
	}
}
void create()
{
	ofstream File("information.txt");
	File.close();
}
void prosmotr()
{
	ifstream File("information.txt");
	vector<string> info;
	string line;
	Date_base infO;
	while (getline(File, line))
	{
		info.push_back(line);
	}
	for (int i = 0; i < info.size(); i += 5)
	{
		infO.FIO = info[i];
		infO.Group = stoi(info[i + 1]);
		infO.sr_ball = stoi(info[i+2]);
		infO.money_mam = stoi(info[i + 3]);
		infO.money_dad = stoi(info[i + 4]);
		infO.Print();

	}
	File.close();
}
void correction()
{
		Date_base fix;
		ofstream File("information.txt", ios::app);
		cout << "ФИО:";
		cin >> fix.FIO;
		File << fix.FIO << endl;
		cout << "Номер группы:";
		cin >> fix.Group;
		File << fix.Group << endl;
		cout << "Средний балл:";
		cin >> fix.sr_ball;
		File << fix.sr_ball << endl;
		cout << "Доход мамы:";
		cin >> fix.money_mam;
		File << fix.money_mam << endl;
		cout << "Доход папы:";
		cin >> fix.money_dad;
		File << fix.money_dad << endl;
		File.close();
}
void find_line()
{
	int key;
	int num=-1;
	ifstream File("information.txt");
	vector<string> info;
	string line;
	Date_base infO;
	while (getline(File, line))
	{
		info.push_back(line);
	}
	cout<<("Выберите критерий поиска: 1- группа, 2- средний балл, 3- доход мамы, 4- доход папы");
	cin >> key;
	if (key == 1)
	{
		string gr;
		cout << "введите группу";
		cin >> gr;
		for (int i = 1; i < info.size(); i += 5)
		{
			if (info[i] == gr)
			{
				num = i;
			infO.FIO = info[num-1];
			infO.Group = stoi(info[num]);
			infO.sr_ball = stoi(info[num + 1]);
			infO.money_mam = stoi(info[num + 2]);
			infO.money_dad = stoi(info[num + 3]);
			infO.Print();
			}
		}
		if (num < 0)
		{
			cout << "такого нет";
		}
	}
	if (key == 2)
	{
		string sr_ball;
		cout << "введите средний балл"<<endl;
		cin >> sr_ball;
		for (int i = 2; i < info.size(); i += 5)
		{
			if (info[i] == sr_ball)
			{
				num = i;
			infO.FIO = info[num - 2];
			infO.Group = stoi(info[num - 1]);
			infO.sr_ball = stoi(info[num]);
			infO.money_mam = stoi(info[num + 1]);
			infO.money_dad = stoi(info[num + 2]);
			infO.Print();
			}
		}
		if (num < 0)
		{
			cout << "такого нет";
		}
	}
	if (key == 3)
	{
		string mam;
		cout << "введите доход мамы" << endl;
		cin >> mam;
		for (int i = 3; i < info.size(); i += 5)
		{
			if (info[i] == mam)
			{
				num = i;
			infO.FIO = info[num - 3];
			infO.Group = stoi(info[num - 2]);
			infO.sr_ball = stoi(info[num - 1]);
			infO.money_mam = stoi(info[num]);
			infO.money_dad = stoi(info[num + 1]);
			infO.Print();
			}
		}
		if (num < 0)
		{
			cout << "такого нет";
		}
	}
	if (key == 4)
	{
		string dad;
		cout << "введите доход папы" << endl;
		cin >> dad;
		for (int i = 4; i < info.size(); i += 5)
		{
			if (info[i] == dad)
			{
				num = i;
			infO.FIO = info[num - 4];
			infO.Group = stoi(info[num - 3]);
			infO.sr_ball = stoi(info[num - 2]);
			infO.money_mam = stoi(info[num - 1]);
			infO.money_dad = stoi(info[num]);
			infO.Print();
			}
		}
		if (num < 0)
		{
			cout << "такого нет";
		}
	}
	File.close();
}
void clear()
{
	system("CLS");
}
bool menu_check(int x)
{
	if (x == 0 || x == 1 || x == 2 || x == 3 ||x==4|| x == 5||x==6 || x == 7 || x == 8)
	{
		return true;
	}
	else
	{
		cout << "Повторите ввод:";
		return false;
	}
}
void list()
{
	ofstream rez("rez.txt");
	rez.close();

	ifstream File("information.txt");
	vector<string> info;
	string line;
	int Index = 0;
	while (getline(File, line))
	{
		info.push_back(line);
	}
	File.close();
	for (int i = 0; i < info.size(); i += 5)
	{
		Index += 1;
	}
	Date_base* infO = new Date_base[Index];
	int index = -1;
	for (int i = 0; i < info.size(); i += 5)
	{
		index += 1;
		infO[index].FIO = info[i];
		infO[index].Group = stoi(info[i + 1]);
		infO[index].sr_ball = stoi(info[i + 2]);
		infO[index].money_mam = stoi(info[i + 3]);
		infO[index].money_dad = stoi(info[i + 4]);

	}
	int min, metod;
	cout << "введите минимальную зарплату" << endl;
	cin >> min;
	cout << "выберите метод: 1- Прямой выбор 2-QuicSort" << endl;
	do { cin >> metod; }while(check(metod)!=1);
	vector<string> REZ;
	vector<Date_base> Srball;
	
	
	    for (int i = 0; i < Index; i++)
		{
			if (infO[i].money_dad+infO[i].money_mam<2*min)
			{
	            ofstream rezult("rez.txt", ios::app);
				rezult << infO[i].FIO << endl;
				rezult << infO[i].Group << endl;
				rezult << infO[i].sr_ball << endl;
				rezult << infO[i].money_mam << endl;
				rezult << infO[i].money_dad << endl;
				rezult.close();
			}
			if (infO[i].money_dad + infO[i].money_mam >= 2 * min)
			{
				Srball.push_back(infO[i]);	
			}
		}
		if (metod == 1)
		{
			for (int i = 0; i < Srball.size() - 1; i++)
			{
				for (int j = i+1; j < Srball.size(); j++)
				{
					if (Srball[i].sr_ball < Srball[j].sr_ball)
					{
						Date_base r;
						r = Srball[i];
						Srball[i] = Srball[j];
						Srball[j] = r;
					}

				}
			}
		}
		if(metod == 2)
		{
			int i = 0; 
			int j = Srball.size() - 1;
			quickSort(Srball,1,i,j);
		}
		for (int i = 0;i<Srball.size(); i++)
		{
			ofstream rezult("rez.txt", ios::app);
			rezult << Srball[i].FIO << endl;
			rezult << Srball[i].Group << endl;
			rezult << Srball[i].sr_ball << endl;
			rezult << Srball[i].money_mam << endl;
			rezult << Srball[i].money_dad << endl;
			rezult.close();
		}
		
	delete[]infO;
}
void prosmotr_rez()
{
	ifstream File("rez.txt");
	vector<string> info;
	string line;
	Date_base infO;
	while (getline(File, line))
	{
		info.push_back(line);
	}
	for (int i = 0; i < info.size(); i += 5)
	{
		infO.FIO = info[i];
		infO.Group = stoi(info[i + 1]);
		infO.sr_ball = stoi(info[i + 2]);
		infO.money_mam = stoi(info[i + 3]);
		infO.money_dad = stoi(info[i + 4]);
		infO.Print();

	}
	File.close();
}
void sort(int key)
{
	ifstream File("information.txt");
	vector<string> info;
	string line;
	int Index = 0;
	while (getline(File, line))
	{
		info.push_back(line);
		Index++;
	}
	File.close();
	Index = Index / 5;
	vector<Date_base> BASE(Index);
	for (int i = 0, k=0; i < info.size(); i += 5,k++)
	{
		BASE[k].FIO = info[i];
	    BASE[k].Group = stoi(info[i + 1]);
		BASE[k].sr_ball = stoi(info[i + 2]);
		BASE[k].money_mam = stoi(info[i + 3]);
		BASE[k].money_dad = stoi(info[i + 4]);

	}
	int metod;
	cout << "Выберите метод сортировки: 1- Прямой выбор 2-QuicSort" << endl;
	cin >> metod;
	if (metod == 1)
	{
		if (key == 1)
		{
			for (int i = 0; i < BASE.size() - 1; i++)
			{
				for (int j = i+1; j < BASE.size(); j++)
				{
					if (BASE[i].sr_ball < BASE[j].sr_ball)
					{
						Date_base r;
						r = BASE[i];
						BASE[i] = BASE[j];
						BASE[j] = r;
					}

				}
			}
		}
		if (key == 2)
		{
			for (int i = 0; i < BASE.size() - 1; i++)
			{
				for (int j = i+1; j < BASE.size(); j++)
				{
					if (BASE[i].Group < BASE[j].Group)
					{
						Date_base r;
						r = BASE[i];
						BASE[i] = BASE[j];
						BASE[j] = r;
					}

				}
			}
		}
		if (key == 3)
		{
			for (int i = 0; i < BASE.size() - 1; i++)
			{
				for (int j = i+1; j < BASE.size(); j++)
				{
					if (BASE[i].money_mam < BASE[j].money_mam)
					{
						Date_base r;
						r = BASE[i];
						BASE[i]= BASE[j];
						BASE[j] = r;
					}

				}
			}
		}
		if (key == 4)
		{
			for (int i = 0; i < BASE.size() - 1; i++)
			{
				for (int j = i+1; j < BASE.size(); j++)
				{
					if (BASE[i].money_dad < BASE[j].money_dad)
					{
						Date_base r;
						r = BASE[i];
						BASE[i] = BASE[j];
						BASE[j]= r;
					}

				}
			}
		}
	}
	if (metod == 2)
	{
	
			int i = 0;
			int j = BASE.size() - 1;
			quickSort(BASE, key, i, j);
	
	}
	ofstream file("information.txt");
	file.close();
	for (int i = 0; i < BASE.size(); i++)
	{
		ofstream File("information.txt", ios::app);
		File << BASE[i].FIO << endl;
		File << BASE[i].Group << endl;
		File << BASE[i].sr_ball << endl;
		File << BASE[i].money_mam << endl;
		File << BASE[i].money_dad << endl;
		File.close();
	}
}
void find_binary()
{
	int key;
	cout << ("Выберите критерий поиска: 1- средний балл, 2- группа, 3- доход мамы, 4- доход папы") << endl;
	cin >> key;
	sort(key);
	ifstream File("information.txt");
	vector<string> info;
	string line;
	int Index = 0;
	while (getline(File, line))
	{
		info.push_back(line);
		Index++;
	}
	File.close();
	Index = Index / 5;
	vector<Date_base> BASE(Index);
	for (int i = 0, k = 0; i < info.size(); i += 5, k++)
	{
		BASE[k].FIO = info[i];
		BASE[k].Group = stoi(info[i + 1]);
		BASE[k].sr_ball = stoi(info[i + 2]);
		BASE[k].money_mam = stoi(info[i + 3]);
		BASE[k].money_dad = stoi(info[i + 4]);

	}
	if (key == 1)
	{
		int KEY;
        cout << endl << "Введите средний балл: "<<endl;
        cin >> KEY;
		int left = 0; 
		int right = BASE.size()-1;
		int search = -1; 
		while (left <= right) 
		{
			int mid = (left + right) / 2;
			if (KEY == BASE[mid].sr_ball)
			{  
				search = mid;
				break;            
			}
			if (KEY > BASE[mid].sr_ball)     
				right = mid - 1; 
			else                  
				left = mid + 1;  
		}
		if (search == -1)
		{
			printf("Элемент не найден!\n");
		}
		else
		{
			BASE[search].Print();
		}
	}
	if (key == 2)
	{
		int KEY;
		cout << endl << "Введите номер группы: " << endl;
		cin >> KEY;
		int left = 0;
		int right = BASE.size() - 1;
		int search = -1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (KEY == BASE[mid].Group)
			{
				search = mid;
				break;
			}
			if (KEY > BASE[mid].Group)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (search == -1)
		{
			printf("Элемент не найден!\n");
		}
		else
		{
			BASE[search].Print();
		}
	}
	if (key == 3)
	{
		int KEY;
		cout << endl << "Введите доход мамы: " << endl;
		cin >> KEY;
		int left = 0;
		int right = BASE.size() - 1;
		int search = -1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (KEY == BASE[mid].money_mam)
			{
				search = mid;
				break;
			}
			if (KEY > BASE[mid].money_mam)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (search == -1)
		{
			printf("Элемент не найден!\n");
		}
		else
		{
			BASE[search].Print();
		}
	}
	if (key == 4)
	{
		int KEY;
		cout << endl << "Введите доход папы: " << endl;
		cin >> KEY;
		int left = 0;
		int right = BASE.size() - 1;
		int search = -1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (KEY == BASE[mid].money_dad)
			{
				search = mid;
				break;
			}
			if (KEY > BASE[mid].money_dad)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (search == -1)
		{
			printf("Элемент не найден!\n");
		}
		else
		{
			BASE[search].Print();
		}
	}
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	while (true)
	{
		cout << "Меню:\n";
		cout << "\tСоздать - 1\n\tПросмотр - 2\n\tДобавление - 3\n\tПоиск линейный - 4\n\tСортировка - 5\n\tОчистить экран - 6\n\tФормировать список на получение общежития - 7\n\tПоиск бинарный- 8\n\tВыход - 0" << endl;
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
			find_line();
			break;
		case 5:
			int key;
			cout << "Выберите ключ сортировки 1- Средний балл, 2-номер группы, 3 -доход мамы, 4 - доход папы" << endl;
			cin >> key;
			sort(key);
			break;
		case 6:
			clear();
			break;
		case 7:
			list();
			prosmotr_rez();
			break;
		case 8:
			find_binary();
			break;
		case 0:
			return 0;
			break;

		}
	}
}