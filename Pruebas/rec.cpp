#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char sMensaje[1000];
void palabra(string);
int main(void)
{
	int n;
	cout << "1. Hablar con la P" << endl;
	cout << "2. Invertir palabras" << endl;
	cout << "3. Codigo murcielago" << endl;
	cin >> n;

	switch (n)
	{
	case 1:
	{
		string pal;
		cout << "inserte una palabra" << endl;
		cin >> pal;

		palabra(pal);
		break;
	}
	case 2:
	{
		string cad = "", pal;
		cout << "ingresa una palabra" << endl;
		cin >> pal;
		int t = pal.length();
		for (int i = t; i > 0; i--)
		{
			cad = cad + pal.substr((i - 1), 1);
		}
		cout << cad;
		break;
	}
	case 3:
		cout << "escriba una palabra:" << endl;
		cin.ignore();
		cin.getline(sMensaje, 1000);

		for (int c = 0; c <= 1000; c++)
		{
			switch (sMensaje[c])
			{
				{
				case 'm':
					sMensaje[c] = 48;
					break;
				}
				{
				case 'u':
					sMensaje[c] = 49;
					break;
				}
				{
				case 'r':
					sMensaje[c] = 50;
					break;
				}
				{
				case 'c':
					sMensaje[c] = 51;
					break;
				}
				{
				case 'i':
					sMensaje[c] = 52;
					break;
				}
				{
				case 'e':
					sMensaje[c] = 53;
					break;
				}
				{
				case 'l':
					sMensaje[c] = 54;
					break;
				}
				{
				case 'a':
					sMensaje[c] = 55;
					break;
				}
				{
				case 'g':
					sMensaje[c] = 56;
					break;
				}
				{
				case 'o':
					sMensaje[c] = 57;
					break;
				}
			default:
				sMensaje[c] = sMensaje[c];
			}
		}
		cout << sMensaje;
	}
	return 0;
}
void palabra(string pal)
{
	int n;
	string cad = "p";
	n = pal.length();

	for (int i = 0; i < n; i++)
	{
		cout << pal.at(i);
		if (pal.at(i) == 'a' or pal.at(i) == 'e' or pal.at(i) == 'i' or pal.at(i) == 'o' or pal.at(i) == 'u')
		{
			cout << cad + pal.at(i);
		}
	}
}