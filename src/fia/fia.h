#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>


struct int_array {
    int* body;              // 数组数据指针
    unsigned int capacity;  // 数组的最大容量
};

typedef struct int_array* IntArray;
typedef IntArray IA;

// =========================================================
// I. 构造与析构
// =========================================================

/**
 * @brief 创建一个指定容量的 int_array
 * * @param capacity 数组的初始最大容量。
 * @return int_array 初始化后的数组结构体。
 */
IA int_array_create(unsigned int capacity);

/**
 * @brief 释放 int_array 内部数据内存并安全归零结构体。
 * * @param arr 指向待销毁的数组结构体的指针。
 */
void int_array_destroy(IA arr);

// =========================================================
// II. 访问与修改
// =========================================================

/**
 * @brief 安全地获取数组指定索引处的值。
 * * @param arr 待操作的数组。
 * @param index 待访问的索引。
 * @return int 索引位置的值。
 */
int int_array_get(const IA arr, unsigned int index);

/**
 * @brief 安全地设置数组指定索引处的值。
 * * @param arr 待操作的数组。
 * @param index 待写入的索引。
 * @param value 要写入的新值。
 */
void int_array_set(IA arr, unsigned int index, int value);

// =========================================================
// III. 查询
// =========================================================

/**
 * @brief 获取数组的最大容量。
 * * @param arr 待查询的数组。
 * @return unsigned int 数组的容量。
 */
unsigned int int_array_capacity(const IA arr);

// =========================================================
// IV. 工具与测试
// =========================================================

/**
 * @brief 打印数组内容到标准输出。
 */
void int_array_print(const IA arr);

/**
 * @brief 使用随机整数填充数组的整个容量。
 */
void int_array_fill_random(IA arr);


/**
 * @brief 使用随机整数填充数组的整个容量。
 * @param bound 随机数的取值范围（0，bound）
 */
void int_array_fill_random_with_bound(IA arr, unsigned int bound);



IA int_array_slice(IA arr, unsigned int start, unsigned int end);



/**
 * @brief 反转一个数组.
 */
void int_array_reverse(IA arr);



/**
 * @brief 打乱数组.
 */
void int_array_shuffle(IA arr);

bool int_array_is_ordered_asc(IA arr);

bool int_array_is_ordered_desc(IA arr);
#endif // INT_ARRAY_H
