#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int temp[5];

    clock_t start = clock();

    for(int size = 1; size < 5; size *= 2)
    {
        for(int left = 0; left < 5 - size; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, 4);

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
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    double time_taken =
    ((double)(end - start) / CLOCKS_PER_SEC) * 1000000000;

    cout << "\n\nTime Taken: " << time_taken << " nanoseconds";

    return 0;
}