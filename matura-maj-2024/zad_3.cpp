#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;


int nieparzysty_skrot(int n) {
    int mnoznik = 1;
    int wynik = 0;
    int cyfra;

    while (n > 0) {
        cyfra = n % 10;

        if (cyfra % 2 == 1) {  // sprawdzamy czy nieparzysta cyfra
            wynik += cyfra * mnoznik;
            mnoznik *= 10;
        }

        n = n / 10;
    }

    return wynik;
}


void zadanie3_2() {
    const string plik_wejsciowy = "./dane/skrot.txt";
    const string plik_wyjsciowy = "./wyniki/wyniki3_2.txt";
    const int liczba_linii = 200;

    fin.open(plik_wejsciowy);
    fout.open(plik_wyjsciowy);

    int liczba;
    int licznik = 0;
    int maksi = 0;
    for (int i = 0; i < liczba_linii; i++) {
        fin >> liczba;
        if (nieparzysty_skrot(liczba) == 0) {
            licznik++;
            if (liczba > maksi)
                maksi = liczba;
        }
    }

    fout << licznik << endl << maksi << endl;

    fin.close();
    fout.close();
}


int nwd(int a, int b) {
    if (b != 0)
    	return nwd(b, a % b);
    return a;
}


void zadanie3_3() {
    const string plik_wejsciowy = "./dane/skrot2.txt";
    const string plik_wyjsciowy = "./wyniki/wyniki3_3.txt";
    const int liczba_linii = 200;

    fin.open(plik_wejsciowy);
    fout.open(plik_wyjsciowy);

    int liczba;
    for (int i = 0; i < liczba_linii; i++) {
        fin >> liczba;
        if (nwd(liczba, nieparzysty_skrot(liczba)) == 7)
            fout << liczba << endl;
    }

    fin.close();
    fout.close();
}


int main() {

    zadanie3_2();
    zadanie3_3();

    return 0;
}
