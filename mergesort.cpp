#include <cstdio>
using namespace std;
const int MAXn = 1e5+5;

void combine(int A[], int min, int max, int mid) {
    int leftLen = mid - min + 1;
    int rightLen = max - mid;
    int* left = new int[leftLen];
    int* right = new int[rightLen];

    for (int i = 0; i < leftLen; i++)
        left[i] = A[min + i];
    
    for (int i = 0; i < rightLen; i++)
        right[i] = A[i + mid + 1];
    
    left[leftLen] = 2147483647;
    right[rightLen] = 2147483647;
    
    for (int k = min, i = 0, j = 0; k <= max; k++) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
    }
}

void Merge_Sort(int A[], int min, int max) {
    if (min < max) {
        int mid = (min + max) / 2;
        Merge_Sort(A, min, mid);
        Merge_Sort(A, mid + 1, max);
        combine(A, min, max, mid);
    }
}

int main() {
    int len;
    int A[MAXn];
    scanf("%d", &len);
    
    for (int i = 0; i < len; i++)
        scanf("%d", &A[i]);
    
    Merge_Sort(A, 0, len-1);
    
    for (int i = 0; i < len; i++) {
        printf("%d", A[i]);
    }
    return 0;
}