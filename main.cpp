#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int rozmiar = 1000;
  int t[rozmiar];
  int dlugosc = 0;
  int max_dlugosc = 0;
  int pierwszy = 0;
  int max_pierwszy = 0;
  ifstream plik("liczby2.txt");
  for (int i = 0; i < 1000; i++)
    plik >> t[i];
  for (int i = 1; i < rozmiar; i++) {
    if (t[i] >= t[i - 1]) {
      dlugosc++;
      if (pierwszy == 0) {
        pierwszy = t[i - 1];
        dlugosc++;
      }
    } else {
      if (dlugosc > max_dlugosc) {
        max_dlugosc = dlugosc;
        max_pierwszy = pierwszy;
      }
      pierwszy = 0;
      dlugosc = 0;
    }
  }
  cout << "Pierwszy element ciagu: " << max_pierwszy << "\n";
  cout << "Liczba elementow ciagu: " << max_dlugosc << "\n";
  return 0;
}
