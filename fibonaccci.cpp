#include <iostream>
#include <vector>

class Fibonacci {
public:
  std::vector<int> generateFibonacci(int n) {
    std::vector<int> fibNumbers;
    generateFibonacciHelper(n, fibNumbers);
    return fibNumbers;
  }

private:
  void generateFibonacciHelper(int n, std::vector<int>& fibNumbers) {
    if (n <= 0) {
      return;
    }
    if (n == 1) {
      fibNumbers.push_back(0);
      return;
    }
    generateFibonacciHelper(n - 1, fibNumbers);
    if (n == 2) {
      fibNumbers.push_back(1);
      return;
    }
    int fibNMinus1 = fibNumbers[n - 2];
    int fibNMinus2 = fibNumbers[n - 3];
    fibNumbers.push_back(fibNMinus1 + fibNMinus2);
  }
};

int main() {
  int n;
  std::cout << "Enter the value of N: ";
  std::cin >> n;

  Fibonacci fib;
  std::vector<int> fibNumbers = fib.generateFibonacci(n);

  std::cout << "The first " << n << " Fibonacci numbers are: ";
  for (int number : fibNumbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;

  return 0;
}
