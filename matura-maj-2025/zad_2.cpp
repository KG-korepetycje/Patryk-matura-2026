#include <bits/stdc++.h>

using namespace std;

const int LICZBA_LINII = 2000;
const int LICZBA_KOLUMN = 12;

ifstream fin;
ofstream fout;


bool czyPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}


void zadanie1() {
    fin.open("./dane/symbole.txt");
    fout.open("./wyniki/wyniki2.txt");
    fout << "2.1." << endl;
    string line;
    for (int i = 0; i < LICZBA_LINII; i++) {
        fin >> line;
        if (czyPalindrom(line))
            fout << line << endl;
    }
    // while (getline(fin, line)) {
    //     if (czyPalindrom(line))
    //         fout << line << endl;
    // }
    fin.close();
    fout.close();
}


bool czySrodekKwadratu(string siatka[LICZBA_LINII], int wiersz, int kolumna) {
    if (wiersz == 0 || kolumna == 0 || wiersz == LICZBA_LINII - 1 || kolumna == LICZBA_KOLUMN - 1)
        return false;
    if (siatka[wiersz - 1][kolumna - 1] != siatka[wiersz][kolumna])
        return false;
    if (siatka[wiersz - 1][kolumna] != siatka[wiersz][kolumna])
        return false;
    if (siatka[wiersz - 1][kolumna + 1] != siatka[wiersz][kolumna])
        return false;
    if (siatka[wiersz][kolumna - 1] != siatka[wiersz][kolumna])
        return false;
    if (siatka[wiersz][kolumna + 1] != siatka[wiersz][kolumna])
        return false;
    if (siatka[wiersz + 1][kolumna - 1] != siatka[wiersz][kolumna])
        return false;
    if (siatka[wiersz + 1][kolumna] != siatka[wiersz][kolumna])
        return false;
    if (siatka[wiersz + 1][kolumna + 1] != siatka[wiersz][kolumna])
        return false;

    return true;
}


void zadanie2() {
    fin.open("./dane/symbole.txt");
    fout.open("./wyniki/wyniki2.txt");
    fout << "2.2." << endl;

    string siatka[LICZBA_LINII];
    for (int i = 0; i < LICZBA_LINII; i++) {
        fin >> siatka[i];
    }

    int licznik = 0;
    for (int i = 0; i < LICZBA_LINII; i++) {
        for (int j = 0; j < LICZBA_KOLUMN; j++) {
            if (czySrodekKwadratu(siatka, i, j)) {
                licznik++;
            }
        }
    }
    fout << licznik;
    for (int i = 0; i < LICZBA_LINII; i++) {
        for (int j = 0; j < LICZBA_KOLUMN; j++) {
            if (czySrodekKwadratu(siatka, i, j)) {
                fout << " " << i + 1 << " " << j + 1;
            }
        }
    }
    fout << "\n";

    fin.close();
    fout.close();
}


int main() {

    // zadanie1();
    zadanie2();

    return 0;
}
