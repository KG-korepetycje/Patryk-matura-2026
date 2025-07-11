#include <bits/stdc++.h>

using namespace std;

const string PLIK_WEJSCIOWY = "./dane/liczby_przyklad.txt";
const string PLIK_WYJSCIOWY = "./wyniki/wyniki4.txt";
const int LICZBA_LICZB_PIERWSZY_WIERSZ = 200;
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


bool czy_mozliwy_rozklad(int n, map<int, int> czynniki_pierwsze_plik) {
    map<int, int> rozklad_liczby;

    int dzielnik = 2;
    // cout << "Rozklad dla liczby: " << n << endl;
    while (n > 1) {
        if (n % dzielnik == 0) {
            if (rozklad_liczby.count(dzielnik) == 0)  // Sprawdzamy, czy dzielnik byl dodany do mapy
                rozklad_liczby[dzielnik] = 1;  // Nie byl
            else
                rozklad_liczby[dzielnik]++;
            n = n / dzielnik;
        }
        else
            dzielnik++;
    }

    // for (pair<int, int> klucz_wartosc : rozklad_liczby) {
    //     cout << klucz_wartosc.first << " -> " << klucz_wartosc.second << endl;
    // }

    for (pair<int, int> dzielnik_licznik : rozklad_liczby) {
        if (czynniki_pierwsze_plik.count(dzielnik_licznik.first) == 0)  // Sprawdzamy, czy dany dzielnik w ogole wystapil w pliku
            return false;
        if (czynniki_pierwsze_plik[dzielnik_licznik.first] < dzielnik_licznik.second)
            return false;
    }

    return true;
}


void zadanie4_3() {

    fin.open(PLIK_WEJSCIOWY);
    fout << "4.3." << endl;

    map<int, int> czynniki_pierwsze_plik;

    int liczba;
    for (int i = 0; i < LICZBA_LICZB_PIERWSZY_WIERSZ; i++) {
        fin >> liczba;
        if (czynniki_pierwsze_plik.count(liczba) == 0)
            czynniki_pierwsze_plik[liczba] = 1;
        else
            czynniki_pierwsze_plik[liczba]++;
    }

    // for (pair<int, int> klucz_wartosc : czynniki_pierwsze_plik) {
    //     cout << "Klucz: " << klucz_wartosc.first << " -> " << klucz_wartosc.second << endl;
    // }

    for (int i = 0; i < LICZBA_LICZB_DRUGI_WIERSZ; i++) {
        fin >> liczba;
        if (czy_mozliwy_rozklad(liczba, czynniki_pierwsze_plik))
            fout << liczba << endl;
    }
    
    fin.close();

}


void zadanie4_4() {

    fin.open(PLIK_WEJSCIOWY);
    fout << "4.4." << endl;
    
    int suma = 0;
    int liczby[LICZBA_LICZB_PIERWSZY_WIERSZ + 1];
    for (int i = 0; i < LICZBA_LICZB_PIERWSZY_WIERSZ; i++) {
        fin >> liczby[i];
        if (i < 50)
            suma = suma + liczby[i];
    }

    int ogon = 0;
    int glowa = 49;
    float max_srednia = suma / 50;
    int max_dlugosc_ciagu = 50;
    int max_pierwszy_element_ciagu = liczby[0];

    while (ogon <= LICZBA_LICZB_PIERWSZY_WIERSZ - 50) {
        if (glowa - ogon == 49)
            glowa++;
        else {
            // Trzeba zrobic sprawdzenie, czy bardziej oplaca sie
            // rozszerzyc glowa czy skrocic ogonem
        }
    }
    
    fin.close();

}


int main() {
    fout.open(PLIK_WYJSCIOWY);

    zadanie4_1();
    zadanie4_2();
    zadanie4_3();

    fout.close();

    return 0;
}
