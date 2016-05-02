#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void Numbers_to_Words (string ns, int n);
void nkbin (int n);

int main(int argc, char **argv)
{
	unsigned long int n = atoi (argv[1]);
	while (n >= 100000 || n <= 0) cin >> n;
	string ns = to_string(n); //moze nie do konca dobre skoro juz mam tablice charow ale wygodne pozniej
	Numbers_to_Words(ns, n);
	nkbin(n);
}

void Numbers_to_Words (string ns, int n)
{
	int i = ns.size() - 1;
	string word;
	string one[10]{ "", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec" };
	string teen[10]{ "dziesiec", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie" };
	string ten[10]{ "", "dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat" };
	string hundred[10]{ "", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset" };
	do
	{
		cout << "i = " << i << endl;
		if (i == ns.size() - 1)
		{
			if ((i - 1) < 0) word = one[n % 10] + word;
			else if (ns[i - 1] != '1') word = ten[(n % 100) / 10] + " " + one[n % 10] + " " + word;
			else if (ns[i - 1] == '1') word = teen[n % 10] + " " + word;
		}
		if (i == ns.size() - 3) word = hundred[n % 10] + " " + word;
		if (i == ns.size() - 4)
		{
			if ((i - 1) < 0)
			{
				if (ns[i] == '1') word = "tysiac " + word;
				else if ((ns[i] == '2') || (ns[i] == '3') || (ns[i] == '4')) word = one[n % 10] + " tysiace " + word;
				else word = one[n % 10] + " tysiecy " + word;
			}
			else if (ns[i - 1] == '1') word = teen[n % 10] + " tysiecy " + word;
			else if (ns[i - 1] != '1')
			{
				if ((ns[i] == '2') || (ns[i] == '3') || (ns[i] == '4')) word = ten[(n % 100) / 10] + " " + one[n % 10] + " tysiace " + word;
				else if (ns[i] == 1) word = "tysiac " + word;
				else word = ten[(n % 100) / 10] + " " + one[n % 10] + " tysiecy " + word;
			}
		}
		if (i == ns.size() - 6) word = hundred[n % 10] + " " + word;
		n = n / 10;
		i--;
	} while (i >= 0);
	cout << word << endl;
}

void nkbin (int n)
{
	long long unsigned buf, k;
	bool result = true;
	for (k = 1; k < 100000; k++)
	{
		buf = n*k;
		do
		{
			if (buf % 10 == 1 || buf % 10 == 0)
			{
				result = true; buf = buf / 10;
			}
			else result = false;
		} while (result == true && buf > 0);
		if (result == true) break;
	}
	if (result == false) cout << "Nie znaleziono k<10^6 spelniajacego warunki.\n";
	else cout << "k spelnia warunki i jest rowne: " << k << endl;
}