#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // Библиотека времени
#include <cmath>
#include <locale.h>
#include <iostream> // Библиотека Ввода,Вывода
#include <conio.h>
#include < queue >
#include <time.h>

int** matrix;
using namespace std;
int* DIST;
int u = 0, n;
struct spisok_smzh {

	int versh;
	spisok_smzh* next;

};

struct spiski_smzh {

	spisok_smzh* spisok;
	spiski_smzh* next;
};

spiski_smzh* p_spiski = NULL;
spiski_smzh* n_spiski = NULL;
spiski_smzh* p_spiski_start = NULL;
spisok_smzh* p_spisok = NULL;
spisok_smzh* p_spisok_start = NULL;
spisok_smzh* n_spisok = NULL;

void bfs(int v, int n)
{

	//clock_t time;
	//time = clock();
	int p = 0, i = 0;
	DIST = new int[n];
	for (u = 0; u < n; u++)
	{
		DIST[u] = -1;
	}
	DIST[v] = 0;
	//cout << v;
	//i = s;
	queue <int> plan; // план посещения в виде очереди
	p_spiski = p_spiski_start;
	spisok_smzh* p_spisok_loc = NULL;
	plan.push(v); // мы нумеруем с 0, а не с 1
	//DIST[v] = 0; // отмечаем, что эта вершина уже заносилась в план
	//int counter = 1; // начальную уже сосчитали
	while (!plan.empty()) {
		v = plan.front(); // посещаем следующую по плану вершину
		plan.pop(); // удаляем ее из плана посещения
		for (int i = 0; i < v; i++)
			p_spiski = p_spiski->next;
		p_spisok_loc = p_spiski->spisok;
		p_spiski = p_spiski_start;
		//cout « v;
		//for (int i = 0; i < n; i++) { // перебираем соседние с ней
		while (p_spisok_loc != NULL)
		{
			if (DIST[p_spisok_loc->versh] == -1) { // если новая, то
				plan.push(p_spisok_loc->versh); // добавляем ее в план
				//cout << i;
				DIST[p_spisok_loc->versh] = DIST[v] + 1; // отмечаем, что уже не новая
				//cout << DIST[i];
			}
			p_spisok_loc = p_spisok_loc->next;

		}
		//DIST[v] = DIST[v] + 1;
	}
	//time = clock() - time;
	//cout << endl;
	//printf("%.50f", (double)time / CLOCKS_PER_SEC);
	cout << endl;
}

void bfsm(int v, int n)
{

	//clock_t time;
	//time = clock();
	int p = 0, i = 0;
	DIST = new int[n];
	for (u = 0; u < n; u++)
	{
		DIST[u] = -1;
	}
	DIST[v] = 0;
	//cout << v;
	//i = s;
	queue <int> plan; // план посещения в виде очереди

	plan.push(v); // мы нумеруем с 0, а не с 1
	//DIST[v] = 0; // отмечаем, что эта вершина уже заносилась в план
	//int counter = 1; // начальную уже сосчитали
	while (!plan.empty()) {
		v = plan.front(); // посещаем следующую по плану вершину
		plan.pop(); // удаляем ее из плана посещения

		//cout « v;
		for (int i = 0; i < n; i++) { // перебираем соседние с ней

			if (matrix[v][i] == 1 && DIST[i] == -1) { // если новая, то
				plan.push(i); // добавляем ее в план
				//cout << i;
				DIST[i] = DIST[v] + 1;
				//cout << DIST[i];
			}


		}
		//DIST[v] = DIST[v] + 1;
	}
	//time = clock() - time;
	//cout << endl;
	//printf("%.50f", (double)time / CLOCKS_PER_SEC);
	cout << endl;
}

void DFS(int v)
{

	int r;
	p_spiski = p_spiski_start;
	spisok_smzh* p_spisok_loc = NULL;

	//cout << v << " ";
	for (int i = 0; i < v; i++)
		p_spiski = p_spiski->next;
	p_spisok_loc = p_spiski->spisok;
	while (p_spisok_loc != NULL)
	{
		if (DIST[p_spisok_loc->versh] == -1 || ((DIST[v] + 1) < DIST[p_spisok_loc->versh]))
		{
			DIST[p_spisok_loc->versh] = DIST[v] + 1;
			DFS(p_spisok_loc->versh);
		}
		p_spisok_loc = p_spisok_loc->next;
	}
}

void DFSm(int v)
{

	int r;


	//cout << v << " ";

	for (int i = 0; i < n; i++) {


		if (DIST[i] == -1 && matrix[v][i] == 1 || ((DIST[v] + 1) < DIST[i]))
		{

			DIST[i] = DIST[v] + 1;
			DFSm(i);

		}


	}
}


int main()
{
	int p = 0, i = 0, j, q;
	int v = 0;
	//int s;
	setlocale(LC_ALL, "Russian"); // подключение русского
	srand(time(NULL)); // новый отсчёт времени

	cout << "n="; // выводит данные
	cin >> n; // помещает данные
	matrix = new int* [n];
	//cout « "n=";
	//cin » n;
	cout << "Матрица: \n";
	int z;
	for (i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}



	for (i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{
			matrix[i][p] = rand() % 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{

			if (p == i)
			{
				matrix[i][p] = 0;
			}
			else
			{
				matrix[i][p] = matrix[p][i];
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		n_spiski = (spiski_smzh*)malloc(sizeof(spiski_smzh));
		p_spisok = NULL;
		p_spisok_start = NULL;
		for (j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1)
			{
				n_spisok = (spisok_smzh*)malloc(sizeof(spisok_smzh));
				n_spisok->versh = j;
				if (p_spisok == NULL)
				{
					p_spisok = n_spisok;
					p_spisok_start = p_spisok;
				}
				else
				{
					p_spisok->next = n_spisok;
					p_spisok = n_spisok;
				}
				n_spisok->next = NULL;
			}
		}
		n_spiski->spisok = p_spisok_start;
		if (p_spiski == NULL)
		{
			p_spiski = n_spiski;
			p_spiski_start = p_spiski;
		}
		else
		{
			p_spiski->next = n_spiski;
			p_spiski = n_spiski;
		}
	}

	p_spiski = p_spiski_start;

	for (int i = 0; i < n; i++)
	{
		p_spisok = p_spiski->spisok;
		p_spisok_start = p_spisok;

		cout << "\n";
		cout << "{";
		while (p_spisok != NULL)
		{
			cout << p_spisok->versh << " ";
			p_spisok = p_spisok->next;
		}
		cout << "}" << "   Вершина" << " " << i;
		p_spisok = p_spisok_start;
		p_spiski = p_spiski->next;
	}
	cout << "\n";

	p_spiski = p_spiski_start;


	cout << "\n";
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		// used[i] = false;
		for (p = 0; p < n; p++)
			cout << matrix[i][p] << " "; // выводит матрицу
		cout << endl;
	}


	cout << "Стартовая вершина » ";
	//cin » s;
	cin >> v;

	//bool* vis = new bool[n];
	cout << "Вектор расстояний: ";
	clock_t time;
	time = clock();
	bfs(v, n);
	time = clock() - time;
	cout << endl;
	cout << "В ширину  для списков смежности";
	cout << endl;
	printf("%.50f", (double)time / CLOCKS_PER_SEC);
	cout << endl;
	for (i = 0; i < n; i++)
	{
		if (DIST[i] == -1)
		{
			cout << "нет пути" << " ";
		}
		else
		{
			cout << "  " << DIST[i] << " ";
		}
	}



	for (u = 0; u < n; u++)
	{
		DIST[u] = -1;
	}
	cout << endl;
	DIST[v] = 0;
	clock_t timeh1;
	timeh1 = clock();
	DFS(v);

	timeh1 = clock() - timeh1;
	cout << endl;
	cout << "В глубину  для списков смежности";
	cout << endl;
	printf("%.50f", (double)timeh1 / CLOCKS_PER_SEC);
	cout << endl;
	for (i = 0; i < n; i++)
	{
		if (DIST[i] == -1)
		{
			cout << "нет пути" << " ";
		}
		else
		{
			cout << "  " << DIST[i] << " ";
		}
	}

	cout << endl;
	DIST[v] = 0;

	for (u = 0; u < n; u++)
	{
		DIST[u] = -1;
	}

	clock_t timeh2;
	timeh2 = clock();
	bfsm(v, n);
	timeh2 = clock() - timeh2;
	cout << endl;
	cout << "В ширину для матрицы";
	cout << endl;
	printf("%.50f", (double)timeh2 / CLOCKS_PER_SEC);
	cout << endl;
	cout << endl;
	for (i = 0; i < n; i++)
	{
		if (DIST[i] == -1)
		{
			cout << "нет пути" << " ";
		}
		else
		{
			cout << "  " << DIST[i] << " ";
		}
	}

	//delete[] used;


	cout << endl;
	for (u = 0; u < n; u++)
	{
		DIST[u] = -1;
	}
	DIST[v] = 0;


	clock_t timeh;
	timeh = clock();
	DFSm(v);
	timeh = clock() - timeh;
	cout << "В глубину  для матрицы";
	cout << endl;
	printf("%.50f", (double)timeh / CLOCKS_PER_SEC);
	cout << endl;
	for (i = 0; i < n; i++)
	{
		if (DIST[i] == -1)
		{
			cout << "нет пути" << " ";
		}
		else
		{
			cout << "  " << DIST[i] << " ";
		}
	}
	_getch();
}
