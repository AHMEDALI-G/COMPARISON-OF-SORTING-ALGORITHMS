#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    clock_t start = clock();

    // Quick Sort (manual stack simulation - simple version)
    int low = 0, high = 4;
    int stack[10];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while(top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        int i = low, j = high;
        int pivot = arr[(low + high) / 2];

        while(i <= j)
        {
            while(arr[i] < pivot) i++;
            while(arr[j] > pivot) j--;

            if(i <= j)
            {
                swap(arr[i], arr[j]);
                i++; j--;
            }
        }

        if(low < j)
        {
            stack[++top] = low;
            stack[++top] = j;
        }

        if(i < high)
        {
            stack[++top] = i;
            stack[++top] = high;
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