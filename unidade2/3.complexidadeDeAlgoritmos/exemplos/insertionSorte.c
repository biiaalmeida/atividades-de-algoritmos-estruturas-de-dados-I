void insertionSort(int arr[], int n){
    int i, key, j; //c1, 1 vez
    for(i = 1; i < n; i++){ 
        key = arr[]; // c2, n vezes
        j = i - 1; //c3, n vezes
        while (j >= 0 && arr[j] > key){ 
            arr[j + 1] = arr[j]; //c4, n² vezes
            j = j - 1; //c5, n² vezes
        }
        arr[j + 1] = key;
    }
}