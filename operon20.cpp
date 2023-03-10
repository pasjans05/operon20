// operon20.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
using namespace std;

ifstream plik("anagramy.txt");

bool AnagrSpr(string a, string b)
{
	if (a.length() != b.length()) return false;
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
		if (spr == false) return false;
	}
	return true;
}

int Jeden()
{
	string a;
	string b;
	int ile = 0;
	for (int i = 0; i < 200; i++)
	{
		plik >> a >> b;
		if (AnagrSpr(a, b)) ile++;
	}
	return ile;
}

int main()
{
	cout << Jeden() << " par to anagramy\n";
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
