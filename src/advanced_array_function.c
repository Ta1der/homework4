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

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int** temp_result = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        temp_result[i] = (int*)malloc(2 * sizeof(int));
    }
    int** intervals_2d = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        intervals_2d[i] = &intervals[i * 2];
    }
    
    qsort(intervals_2d, intervalsSize, sizeof(int*), compare_intervals);

    int result_count = 0;
    temp_result[0][0] = intervals_2d[0][0];
    temp_result[0][1] = intervals_2d[0][1];
    
    for (int i = 1; i < intervalsSize; i++) {
        int* current = intervals_2d[i];
        int* last_merged = temp_result[result_count];
        
        if (current[0] <= last_merged[1]) {
            // Интервалы пересекаются - объединяем
            if (current[1] > last_merged[1]) {
                last_merged[1] = current[1];
            }
        } else {
            // Не пересекаются - добавляем новый интервал
            result_count++;
            temp_result[result_count][0] = current[0];
            temp_result[result_count][1] = current[1];
        }
    }
    
    result_count++; 
    int* result = (int*)malloc(result_count * 2 * sizeof(int));
    for (int i = 0; i < result_count; i++) {
        result[i * 2] = temp_result[i][0];
        result[i * 2 + 1] = temp_result[i][1];
    }

    for (int i = 0; i < intervalsSize; i++) {
        free(temp_result[i]);
    }
    free(temp_result);
    free(intervals_2d);
    
    *returnSize = result_count * 2;
    return result;
}

