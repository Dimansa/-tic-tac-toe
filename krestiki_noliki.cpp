#include<iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>

using namespace std;

char a[3][3];

int k1[5], k2[5], n1[4], n2[4];

int vivod()
{
	int q = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			cout << a[i][j];
			if (cout.fail() == true)
				q = 1;
		}
		cout << endl;
		if (cout.fail() == true)
			q = 2;
	}
	return q;
}
int check(int x, int y) 
{
	if (x < 0 || x > 2) 
		return 2;
	else
	{
		if (y < 0 || y > 2)
			return 3;
		else
		{
			if (a[x][y] == ' ')
				return 0;
			else
				return 1;
		}
	}
}
int pod_check(int y, int t) 
{
	int q = 1;
	if (y < 0 || y > 2) 
		q = 2;
	else
	if (t < 0 || t > 4) 
		q = 3;
	else 
	{
		int x = k1[t];
		q = check(x, y);
		if (q == 0) 
		{
			a[x][y] = '0';
			n1[t] = x;
			n2[t] = y;
		}
	}
	return q;
}
int pod_check2(int x, int t) 
{
	int q = 1;
	if (x < 0 || x > 2) 
		q = 2;
	else
	if (t < 0 || t > 4) 
		q = 3;
	else 
	{
		int y = k2[t];
		q = check(x, y);
		if (q == 0) 
		{
			a[x][y] = '0';
			n1[t] = x;
			n2[t] = y;
		}
	}
	return q;
}
int pod_check_vin(int y, int t)
{
	int q = 1;
	if (y < 0 || y > 2) 
		q = 2;
	else
	if (t < 0 || t > 3)
		q = 3;
	else 
	{
		int x = n1[t];
		q = check(x, y);
		if (q == 0)
			a[x][y] = '0';
	}
	return q;
}
int pod_check_vin2(int x, int t) 
{
	int q = 1;
	if (x < 0 || x > 2)
		q = 2;
	else
	if (t < 0 || t > 3) 
		q = 3;
	else {
		int y = n2[t];
		q = check(x, y);
		if (q == 0)
			a[x][y] = '0';
	}
	return q;
}
int sluchaino(int t) 
{
	int q = 0;
	if (t < 0 || t > 4) 
		q = 1;
	else 
	{
		int x = rand() % 3;
		int y = rand() % 3;
		q = check(x, y);
		if (q == 0) 
		{
			a[x][y] = '0';
			n1[t] = x;
			n2[t] = y;
		}
		else {
			q = sluchaino(t);
			if (q != 0)
				q = 2;
		}
	}
	return q;
}
int check_loose_next(int t)
{
	int q = 1;
	if (t < 0 || t > 4)
		q = 2;
	else 
	{
		int y = 0;
		int x = 0;
		for (int i = 0; i < t; i++) 
		{
			if (k1[t] == k1[i] && q == 1) 
			{
				switch (k2[t] + k2[i]) 
				{
				case 1:
					y = 2;
					q = pod_check(y, t);
					break;
				case 2:
					y = 1;
					q = pod_check(y, t);
					break;
				case 3:
					y = 0;
					q = pod_check(y, t);
					break;
				default:
					break;
				}
			}
			if (k2[t] == k2[i] && q == 1)
			{
				switch (k1[t] + k1[i]) {
				case 1:
					x = 2;
					q = pod_check2(x, t);
					break;
				case 2:
					x = 1;
					q = pod_check2(x, t);
					break;
				case 3:
					x = 0;
					q = pod_check2(x, t);
					break;
				default:
					break;
				}
			}
			if (k2[t] == k1[t] && k1[i] == k2[i] && q == 1) 
			{
				switch (k1[t] + k1[i]) 
				{
				case 1:
					if (check(2, 2) == 0) 
					{
						a[2][2] = '0';
						n1[t] = 2;
						n2[t] = 2;
						q = 0;
					}
					break;
				case 2:
					if (check(1, 1) == 0) 
					{
						a[1][1] = '0';
						n1[t] = 1;
						n2[t] = 1;
						q = 0;
					}
					break;
				case 3:
					if (check(0, 0) == 0) 
						{
						a[0][0] = '0';
						n1[t] = 0;
						n2[t] = 0;
						q = 0;
					}
					break;
				default:
					break;
				}
			}					
			if (((k1[t] == 0 && k2[t] == 2 && k1[i] == 1 && k2[i] == 1) || (k1[i] == 0 && k2[i] == 2 && k1[t] == 1 && k2[t] == 1)) && q == 1)
			{
				if (check(2, 0) == 0) 
				{
					a[2][0] = '0';
					n1[t] = 2;
					n2[t] = 0;
					q = 0;
				}
			}			
			if (((k1[t] == 2 && k2[t] == 0 && k1[i] == 1 && k2[i] == 1) || (k1[i] == 2 && k2[i] == 0 && k1[t] == 1 && k2[t] == 1)) && q == 1)
			{
				if (check(0, 2) == 0) 
				{
					a[0][2] = '0';
					n1[t] = 0;
					n2[t] = 2;
					q = 0;
				}
			}
			if (((k1[t] == 2 && k2[t] == 0 && k1[i] == 0 && k2[i] == 2) || (k1[i] == 0 && k2[i] == 2 && k1[t] == 2 && k2[t] == 0)) && q == 1) 
			{
				if (check(1, 1) == 0)
				{
					a[1][1] = '0';
					n1[t] = 1;
					n2[t] = 1;
					q = 0;
				}
			}	
		}
	}
	return q;
}
int check_vin(int t) 
{
	int q = 1;
	if (t < 0 || t > 4) 
		q = 2;
	else 
	{
		q = 1;
		int y = 0;
		int x = 0;
		for (int i = 0; i < t; i++) 
		{
			if (n1[t] == n1[i] && q == 1) 
			{
				switch (n2[t] + n2[i]) 
				{
				case 1:
					y = 2;
					q = pod_check_vin(y, t);
					break;
				case 2:
					y = 1;
					q = pod_check_vin(y, t);
					break;
				case 3:
					y = 0;
					q = pod_check_vin(y, t);
					break;
				default:
					break;
				}
			}
			if (n2[t] == n2[i] && q == 1) 
			{
				switch (n1[t] + n1[i]) 
				{
				case 1:
					x = 2;
					q = pod_check_vin2(x, t);
					break;
				case 2:
					x = 1;
					q = pod_check_vin2(x, t);
					break;
				case 3:
					x = 0;
					q = pod_check_vin2(x, t);
					break;
				default:
					break;
				}
			}
			if (n2[t] == n1[t] && n1[i] == n2[i] && q == 1) 
			{
				switch (n1[t] + n1[i]) 
				{
				case 1:
					if (check(2, 2) == 0) 
					{
						a[2][2] = '0';
						q = 0;
					}
					break;
				case 2:
					if (check(1, 1) == 0) 
					{
						a[1][1] = '0';
						q = 0;
					}
					break;
				case 3:
					if (check(0, 0) == 0) 
					{
						a[0][0] = '0';
						q = 0;
					}
					break;
				default:
					break;
				}
			}
			if (((n1[t] == 0 && n2[t] == 2 && n1[i] == 1 && n2[i] == 1) || (n1[i] == 0 && n2[i] == 2 && n1[t] == 1 && n2[t] == 1)) && q == 1) 
			{
				if (check(2, 0) == 0) 
				{
					a[2][0] = '0';
					q = 0;
				}
			}
			if (((n1[t] == 2 && n2[t] == 0 && n1[i] == 1 && n2[i] == 1) || (n1[i] == 2 && n2[i] == 0 && n1[t] == 1 && n2[t] == 1)) && q == 1) 
			{
				if (check(0, 2) == 0) 
				{
					a[0][2] = '0';
						q = 0;
				}
			}
			if (((n1[t] == 2 && n2[t] == 0 && n1[i] == 0 && n2[i] == 2) || (n1[i] == 0 && n2[i] == 2 && n1[t] == 2 && n2[t] == 0)) && q == 1)
			{
				if (check(1, 1) == 0) 
				{
					a[1][1] = '0';
					q = 0;

				}
			}	
		}
	}
	return q;
}
int check_loose(int t) 
{
	int q = 0;
	if (t < 0 || t > 4)
		q = 2;
	else
	{
		int r0 = 0, r1 = 0, r2 = 0, t0 = 0, t1 = 0, t2 = 0, s1 = 0, s2 = 0;
		for (int i = 0; i <= t; i++) 
		{
			if (k1[i] == 0)
				r0++;
			if (k1[i] == 1)
				r1++;
			if (k1[i] == 2)
				r2++;
			if (k2[i] == 0)
				t0++;
			if (k2[i] == 1)
				t1++;
			if (k2[i] == 2)
				t2++;
		}
		if (r0 == 3 || r1 == 3 || r2 == 3 || t0 == 3 || t1 == 3 || t2 == 3)
			q = 0;
		else 
		{
			for (int i = 0; i <= t; i++)
				if (k1[i] == k2[i])
					s1++;
			if (s1 == 3)
				q = 0;
			else 
			{
				for (int i = 0; i <= t; i++)
					if (abs(k1[i] - k2[i]) == 2 || (k1[i] == k2[i] && k1[i] == 1))
						s2++;
				if (s2 == 3)
					q = 0;
				else
					q = 1;
			}
		}
	}
	return q;
}
int number_move(int t,int *b,int *c) 
{
	int q = 0;
	if (t < 1 || t > 5)
	 q = 2;
	else 
	{
		switch (t) 
		{
		case 1:
			q = sluchaino(0);
			break;
		case 2:
			q = check_loose_next(1);
			if (q == 1)
				 q = sluchaino(1);
			break;
		case 3:
			q = check_loose(2);
			if (q == 1)
			{
				q = check_vin(1);
				if (q == 1) 
				{
					q = check_loose_next(2);
					if (q == 1)
						q=sluchaino(2);
				}
				else
					*c = 0;
			}
			else
				*b = 0;
			break;
		case 4:
			q = check_loose(3);
			if (q == 1) 
			{
				q = check_vin(2);
				if (q == 1) 
				{
					q = check_loose_next(3);
					if (q == 1)
					{
						q = check_loose_next(2);
						if(q==1)
							q = sluchaino(3);
					}
				}
				else
					*c = 0;
			}
			else
				*b = 0;
			break;
		case 5:
			q = check_loose(4);
			if (q == 0)
				*b = 0;
			else
				if (q == 1)
					q = 0;
		default:
			break;
		}
	}
	return q;
}
int vvod(int i,int *b,int *c)
{
	int q = 0;
	if (i < 0 || i > 4) 
		return 2;
	else
	{
		cout << "Ваш ход, введите координаты (две цифры от 1 до 3)" << endl;
		if (cout.fail() == true)
			return 3;
		while (!(cin >> k1[i] >> k2[i])) 
		{
			cout << "Ââåäåíî íåêîððåêòíîå çíà÷åíèå, Ââåäèòå öèôðû îò 1 äî 3" << endl;
			if (cout.fail() == true) 
				return 4;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		cin.ignore(32767, '\n');
		k1[i]--;
		k2[i]--;
		if (check(k1[i], k2[i]) == 0 && k1[i] >= 0 && k1[i] < 3 && k2[i] >= 0 && k2[i] < 3) 
		{
			a[k1[i]][k2[i]] = 'x';
			q = number_move(i + 1,b,c);
			if (q != 0)
				return 8;
			q = vivod();
			if (q != 0)
				return 5;
		}
		else 
		{
			cout << "Ýòà êëåòêà óæå çàíÿòà èëè íå ñóùåñòâóåò, ïîñòàâòå êðåñòèê â äðóãóþ êëåòêó" << endl;
			if (cout.fail() == true) 
				return 6;
			q=vvod(i,b,c);
			if (q != 0)
				return 7;
		}
	}
	return q;
}
int main() 
{
	int q = 0,b=1,c=1,t;
	if ((t = time(NULL)) == -1)
		return 6;
	srand(t);
	if(setlocale(LC_ALL, "Russian")==NULL)
		return 7;
	cout << "Äîáðî ïîæàëîâàòü" << endl << "1 1 ýòî ëåâûé âåðõíèé óãîë, 1 2 ýòî ñåðåäèíà ââåðõó, à 3 3 ýòî ïðàâûé íèæíèé óãîë" << endl;
	if (cout.fail() == true)
		q = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = ' ';
	for (int i = 0; i < 4; i++) 
	{
		n1[i] = 1000;
		n2[i] = 1000;
		k1[i] = 1000;
		k2[i] = 1000;
	}
	k1[4] = 1000;
	k2[4] = 1000;
	for (int i = 0; i < 5; i++) 
	{
		if (b == 1 && c == 1)
			q = vvod(i,&b,&c);
		else
		{
			if (b == 0)
				cout << "ÏÎÁÅÄÀ" << endl;
			if (cout.fail() == true) 
				q = 2;
			if (c == 0)
				cout << "ÏÎÐÀÆÅÍÈÅ" << endl;
			if (cout.fail() == true)
				q = 3;
			i = 5;
		}
		if (i == 4 && b == 0)
			cout << "ÏÎÁÅÄÀ" << endl;
		if (cout.fail() == true)
			q = 4;
	}
	if (b == 1 && c == 1)
		cout << "ÍÈ×Üß" << endl;
	if (cout.fail() == true) 
		q = 5;
	system("pause");
	return q;
}
