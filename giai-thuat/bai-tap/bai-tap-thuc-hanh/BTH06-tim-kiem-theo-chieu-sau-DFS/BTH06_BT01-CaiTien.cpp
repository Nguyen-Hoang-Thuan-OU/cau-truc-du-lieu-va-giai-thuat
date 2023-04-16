#include<iostream>
#include<stack>
#define MAX 20
using namespace std;
stack<int> x;
int A[MAX][MAX];
int n;
int C[100];
int dfs[100];
int ndfs = 0;

void khoiTao()
{
	n = 0;
}

void nhapMaTran()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	cout << endl;
}

void xuatMaTran()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
}

void khoiTaoDinhChuaXet()
{
	for (int i = 0; i < n; i++)
	{
		C[i] = 1;
	}
}

void DFS(int s, int &ss, int &gan, int &toan)
{
	x.push(s);
	dfs[ndfs] = s;
	gan++;
	ndfs++;
	gan++;
	toan++;
	C[s] = 0;
	int v = -1, u = s;
	gan+=2;

	while (ss++, !x.empty())
	{
		if (v == n, ss++)
			x.pop();
		for (gan++, v = 0; ss++, v < n; gan++, toan++, v++)
		{
			if (ss+=2, A[u][v] != 0 && C[v] == 1)
			{
				x.push(u);
				x.push(v);
				dfs[ndfs] = v;
				gan++;
				ndfs++;
				C[v] = 0;
				u = v;
				gan++;
				break;
			}
		}
	}
}

void xuatDFS(int &ss, int &gan, int &toan)
{
	for (int i = 0; i < ndfs; i++)
	{
		cout << dfs[i] << "  ";
	}
	cout << endl;
	
	cout << "Tong so phep so sanh: " << ss << endl;
	cout << "Tong so phep gan: " << gan << endl;
	cout << "Tong so phep toan: " << toan << endl;
}

void main()
{
	int ss, gan, toan = 0;
	khoiTao();
	nhapMaTran();
	xuatMaTran();
	khoiTaoDinhChuaXet();
	DFS(0, ss, gan, toan);
	xuatDFS(ss, gan, toan);
}