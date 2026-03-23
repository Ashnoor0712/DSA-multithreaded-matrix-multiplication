// Ashnoor Jattana

#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <cstdlib>

using namespace std;

static const int MAX_N = 100;

int M, N, K;
int A[MAX_N][MAX_N];
int B[MAX_N][MAX_N];
long long C[MAX_N][MAX_N];

void readA() {
    ifstream f("A.txt");
    if (!f) {
        cerr << "Error: Could not open A.txt\n";
        exit(1);
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(f >> A[i][j])) {
                cerr << "Error: Invalid data in A.txt\n";
                exit(1);
            }
        }
    }
}

void readB() {
    ifstream f("B.txt");
    if (!f) {
        cerr << "Error: Could not open B.txt\n";
        exit(1);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (!(f >> B[i][j])) {
                cerr << "Error: Invalid data in B.txt\n";
                exit(1);
            }
        }
    }
}

void threadCallback(int x, int y) {
    long long sum = 0;
    for (int k = 0; k < N; ++k) {
        sum += 1LL * A[x][k] * B[k][y];
    }
    C[x][y] = sum;
}

int main() {
    cout << "Enter M N K: ";
    cin >> M >> N >> K;

    if (!cin || M <= 0 || N <= 0 || K <= 0 || M > MAX_N || N > MAX_N || K > MAX_N) {
        cerr << "Invalid input.\n";
        return 1;
    }

    readA();
    readB();

    vector<thread> myThreads;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < K; ++j) {
            myThreads.push_back(thread(threadCallback, i, j));
        }
    }

    for (auto& t : myThreads) {
        t.join();
    }

    cout << "Result Matrix:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < K; ++j) {
            if (j) cout << ' ';
            cout << C[i][j];
        }
        cout << '\n';
    }

    return 0;
}
