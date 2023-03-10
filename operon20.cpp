// operon20.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
using namespace std;

ifstream plik("anagramy.txt");

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

int main()
{
	cout << Jeden() << " pary to anagramy\n" << endl;
	Dwa();
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
