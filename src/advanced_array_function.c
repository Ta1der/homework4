#include "../include/advanced_array_function.h"

int max_subarray_sum(int* nums, int size) {
    if (size == 0) return 0;
    
    int max_sum = nums[0];
    int current_sum = nums[0];
    
    for (int i = 1; i < size; i++) {
        // Выбираем максимум между текущим элементом и суммой предыдущих + текущий
        if (current_sum + nums[i] > nums[i]) {
            current_sum = current_sum + nums[i];
        } else {
            current_sum = nums[i];
        }
        
        // Обновляем общий максимум
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return max_sum;
}

// 2. Длина самой длинной непрерывной строго возрастающей подпоследовательности
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

// Вспомогательная функция для сравнения интервалов (для сортировки)
int compare_intervals(const void* a, const void* b) {
    const int* interval1 = (const int*)a;
    const int* interval2 = (const int*)b;
    return interval1[0] - interval2[0];
}

// 3. Объединение интервалов
int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Сортируем интервалы по начальной точке
    qsort(intervals, intervalsSize, 2 * sizeof(int), compare_intervals);
    
    // Временный массив для хранения результата
    int* temp_result = (int*)malloc(intervalsSize * 2 * sizeof(int));
    int result_count = 0;
    
    // Добавляем первый интервал
    temp_result[0] = intervals[0];
    temp_result[1] = intervals[1];
    
    // Объединяем интервалы
    for (int i = 1; i < intervalsSize; i++) {
        int current_start = intervals[i * 2];
        int current_end = intervals[i * 2 + 1];
        int* last_interval = &temp_result[result_count * 2];
        
        if (current_start <= last_interval[1]) {
            // Интервалы пересекаются - объединяем
            if (current_end > last_interval[1]) {
                last_interval[1] = current_end;
            }
        } else {
            // Не пересекаются - добавляем новый интервал
            result_count++;
            temp_result[result_count * 2] = current_start;
            temp_result[result_count * 2 + 1] = current_end;
        }
    }
    
    result_count++; // Переводим из индекса в количество
    
    // Копируем результат в массив нужного размера
    int* result = (int*)malloc(result_count * 2 * sizeof(int));
    for (int i = 0; i < result_count * 2; i++) {
        result[i] = temp_result[i];
    }
    
    free(temp_result);
    *returnSize = result_count;
    return result;
}
