// operon20.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

ifstream plik("anagramy.txt");
ifstream plik2("wyrazy.txt");
fstream plik3("wyniki.txt");

int AnagrSpr(string a, string b)
{
	int nie = 0;
	if (a.length() != b.length()) return 2;
	for (int i = 0; i < a.length(); i++)
	{
		bool spr = false;
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i] == b[j])
			{
				spr = true;
				b[j] = 0;
				a[i] = 0;
			}
		}
		if (spr == false) nie++;
	}
	return nie;
}

int Jeden()
{
	string a;
	string b;
	int ile = 0;
	for (int i = 0; i < 200; i++)
	{
		plik >> a >> b;
		if (AnagrSpr(a, b) == 0)
		{
			ile++;
		}
	}
	plik.close();
	plik.open("anagramy.txt");
	return ile;
}

void AnagrPozZnak(string a, string b)
{
	for (int i = a.length() - 1; i >= 0; i--)
	{
		for (int j = b.length() - 1; j >= 0; j--)
		{
			if (a[i] == b[j])
			{
				b[j] = 0;
				a[i] = 0;
			}
		}
	}
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i] != 0 && b[j] != 0) cout << a[i] << "\t" << j+1 << endl;
		}
	}
}

void Dwa()
{
	string a;
	string b;
	for (int i = 0; i < 200; i++)
	{
		plik >> a >> b;
		int poz;
		char znak;
		if (AnagrSpr(a, b) == 1)
		{
			cout << a << "\t" << b << "\t";
			AnagrPozZnak(a, b);
		}
	}
}

void Trzy(string a)
{
	sort(a.begin(), a.end());
	do
	{
		cout << a << endl;
	} while (next_permutation(a.begin(), a.end()));
}

void Trzy2(string a)
{
	sort(a.begin(), a.end());
	do
	{
		plik3 << a << endl;
	} while (next_permutation(a.begin(), a.end()));
}

void Cztery()
{
	string wyraz;
	int i = 1;
	while (plik2.good())
	{
		plik2 >> wyraz;
		plik3 << "WYRAZ " << i << endl << endl;
		Trzy2(wyraz);
		i++;
	}
	plik2.close();
	plik2.open("wyrazy.txt");
}

bool spr()
{
	string a;
	string b;
	while (plik3.good())
	{
		getline(plik2, a);
		getline(plik3, b);
		if (a != b) return false;
	}
	return true;
}

int main()
{
	cout << Jeden() << " pary to anagramy\n" << endl;
	Dwa();
	Trzy("bura");
	Cztery();
	cout << "czy poprawne: " << spr();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
