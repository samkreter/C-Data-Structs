void merge(int array[], int low, int middle, int high)
{
    int temp[100];
    int lowCurr = low, highCurr = middle + 1, i = 0;


    while (lowCurr <= middle && highCurr <= high) {
        if (array[lowCurr] <= array[highCurr])
            temp[i++] = array[lowCurr++];
        else
            temp[i++] = array[highCurr++];
    }
    while (lowCurr <= middle)
        temp[i++] = array[lowCurr++];

    while (highCurr <= high)
        temp[i++] = array[highCurr++];

    i--;
    while (i >= 0) {
        array[low + i] = temp[i];
        i--;
    }
}

void merge_sort(int array[], int low, int high)
{
    if (low < high) {
        int middle = (high + low)/2;
        merge_sort(array, low, middle);
        merge_sort(array, middle + 1, high);
        merge(array, low, middle, high);
    }
}


