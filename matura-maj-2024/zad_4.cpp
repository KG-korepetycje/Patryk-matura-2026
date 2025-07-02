#include <bits/stdc++.h>

using namespace std;

const string PLIK_WEJSCIOWY = "./dane/liczby.txt";
const string PLIK_WYJSCIOWY = "./wyniki/wyniki4.txt";
const int LICZBA_LICZB_PIERWSZY_WIERSZ = 3000;
const int LICZBA_LICZB_DRUGI_WIERSZ = 20;

ifstream fin;
ofstream fout;


void zadanie4_1() {
    fin.open(PLIK_WEJSCIOWY);
    fout << "4.1." << endl;

    int liczby_pierwszy_wiersz[LICZBA_LICZB_PIERWSZY_WIERSZ + 1];
    int liczby_drugi_wiersz[LICZBA_LICZB_DRUGI_WIERSZ + 1];
    for (int i = 0; i < LICZBA_LICZB_PIERWSZY_WIERSZ; i++) {
        fin >> liczby_pierwszy_wiersz[i];
    }
    for (int i = 0; i < LICZBA_LICZB_DRUGI_WIERSZ; i++) {
        fin >> liczby_drugi_wiersz[i];
    }

    int licznik = 0;
    bool liczba_znaleziona;
    int j;

    for (int i = 0; i < LICZBA_LICZB_PIERWSZY_WIERSZ; i++) {
        liczba_znaleziona = false;
        j = 0;
        while (!liczba_znaleziona && j < LICZBA_LICZB_DRUGI_WIERSZ) {
            if (liczby_drugi_wiersz[j] % liczby_pierwszy_wiersz[i] == 0) {
                licznik++;
                liczba_znaleziona = true;  // aby liczyc kazda liczbe tylko raz (alternatywa: break)
            }
            j++;
        }
    }

    fout << licznik << endl << endl;
    fin.close();
}


void bubble_sort(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar - 1 - i; j++) {
            if (tablica[j] > tablica[j + 1]) {
                int temp = tablica[j + 1];
                tablica[j + 1] = tablica[j];
                tablica[j] = temp;
            }
        }
    }
}


void zadanie4_2() {
    fin.open(PLIK_WEJSCIOWY);
    fout << "4.2." << endl;

    int liczby_pierwszy_wiersz[LICZBA_LICZB_PIERWSZY_WIERSZ + 1];
    for (int i = 0; i < LICZBA_LICZB_PIERWSZY_WIERSZ; i++) {
        fin >> liczby_pierwszy_wiersz[i];
    }

    bubble_sort(liczby_pierwszy_wiersz, LICZBA_LICZB_PIERWSZY_WIERSZ);
    int indeks = LICZBA_LICZB_PIERWSZY_WIERSZ - 101;
    fout << liczby_pierwszy_wiersz[indeks] << endl << endl;
    
    fin.close();
}


int main() {
    fout.open(PLIK_WYJSCIOWY);

    zadanie4_1();
    zadanie4_2();

    fout.close();

    return 0;
}
