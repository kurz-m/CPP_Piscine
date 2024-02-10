#include <vector>
#include <algorithm>
#include <iostream>

// Comparison functions
bool comparePair(const std::pair<int, int>& a, const std::pair<int, int>& b) {
  return a.first > a.second;
}

bool comparePairFirst(const std::pair<int, int>& a, const std::pair<int, int>& b) {
  return a.first < b.first;
}

// Helper function for recursive merge sort
void mergeSort(std::vector<std::pair<int, int> >& pairs, std::vector<std::pair<int, int> >& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(pairs, temp, left, mid);
        mergeSort(pairs, temp, mid + 1, right);

        // Standard merge operation using std::merge
        std::merge(pairs.begin() + left, pairs.begin() + mid + 1,
                   pairs.begin() + mid + 1, pairs.begin() + right + 1,
                   temp.begin() + left, comparePairFirst);

        // Copy merged data back into the original vector
        std::copy(temp.begin() + left, temp.begin() + right + 1, pairs.begin() + left);
    }
}

int main() {
  std::vector<int> data = {5, 10, 4, 2, 3, 20};
  std::vector<std::pair<int, int> > pairs;

  // Create pairs
  for (size_t i = 0; i < data.size(); i += 2) {
    pairs.push_back(std::pair<int, int>(data[i], data[i + 1]));
  }

  // Sort within each pair
  for (std::vector<std::pair<int, int> >::iterator pair = pairs.begin(); pair != pairs.end(); ++pair) {
    std::sort(pair->first, pair->second, comparePair);
  }

  // Merge and Sort
  std::vector<std::pair<int, int> > temp(pairs.size());
  mergeSort(pairs, temp, 0, pairs.size() - 1);

  std::vector<std::pair<int, int> >::iterator it;

  for (it = temp.begin(); it < temp.end(); ++it) {
    std::cout << it->first << std::endl;
  }
  return 0;
}