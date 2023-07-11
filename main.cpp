#include <iostream>
#include <vector>

using namespace std;

vector<long long> pow10(18);

// Function to calculate the summation of the number of digits for every number from 0 to n
int numberOfDigits(long long number, int power) {
    if (number <= pow10[power])
        return (number + 1) * power; // Sum of digits for numbers up to the given power
    else
        return pow10[power] * power + numberOfDigits(number - pow10[power], power + 1); // Recursive calculation for remaining digits
}

void ahmad_solve() {
    long long l, r;
    cin >> l >> r;

    pow10[0] = 1;
    for (int i = 1; i < 18; i++) {
        pow10[i] = pow10[i - 1] * 10LL; // Generate powers of 10 using the previous power
    }

    // Calculate the summation of the number of digits for numbers between l and r
    cout << numberOfDigits(max(l, r), 1) - numberOfDigits(min(l, r) - 1, 1) << endl;
}

int main() {
	// this code must conflict with your code
	
	int q;
	cin>>q;
    
    while(--q) {
    	ahmad_solve();
    }
    return 0;
}
