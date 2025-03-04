#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

int maxCrossingSum(vector<int>& arr, int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN, rightSum = INT_MIN;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArraySum(vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = low + (high - low) / 2;
    int leftMax = maxSubArraySum(arr, low, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);
    return max(leftMax, rightMax, crossMax);
}

int main() {
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << maxSubArraySum(arr, 0, size - 1) << endl;
    return 0;
}
