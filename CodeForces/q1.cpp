#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int num, factor, product;
        cin >> num >> factor >> product;
        if (num * product < factor || (-1) * num * product > factor) {
            cout << -1 << endl;
        } else {
            if (factor == 0) {
                cout << 0 << endl;
            } else if (factor > 0) {
                if (factor % product == 0) {
                    cout << factor / product << endl;
                } else {
                    cout << factor / product + 1 << endl;
                }
            } else {
                if (abs(factor) % product == 0) {
                    cout << abs(factor) / product << endl;
                } else {
                    cout << abs(factor) / product + 1 << endl;
                }
            }
        }
    }
    return 0;
}