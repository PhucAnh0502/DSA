#include <iostream>
#include <cmath>
using namespace std;

bool Narcissistic(int a) {
    int originalNumber = a;
    int numDigits = 0;
    int sum = 0;

    while (a != 0) {
        a /= 10;
        numDigits++;
    }

    a = originalNumber;
    while (a != 0) {
        int digit = a % 10;
        sum += pow(digit, numDigits);
        a /= 10;
    }

    return (sum == originalNumber);
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    bool hasNarcissistic = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (Narcissistic(a[i])) {
            cout << a[i] << " ";
            hasNarcissistic = true;
        }
    }

    if (!hasNarcissistic) {
        cout << "NO";
    }

    return 0;
}
