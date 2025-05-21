#include <bits/stdc++.h>

using namespace std;

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
    for (int i = 0; i < 2000; i++) {
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


int main() {

    zadanie1();

    return 0;
}
