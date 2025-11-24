---
Category: "Array"
Name: "Basic Int Array"
Basement: "Array"
CStructName: ["IA", "IntArray"]
---

# Basic Int Array

## Definition

```c
typedef struct {
    int* body;              // 数组数据指针 (实际存储空间)
    unsigned int capacity;  // 数组的最大容量
} int_array;
```

## 1 立刻上手

使用
```c 
IA int_array_create(unsigned int capacity);
void int_array_destroy(IA arr);
```

这两个 API 来生成和销毁数组。

使用 `void int_array_print(const IA arr);` 打印数组；
使用 `unsigned int int_array_capacity(const IA arr);` 查看数组长度；

## 2 更多妙妙工具

用随机数填充数组
```c
void int_array_fill_random(IA arr);
void int_array_fill_random_with_bound(IA arr, unsigned int bound);
```

获取一个数组的切片（需要手动销毁！）
```c
IA int_array_slice(IA arr, unsigned int start, unsigned int end);
```


打乱数组
```c
void int_array_shuffle(IA arr);
```


打乱数组，查看数组是否按照某种顺序排列：
```c
bool int_array_is_ordered_asc(IA arr);
bool int_array_is_ordered_desc(IA arr);
void int_array_reverse(IA arr);
```
