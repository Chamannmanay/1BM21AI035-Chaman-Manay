#include <iostream>

class TowerOfHanoi {
public:
  TowerOfHanoi(int num_disks)
      : num_disks_(num_disks) {}

  void solve() {
    moveDisks(num_disks_, 'A', 'C', 'B');
  }

private:
  void moveDisks(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
      std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
      return;
    }

    moveDisks(n - 1, source, auxiliary, destination);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    moveDisks(n - 1, auxiliary, destination, source);
  }

  int num_disks_;
};

int main() {
  int num_disks;
  std::cout << "Enter the number of disks: ";
  std::cin >> num_disks;

  TowerOfHanoi tower(num_disks);
  tower.solve();

  return 0;
}
