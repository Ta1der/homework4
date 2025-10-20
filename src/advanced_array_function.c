#include "../include/advanced_array_function.h"

int max_subarray_sum(int* nums, int size) {
    if (size == 0) return 0;
    
    int max_sum = nums[0];
    int current_sum = nums[0];
    
    for (int i = 1; i < size; i++) {
        current_sum = (nums[i] > current_sum + nums[i]) ? nums[i] : current_sum + nums[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return max_sum;
}

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int max_length = 1;
    int current_length = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 1;
        }
    }
    
    return max_length;
}
#include <stdlib.h>
int compare_intervals(const void* a, const void* b) {
    int* interval1 = (int*)a;
    int* interval2 = (int*)b;
    return interval1[0] - interval2[0];
}

int compare_intervals(const void* a, const void* b) {
    int* interval1 = (int*)a;
    int* interval2 = (int*)b;
    return interval1[0] - interval2[0];
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Сортируем интервалы
    qsort(intervals, intervalsSize, 2 * sizeof(int), compare_intervals);
    
    // Временный массив для результата
    int* temp = (int*)malloc(intervalsSize * 2 * sizeof(int));
    int result_count = 0;
    
    temp[0] = intervals[0];
    temp[1] = intervals[1];
    
    for (int i = 1; i < intervalsSize; i++) {
        int current_start = intervals[i * 2];
        int current_end = intervals[i * 2 + 1];
        int last_end = temp[result_count * 2 + 1];
        
        if (current_start <= last_end) {
            // Объединяем интервалы
            if (current_end > last_end) {
                temp[result_count * 2 + 1] = current_end;
            }
        } else {
            // Новый интервал
            result_count++;
            temp[result_count * 2] = current_start;
            temp[result_count * 2 + 1] = current_end;
        }
    }
    
    result_count++; // Переводим из индекса в количество
    
    // Копируем результат в массив нужного размера
    int* result = (int*)malloc(result_count * 2 * sizeof(int));
    for (int i = 0; i < result_count * 2; i++) {
        result[i] = temp[i];
    }
    
    free(temp);
    *returnSize = result_count;
    return result;
}
