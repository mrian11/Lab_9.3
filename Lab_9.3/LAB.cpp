#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include<fstream>
#include <string.h>


using namespace std;

enum Train {Z_V ,P_COMF , SPEED_E };
string trainStr[] = { "����.", "����.", "�������" };

struct Tramvai
{
	string punkt;
	Train tup;
	double chas;
};

void Create(Tramvai* p, const int N);
void Print(Tramvai* p, const int N);
double LineSearch(Tramvai* p, const int N);
void Remove(Tramvai* p, int& N);
void SaveToFile(Tramvai* p, const int N, const char* filename);
void LoadFromFile(Tramvai*& p, int& N, const char* filename);
void Edit(Tramvai* p, const int N);
void Sort(Tramvai* p, const int N);

int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int N;
	cout << "������ ������� ����� N: "; cin >> N;
	Tramvai* p = new Tramvai[N];
	
     //double proc;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - ��������� ����������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ��������� ����������" << endl;
		cout << " [4] - ����������� ����������" << endl;
		cout << " [5] - ����������" << endl;
		cout << " [6] - ����� �� ������ ���� ��������� ����" << endl;

		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Remove(p, N);
			Print(p, N);
			break;

		case 4:
			Edit(p, N);
			break;
		case 5:
			Sort(p, N);
			//Print(p, N);
				break;
		case 6:
			LineSearch(p, N);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	delete[] p;
	return 0;
}
void Create(Tramvai* p, const int N)
{
	double chas;
	int tup;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;

		cin.get();
		cin.sync(); 

		cout << "���� ����������� :"; getline(cin, p[i].punkt);

		cout << " ��� (0 - ����, 1 - ����, 2 - �������): ";
		cin >> tup;
		p[i].tup = (Train)tup;
		cout << "��� :";
		cin >> chas;
		p[i].chas = (double)chas;

		cout << endl;
	}
}
void Print(Tramvai* p, const int N)
{
	cout << "==========================="
		<< endl;
	cout << "| �  | ����� | ��� | ��� |"
		<< endl;
	cout << "---------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(5) << left << p[i].punkt
			<< "| " << setw(4) << right << p[i].tup << " "
			<< "| " << setw(4) << left << p[i].chas;
		cout  << endl;
	}

	cout << "=========================="
		<< endl;
	cout << endl;
}

/*
if (strcmp(p[i1].punkt.c_str, p[i1 + 1].punkt) > 0 ||
(strcmp(p[i1].punkt, p[i1 + 1].punkt) == 0 && p[i1].chas > p[i1 + 1].c3has))
	{*/

void Sort(Tramvai* p, const int N)
{
	Tramvai tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].punkt > p[i1 + 1].punkt || (p[i1].punkt == p[i1 + 1].punkt && p[i1].chas > p[i1 + 1].chas))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

double LineSearch(Tramvai* p, const int N)
{
	double time;
	cout << "������ ���: ";
	cin >> time;

	cout << "�����, �� �������� ���� " << time << " �����:" << endl;
	int count = 0;

	cout << "==========================="
		<< endl;
	cout << "| �  | ����� | ��� | ��� |"
		<< endl;
	cout << "---------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		if (p[i].chas > time)
		{
			cout << "| " << setw(3) << right << i + 1 << " ";
			cout << "| " << setw(5) << left << p[i].punkt
				<< "| " << setw(4) << right << p[i].tup << " "
				<< "| " << setw(4) << left << p[i].chas;
			cout << endl;

			count++;
		}
	}

	cout << "=========================="
		<< endl;

	return count;
}

void Remove(Tramvai* p, int& N)
{
	if (N <= 0)
	{
		cout << "���� ������� ��� ���������." << endl;
		return;
	}

	int Ind;
	cout << "������ ����� ������� ��� ���������: ";
	cin >> Ind;

	if (Ind < 1 || Ind > N)
	{
		cout << "����������� ����� �������." << endl;
		return;
	}

	if (Ind >= 1 && Ind <= N)
	{
		int K = N - 1;
		Tramvai* t = new Tramvai[K];
		int j = 0;

		for (int i = 0; i < N; ++i)
		{
			if (i + 1 != Ind)
			{
				t[j++] = p[i];
			}
		}

		delete[] p;  // ��������� ���'���, �� ������� �� ��� ������������ � �����
		p = t;
		N = K;

		cout << "������� �� ������� " << Ind << " ��������." << endl;
	}
}





void SaveToFile(Tramvai* p, const int N, const char* filename)
{
		ofstream fout(filename, ios::binary); 
		fout.write((char*)&N, sizeof(N)); 
		for (int i = 0; i < N; i++)
			fout.write((char*)&p[i], sizeof(Tramvai)); 
		fout.close(); 
}

void LoadFromFile(Tramvai*& p, int& N, const char* filename)
{
		delete[] p;

		ifstream fin(filename, ios::binary);

		fin.read((char*)&N, sizeof(N));

		p = new Tramvai[N];
		for (int i = 0; i < N; i++)
			fin.read((char*)&p[i], sizeof(Tramvai));
		fin.close();
}

void Edit(Tramvai* p, const int N)
{
	int trainNumber;
	cout << "������ ����� ������� ��� �����������: ";
	cin >> trainNumber;

	// ����� ������ �������
	int index = -1;
	for (int i = 0; i < N; ++i) {
		if (i + 1 == trainNumber) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// �������� �������� �������
		cout << "����������� ���������� ��� ������� �" << trainNumber << ":" << endl;

		cin.get();
		cin.sync();

		cout << "����� ����� �����������: ";
		getline(cin, p[index].punkt);

		int tup;
		cout << "����� ��� (0 - ����, 1 - ����, 2 - �������): ";
		cin >> tup;
		p[index].tup = static_cast<Train>(tup);

		cout << "����� ��� �����������: ";
		cin >> p[index].chas;

		cout << "���������� ��� ������� �" << trainNumber << " ������������." << endl;
	}
	else {
		cout << "������� � ������� " << trainNumber << " �� ��������." << endl;
	}
}
