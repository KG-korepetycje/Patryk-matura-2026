#include <bits/stdc++.h>

using namespace std;

const string PLIK_WEJSCIOWY = "./dane/symbole.txt";
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


int symbolNaCyfre(char symbol) {
    if (symbol == 'o')
        return 0;
    if (symbol == '+')
        return 1;
    return 2;
}


char cyfraNaSymbol(int cyfra) {
    if (cyfra == 0)
        return 'o';
    if (cyfra == 1)
        return '+';
    return '*';
}


int symboleNaDziesietny(string linia) {
    int mnoznik = 1;
    int wynik = 0;
    int wagaPozycji = 3;

    for (int i = linia.length() - 1; i >= 0; i--) {
        int cyfra = symbolNaCyfre(linia[i]);
        wynik += cyfra * mnoznik;
        mnoznik *= wagaPozycji;
    }

    return wynik;
}


string dziesietnyNaSymbole(int liczba) {
    string wynik = "";
    int wagaPozycji = 3;

    while (liczba > 0) {
        int cyfra = liczba % wagaPozycji;
        // wynik = cyfraNaSymbol(cyfra) + wynik;
        wynik += cyfraNaSymbol(cyfra);
        liczba = liczba / wagaPozycji;
    }

    reverse(wynik.begin(), wynik.end());
    return wynik; 
}


void zadanie3() {
    fin.open(PLIK_WEJSCIOWY);
    fout.open("./wyniki/wyniki2.txt");
    fout << "2.3." << endl;

    int maksi = 0;
    string maksiLinia = "";
    string linia;

    for (int i = 0; i < LICZBA_LINII; i++) {
        fin >> linia;
        int wartoscLinii = symboleNaDziesietny(linia);
        if (maksi < wartoscLinii) {
            maksi = wartoscLinii;
            maksiLinia = linia;
        }
    }

    fout << maksi << " " << maksiLinia << endl;

    fin.close();
    fout.close();
}


void zadanie4() {
    fin.open(PLIK_WEJSCIOWY);
    fout.open("./wyniki/wyniki2.txt");
    fout << "2.4." << endl;

    int suma = 0;
    string linia;

    for (int i = 0; i < LICZBA_LINII; i++) {
        fin >> linia;
        suma += symboleNaDziesietny(linia);
    }

    fout << suma << " " << dziesietnyNaSymbole(suma) << endl;

    fin.close();
    fout.close();
}


int main() {

    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();

    return 0;
}
