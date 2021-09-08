/*
    SOLVE WITH MERGESORT

    arr = 0, -1, -1, 0, 9, 3, 1, 4, 2, 3, 1, 5, 6, 7, 9, 10, 15, 17, -2, 0
    arr = -2, -1, -1, 0, 0, 1, 3, 4, 5, 6, 7, 9, 10, 15, 17 (maneras de ordenar algo o subsetear)

    ---- 0. los elementos deben estar ordenados

    1. nadie con puntaje menor o igual a 0 puede ser premiado (omitir o eliminar)
    2. encontrar el primer dato que sea mayor a 0
    3. encontrar cuantos hay con puntaje mayor a 0 y calcular fact ()
*/
#include <vector>
using namespace std;

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

int subset(int n, vector<int> arr) {
    mergeSort(arr);

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            count++;
        }
    }

    return fact(count);
}

void mergeSort(vector<int> &arr) {
    if (arr.size() <= 1) {
        int mid = arr.size() / 2;
        
        vector<int> left;
        for(int i = 0; i < mid; i++) {
            left.push_back(arr[i]);
        }

        vector<int> right;
        for(int i = mid + 1; i < arr.size(); i++) {
            right.push_back(arr[i]);
        }

        mergeSort(left);
        mergeSort(right);

        merge(left, right, arr);
    }
}

void merge(vector<int> left, vector<int> right, vector<int> &arr) {
    vector<int> result;

    while(left.size() > 0 && right.size() > 0) {
        if(left[0] < right[0]) {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else {
            result.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while(left.size() > 0) {
        result.push_back(left[0]);
        left.erase(left.begin());
    }

    while(right.size() > 0) {
        result.push_back(right[0]);
        right.erase(right.begin());
    }

    arr = result;
}