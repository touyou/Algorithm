/**
 * ソースコード探検隊のコード
 * これをひな形に他の言語でも実装してみる
 */

typedef int value_type;

void mergeSort(value_type nums[], value_type temp[], int array_size) {
    m_sort(nums, temp, 0, array_size-1);
}

void m_sort(int nums[], int temp[], int left, int right) {
    int mid;

    if (right > left) {
        mid = (right + left) / 2;
        m_sort(nums, temp, left, mid);
        m_sort(nums, temp, mid+1, right);
        merge(nums, temp, left, mid+1, right);
    }
}

void merge(int nums[], int temp[], int left, int mid, int right) {
    int i, left_end, num_elems, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    num_elems = right - left + 1;
    while ((left <= left_end) && (mid <= right)) {
        if (nums[left] <= nums[mid]) {
            temp[tmp_pos] = nums[left];
            tmp_pos++; left++;
        } else {
            temp[tmp_pos] = nums[mid];
            tmp_pos++; mid++;
        }
    }

    while (left <= left_end) {
        temp[tmp_pos] = nums[left];
        tmp_pos++; left++;
    }

    while (mid <= right) {
        temp[tmp_pos] = nums[mid];
        tmp_pos++; mid++;
    }

    // 賢いけどわかりにくいかも？
    for (i = 0; i < num_elems; i++) {
        nums[right] = temp[right];
        right--;
    }
}
