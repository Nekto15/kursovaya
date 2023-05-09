#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, b, c, x1, x2, D;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
    D = b * b - 4 * a * c;
    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0) {
        cout << "Roots are real and same." << endl;
        x1 = (-b + sqrt(D)) / (2 * a);
        cout << "x1 = x2 =" << x1 << endl;
    }
    else {
        cout << "Roots are complex and different." << endl;
        cout << "x1 = " << -b / (2 * a) << "+" << sqrt(-D) / (2 * a) << "i" << endl;
        cout << "x2 = " << -b / (2 * a) << "-" << sqrt(-D) / (2 * a) << "i" << endl;
    }
    return 0;
}
