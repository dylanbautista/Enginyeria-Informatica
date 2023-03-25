#include <iostream>
#include <cmath>
using namespace std;

double func(double d) {
    return d * sqrt(pow(d, 2) + 9);
}

/*
    Precondició: Una funció contínua, a la funció func, entre l'interval tancat [a,b]. Essent a i b nombres amb coma flotant double.
    Postcondició: El resultat, double, de la integral de la funció entre l'interval [a,b] calculat mitjançant
    la regla de simpson.
*/
double integration_by_simpson(double a, double b) {
    double n = 100000.0;
    double d_x = (b - a) / n;
    double x_k;

    double result = 0;
    bool flag = false;

    for (double k = 0.0; k <= n; ++k) {
        x_k = a + (k*d_x);
        if (k == 0.0 or k == n) result += func(x_k);
        else if (not flag) {result += 4 * func(x_k); flag = true;}
        else {result += 2 * func(x_k); flag = false;}
    }

    result = double(1.0/3.0) * result * d_x;
    return result;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(17);
    cout << integration_by_simpson(0, 4) << endl;

}