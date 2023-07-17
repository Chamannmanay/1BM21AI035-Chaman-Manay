#include <iostream>
#include <vector>
#include <chrono>

class SearchAlgorithm {
public:
    int linearSearch(const std::vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target)
                return i;
        }
        return -1; // Element not found
    }

    int binarySearch(const std::vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1; // Element not found
    }
};

int main() {
    SearchAlgorithm search;

    // Example usage
    std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 10;

    // Linear Search
    auto start = std::chrono::steady_clock::now();
    int linearIndex = search.linearSearch(arr, target);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> linearTime = end - start;

    if (linearIndex != -1)
        std::cout << "Linear search: Element found at index " << linearIndex << std::endl;
    else
        std::cout << "Linear search: Element not found" << std::endl;

    // Binary Search
    start = std::chrono::steady_clock::now();
    int binaryIndex = search.binarySearch(arr, target);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> binaryTime = end - start;

    if (binaryIndex != -1)
        std::cout << "Binary search: Element found at index " << binaryIndex << std::endl;
    else
        std::cout << "Binary search: Element not found" << std::endl;

    std::cout << "Linear search time: " << linearTime.count() << " seconds" << std::endl;
    std::cout << "Binary search time: " << binaryTime.count() << " seconds" << std::endl;

    return 0;
}
