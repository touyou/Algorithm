/**
 * Wikipediaの実装を個人の好みで整形したもの。
 * これを雛形として後日他の言語でも実装してみる。
 */

typedef int value_type;

value_type med3(value_type x, value_type y, value_type z) {
    if (x < y) {
        if (y < z) return y;
        else if (z < x) return x;
        else return z;
    } else {
        if (z < y) return y;
        else if (x < z) return x;
        else return z;
    }
}

void quicksort(value_type a[], int left, int right) {
    if (left < right) {
        int i = left, j = right;
        value_type tmp, pivot = med3(a[i], a[i+(j-i)/2], a[j]);
        while(1) {
            while (a[i] < pivot) i++;
            while (pivot < a[j]) j--;
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            i++; j--;
        }
        quicksort(a, left, i-1);
        quicksort(a, j+1, right);
    }
}

