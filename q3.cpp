#include <iostream>
#include <vector>
using namespace std;

const int LIMIT = 1e5;

vector<int> positions(LIMIT);

int main() {
    int arraySize;
    cin >> arraySize;

    for (int inputIndex = 0; inputIndex < arraySize; inputIndex++) {
        int inputValue;
        cin >> inputValue;
        positions[inputValue - 1] = inputIndex;
    }

    int lowerLimit = arraySize, upperLimit = 0, maxInterval = 0;

    for (int currentIndex = arraySize - 1, visitedElements = 1; currentIndex >= 0; currentIndex--, visitedElements++) {
        if (positions[currentIndex] < lowerLimit) {
            lowerLimit = positions[currentIndex];
        }
        if (positions[currentIndex] > upperLimit) {
            upperLimit = positions[currentIndex];
        }
        int currentInterval = upperLimit - lowerLimit - visitedElements + 3;
        if (currentInterval > maxInterval) {
            maxInterval = currentInterval;
        }
    }

    if (arraySize == 1) {
        maxInterval = 1;
    }

    cout << maxInterval << endl;
    return 0;
}
