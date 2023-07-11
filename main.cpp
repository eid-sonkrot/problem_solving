#include <iostream>
#include <vector>

using namespace std;

vector<long long> pow10(18);
const int Mod = 1e9 + 7;

// Function to calculate the summation of the number of digits for every number from 0 to n
int numberOfDigits(long long number, int power) {
    if (number <= pow10[power])
        return ((number + 1) * power) % Mod; // Sum of digits for numbers up to the given power (with modulo operation)
    else
        return (pow10[power] * power + numberOfDigits(number - pow10[power], power + 1)) % Mod; // Recursive calculation for remaining digits (with modulo operation)
}

void solution() {
    long long l, r;
    cin >> l >> r;

    pow10[0] = 1;
    for (int i = 1; i < 18; i++) {
        pow10[i] = (pow10[i - 1] * 10LL) % Mod; // Generate powers of 10 using the previous power (with modulo operation)
    }

    // Calculate the summation of the number of digits for numbers between l and r (with modulo operation)
    int result = (numberOfDigits(max(l, r), 1) - numberOfDigits(min(l, r) - 1, 1) + Mod) % Mod;
    cout << result << endl;
}

int main() {
    int Testcase;
    cin >> Testcase;
    // Solve the problem for several Test cases
    while (Testcase--) {
        solution();
    }
    return 0;
}
