#include <bits/stdc++.h>

using namespace std;


pair<long long, int> przestawRek(long long int n, int licznikWywolan) {
    long long int r = n % 100;
    long long int a = r / 10;
    long long int b = r % 10;
    n = n / 100;

    long long int w = 0;
    if (n > 0)
        w = a + (10 * b) + (100 * przestawRek(n, licznikWywolan + 1).first);
    else {
        if (a > 0)
            w = a + (10 * b);
        else
            w = b;
    }

    return pair<long long, int>(w, licznikWywolan);
}


int main() {

    // cout << "Przypadek 1: " << (przestawRek(316498) == 134689) << endl;
    // cout << "Przypadek 2: " << (przestawRek(43657688) == 34566788) << endl;
    // cout << "Przypadek 3: " << (przestawRek(154005710) == 145007501) << endl;
    // cout << "Przypadek 4: " << (przestawRek(998877665544321) == 989786756453412) << endl;
    pair<long long, int> wynik = przestawRek(316498, 1);
    cout << "Przypadek 1: " << (wynik.first == 134689) << ", liczba wywolan: " << wynik.second << endl;
    // cout << "Przypadek 2: " << (przestawRek(43657688) == 34566788) << endl;
    // cout << "Przypadek 3: " << (przestawRek(154005710) == 145007501) << endl;
    // cout << "Przypadek 4: " << (przestawRek(998877665544321) == 989786756453412) << endl;

    return 0;
}
