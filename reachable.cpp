#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool canReach(vector<int>& A, int i) {
    if (i < 0 || i >= A.size() || A[i] < 0) {
        return false;
    }

    if (A[i] == 0) {
        return true;
    }

    int jump = A[i];
    A[i] = -A[i];

    return canReach(A, i + jump) || canReach(A, i - jump);
}

vector<int> inputArrayInt() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> result;
    int num;

    while (iss >> num) {
        result.push_back(num);
    }

    return result;
}

int main() {
    vector<int> A = inputArrayInt();
    int i;
    cin >> i;
    bool result = canReach(A, i);
    cout << boolalpha << result << endl;

    return 0;
}
