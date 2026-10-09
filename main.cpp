#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    long double tochnost;
    cout << "Введите точность (> 0): ";
    if (!(cin >> tochnost)) {
        cout << "Ошибка: требуется число.\n";
        return 1;
    }
    cout << setprecision(12) << "Введена точность = "
         << tochnost << '\n';
    if (!isfinite(tochnost) || tochnost <= 0) {
        cout << "Ошибка: точность должна быть конечной и > 0.\n";
        return 1;
    }
    const long double tochnayaSumma = 0.25L;
    unsigned long long chisloSlagaemyh = 0;
    long double summa = 0, slagaemoe = 1.0L / 6;
    long double ostatok = tochnayaSumma;
    while (slagaemoe >= tochnost || ostatok > tochnost) {
        if (summa + slagaemoe == summa) {
            cout << "Ошибка: точность типа исчерпана.\n";
            return 1;
        }
        summa += slagaemoe;
        ++chisloSlagaemyh;
        long double nomer = chisloSlagaemyh;
        ostatok = 1.0L / (2 * (nomer + 1) * (nomer + 2));
        slagaemoe = 1.0L / ((nomer + 1) * (nomer + 2) * (nomer + 3));
    }
    long double pogreshnost = fabs(summa - tochnayaSumma);
    if (pogreshnost > tochnost) {
        cout << "Ошибка: заданная точность не достигнута.\n";
        return 1;
    }
    cout << fixed << setprecision(12);
    cout << "Число слагаемых = " << chisloSlagaemyh << '\n';
    cout << "Сумма = " << summa << '\n';
    cout << "Точная сумма = " << tochnayaSumma << '\n';
    cout << "Погрешность = " << pogreshnost << '\n';
    return 0;
}
