#include <iostream>

class Factorial {
public:
  unsigned long long findFactorial(int n) {
    if (n <= 1) {
      return 1;
    }
    return n * findFactorial(n - 1);
  }
};

int main() {
  int num;
  std::cout << "Enter a positive integer: ";
  std::cin >> num;

  Factorial factorial;
  unsigned long long result = factorial.findFactorial(num);

  std::cout << "The factorial of " << num << " is " << result << std::endl;

  return 0;
}
