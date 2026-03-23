
// ashnoor jattana


#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include <cstdlib>
#include <mutex>

using namespace std;

static const int MAX_N = 100;

int M, N, K; // M is rows(4), N is cols in B and rows in A (5), K is cols in B(6) ->
mutex mt; //

int A[MAX_N][MAX_N];// 4,5
int B[MAX_N][MAX_N]; //5,6
long long C[MAX_N][MAX_N]; // 4X6


void readA() { ifstream f("A.txt");
  for (int i=0;i<M;++i) for (int j=0;j<N;++j) f >> A[i][j]; }

void readB() { ifstream f("B.txt");
  for (int i=0;i<N;++i) for (int j=0;j<K;++j) f >> B[i][j]; }


/*bool read_matrix(const string& filename, int rows, int cols, int outp[MAX_N][MAX_N]) {
   
    ifstream file_1(filename);
    if (!file_1.open)
        return false;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            file_1 >> outp[i][j]; // reading first
            //return false;
           // outp[i][j] = file_1[i][j];
            if(!file_1)
                return false;
        }
    }
    return true;
}*/

// one thread computes cell (x,y)
void threadCallback(int x, int y) {
    long long sum = 0;
    for (int k = 0; k < N; ++k) sum += 1LL * A[x][k] * B[k][y];
    C[x][y] = sum;

    // Uncomment for per-thread debug:
    lock_guard<mutex> g(mt);
     cerr << "Cell " << x << "," << y << " = " << sum << "\n";
}

int main() {
   /* (int argc, char** argv)
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " M N K\n";
        return 1;
    }
    M = atoi(argv[1]); N = atoi(argv[2]); K = atoi(argv[3]);
    if (M <= 0 || N <= 0 || K <= 0) {
        cerr << "Invalid sizes (max " << MAX_N << ").\n";
        return 1;
    }*/
    
    /*int argc;
    char** argv;
    
    if ( argc < 4) {
        std::cout << "Enter M N K: ";
        std::cin >> M >> N >> K;
        if (!std::cin || M <= 0 || N <= 0 || K <= 0) {
            std::cerr << "Invalid input.\n";
            return 1;
        }
   
    }*/


   /* if (!readA("A.txt", M, N, A)) {
        cerr << "Failed to read A.txt as " << M << "x" << N << ".\n";
        return 1;
    }
    if (!readB("B.txt", N, K, B)) {
        cerr << "Failed to read B.txt as " << N << "x" << K << ".\n";
        return 1;
    }*/
    
    cout << "Enter M N K: ";
        cin >> M >> N >> K; //  enter 4 5 6

        if (!cin || M <= 0 || N <= 0 || K <= 0 || M > MAX_N || N > MAX_N || K > MAX_N) {
            cerr << "Invalid input.\n";
            return 1;
        }

        // Read matrices
        readA();
        readB();

    vector<thread> myThreads;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            myThreads.push_back(thread(threadCallback, i, j));
        }
    }

   
    
    // Join all threads
        for (auto &t : myThreads)
            t.join();



    // Print result in C
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < K; ++j) {
            if (j) cout << ' ';
            cout << C[i][j];
        }
        cout << '\n';
    }
    return 0;
}
