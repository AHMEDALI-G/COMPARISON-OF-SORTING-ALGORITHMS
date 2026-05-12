#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};

    clock_t start = clock();

    for(int i = 0; i < 4; i++)
    {
        int min = i;

        for(int j = i + 1; j < 5; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        swap(arr[i], arr[min]);
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