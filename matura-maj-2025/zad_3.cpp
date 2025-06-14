#include <bits/stdc++.h>

using namespace std;

const string PLIK_WEJSCIOWY = "./dane/dron.txt";
const string PLIK_WYJSCIOWY = "./wyniki/wyniki3.txt";
const int LICZBA_LINII = 100;

ifstream fin;
ofstream fout;


int nwd(int a, int b)
{
    if (b != 0)
    	return nwd(b, a % b);
    return a;
}


void zadanie1() {
    fin.open(PLIK_WEJSCIOWY);
    fout << "3.1." << endl;

    int a, b;
    int licznik_par = 0;
    for (int i = 0; i < LICZBA_LINII; i++) {
        fin >> a >> b;
        if (nwd(abs(a), abs(b)) > 1)
            licznik_par++;
    }

    fout << licznik_par << endl << endl;

    fin.close();
}


bool czy_wewnatrz_kwadratu(int x, int y) {
    if (x <= 0 || x >= 5000)
        return false;
    if (y <= 0 || y >= 5000)
        return false;
    return true;
}


struct punkt {
    int x;
    int y;
};


void zadanie2() {
    fin.open(PLIK_WEJSCIOWY);
    fout << "3.2." << endl;

    int a, b;
    int x = 0;
    int y = 0;
    int licznik_wewnatrz_kwadratu = 0;
    punkt punkty[LICZBA_LINII];

    for (int i = 0; i < LICZBA_LINII; i++) {
        fin >> a >> b;
        x += a; // x = x + a;
        y += b; // y = y + b;
        if (czy_wewnatrz_kwadratu(x, y))
            licznik_wewnatrz_kwadratu++;
        
        punkty[i] = punkt {x, y};
    }
    
    fout << "a) " << licznik_wewnatrz_kwadratu << endl;

    for (int i = 0; i < LICZBA_LINII - 2; i++) {
        punkt lewy_koniec = punkty[i];
        for (int j = i + 1; j < LICZBA_LINII - 1; j++) {
            punkt srodek = punkty[j];
            for (int k = j + 1; k < LICZBA_LINII - 1; k++) {
                punkt prawy_koniec = punkty[k];
                if (
                    (lewy_koniec.x + prawy_koniec.x) / 2 == srodek.x &&
                    (lewy_koniec.y + prawy_koniec.y) / 2 == srodek.y
                ) {
                    fout << "b) (" << lewy_koniec.x << ", " << lewy_koniec.y << "), (" << srodek.x << ", " << srodek.y << "), (" << prawy_koniec.x << ", " << prawy_koniec.y << ")" << endl;
                    fin.close();
                    return;
                }
            }
        }
    }
}


int main() {

    fout.open(PLIK_WYJSCIOWY);

    zadanie1();
    zadanie2();

    fout.close();
    // zadanie3();
    // zadanie4();

    return 0;
}
