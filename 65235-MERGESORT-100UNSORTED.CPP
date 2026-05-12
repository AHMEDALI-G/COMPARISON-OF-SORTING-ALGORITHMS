#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int arr[100] = {
    100,99,98,97,96,95,94,93,92,91,
    90,89,88,87,86,85,84,83,82,81,
    80,79,78,77,76,75,74,73,72,71,
    70,69,68,67,66,65,64,63,62,61,
    60,59,58,57,56,55,54,53,52,51,
    50,49,48,47,46,45,44,43,42,41,
    40,39,38,37,36,35,34,33,32,31,
    30,29,28,27,26,25,24,23,22,21,
    20,19,18,17,16,15,14,13,12,11,
    10,9,8,7,6,5,4,3,2,1
    };

    int temp[100];

    clock_t start = clock();

    for(int size = 1; size < 100; size *= 2)
    {
        for(int left = 0; left < 100 - size; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, 99);

            int i = left, j = mid + 1, k = left;

            while(i <= mid && j <= right)
                temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];

            while(i <= mid) temp[k++] = arr[i++];
            while(j <= right) temp[k++] = arr[j++];

            for(int p = left; p <= right; p++)
                arr[p] = temp[p];
        }
    }

    clock_t end = clock();

    cout << "Sorted Array:\n";
    for(int i = 0; i < 100; i++)
        cout << arr[i] << " ";

    double time_taken =
    ((double)(end - start) / CLOCKS_PER_SEC) * 1000000000;

    cout << "\n\nTime Taken: " << time_taken << " nanoseconds";

    return 0;
}