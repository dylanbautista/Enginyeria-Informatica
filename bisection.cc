#include <cmath>
#include <iostream>
using namespace std;

double func(double d) {
    return (2.0 * pow(d, 4.0)) - (19.08 * pow(d, 3.0)) + (46.31 * pow(d, 2.0)) - (26.71 * d) + 60.91;
}

double func_d(double d) {
    return 2.0 * 4.0 * pow(d, 3.0) - 19.08 * 3.0 * pow(d, 2.0) + 46.31 * 2.0 * d - 26.71;
}

/*
    Precondició: Una funció contínua entre l'interval tancat [a,b]. Un error e, conegut com a epsilon.
    Postcondició: L'arrel entre l'interval amb un error menor que e.
*/
double search_root_by_bisection_iterative(double a, double b, double e, int& i, double& error) {
    double m = a;
    while (abs(b - a) >= e) {
        m = (a+b)/2;
        if (func(a) * func(m) < 0.0) b = m;
        else a = m;
        ++i;
    }
    error = abs(b - a);
    return m;
}

double search_root_by_secant_iterative(double a, double b, double e, int& i, double& error) {
    double m;
    double xn = b; //Xn es b;
    double xn_1 = a; //Xn-1 es a;

    while (abs(xn - xn_1) >= e or abs(func(xn)) >= e) {
        // m = xn - (((xn - xn_1) * func(xn) / (func(xn) - func(xn_1))));
        m = xn - ((xn - xn_1) * func(xn) / (func(xn) - func(xn_1)));
        xn_1 = xn;
        xn = m;
        //cout << i << ". xn: " << xn << " xn-1: " << xn_1 << endl;
        cout << abs(xn - xn_1) << endl;
        ++i;
    }

    error = abs(xn - xn_1);
    return m;
}

double search_root_by_newton_raphson_iterative(double a, double e, int& i, double& error) {
    double h;
    double xn = a;

    do {
        h = func(xn) / func_d(xn);
        xn = xn - h;
        cout << i << endl;
        ++i;
    } while (abs(h) >= e);

    error = abs(h);
    return xn;
}



int main() {
    cout.setf(ios::fixed);
    cout.precision(17);
    int i = -1;
    double error;
    /*cout << search_root_by_bisection_iterative(1.0, 2.0, 0.000100, i, error);
    cout << " en " << i << " iteraciones, con un error de: " << error << endl;*/
    i = 0;
    /*cout << search_root_by_secant_iterative(-0.8700000000000001, -0.5700000000000001, 0.000010, i, error);
    cout << " en " << i << " iteraciones, con un error de: " << error << endl;*/
    cout << search_root_by_newton_raphson_iterative(2.455, 0.000010, i, error);
    cout << " en " << i << " iteraciones, con un error de: " << error << endl;


}