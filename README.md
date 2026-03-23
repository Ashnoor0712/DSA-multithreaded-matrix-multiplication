## Multithreaded Matrix Multiplication in C++

1. Overview
This project implements matrix multiplication in C++ using multithreading. It reads two matrices from input files and creates a separate thread for each element in the resulting matrix.

The goal of the project is to demonstrate how matrix multiplication can be parallelized using threads, while also practicing file input, synchronization, and matrix processing in C++.

2. Features
- Reads matrix data from `A.txt` and `B.txt`
- Accepts matrix dimensions from user input
- Creates one thread per output cell
- Computes the result matrix in parallel
- Displays the final multiplied matrix
- Uses a mutex for safe threaded output during debugging

3. Concepts Covered
- Multithreading in C++
- Matrix multiplication
- File input handling
- Synchronization with mutex
- Parallel computation
- Basic systems programming concepts

4. ech Stack
- Language: C++
- Libraries Used:
  - `iostream`
  - `fstream`
  - `thread`
  - `vector`
  - `string`
  - `cstdlib`
  - `mutex`

5. File Structure
- `main.cpp` — multithreaded matrix multiplication program
- `A.txt` — input file for matrix A
- `B.txt` — input file for matrix B

6. How It Works
1. The user enters the matrix dimensions `M N K`
2. Matrix `A` is read as an `M x N` matrix from `A.txt`
3. Matrix `B` is read as an `N x K` matrix from `B.txt`
4. One thread is created for each cell in the result matrix `C`
5. Each thread computes one value of the output matrix
6. All threads are joined before printing the final result

7. How to Compile

```bash
g++ -std=c++11 -pthread main.cpp -o program
