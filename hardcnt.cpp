#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> factorToCalculate = vector<int>(4000);

long long factor(int n) {
    if (n <= 1) {
        return 1;
    }
    long long res = n * factor(n - 1);
    return res > 0 ? res : 1;
}

void initFactors(int n) {
    int MIN = 1024;
    int MAX = 1024 * (64 + n + 1);
    for (int &i: factorToCalculate) {
        i = MIN + (abs((int) random()) % static_cast<int>(MAX - MIN + 1));
    }
}


int main(int argc, const char *argv[]) {
    if (argc != 2) {
        cerr << "Expected 1 argument from cmd";
        return -1;
    }

    int n = atoi(argv[1]);
    initFactors(n);

    long long sum = 0;
    for (int &i: factorToCalculate) {
        sum += factor(i);
    }

    cout << sum << endl;
}