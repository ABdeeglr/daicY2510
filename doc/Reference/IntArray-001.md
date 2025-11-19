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


## API


### I. 构造与析构 (Creation & Destruction)

| API 名称 | 描述 | 参数 | 返回值 | 错误处理 (Error Handling) |
| :--- | :--- | :--- | :--- | :--- |
| `int_array_create` | 分配内存并初始化一个指定容量的 `int_array` 结构体。 | `capacity` (`unsigned int`): 数组的初始最大容量。 | `int_array`: 初始化后的数组结构体。 | 如果内存分配失败 (`malloc` 失败)，应返回一个 `capacity` 为 `0` 且 `body` 为 `NULL` 的无效结构体。 |
| `int_array_destroy` | 释放 `int_array` 内部数据指针 (`body`) 所占用的内存，并将结构体成员安全归零。 | `arr` (`int_array *`): 指向待销毁的数组结构体的指针。 | `void` | 无。 |

### II. 访问与修改 (Access & Modification)

| API 名称 | 描述 | 参数 | 返回值 | 错误处理 (Error Handling) |
| :--- | :--- | :--- | :--- | :--- |
| `int_array_get` | 安全地获取数组指定索引处的值。 | `arr` (`const int_array *`): 待操作的数组。<br>`index` (`unsigned int`): 待访问的索引。 | `int`: 索引位置的值。 | 如果 `index` 越界 ( $\ge arr->capacity$ )，应触发断言 (`assert`) 或退出程序。 |
| `int_array_set` | 安全地设置数组指定索引处的值。 | `arr` (`int_array *`): 待操作的数组。<br>`index` (`unsigned int`): 待写入的索引。<br>`value` (`int`): 要写入的新值。 | `void` | 如果 `index` 越界 ( $\ge arr->capacity$ )，应触发断言 (`assert`) 或退出程序。 |

### III. 查询 (Query)

| API 名称 | 描述 | 参数 | 返回值 | 错误处理 (Error Handling) |
| :--- | :--- | :--- | :--- | :--- |
| `int_array_capacity` | 获取数组的最大容量。 | `arr` (`const int_array *`): 待查询的数组。 | `unsigned int`: 数组的容量。 | 无。 |

### IV. 工具与测试 (Utilities & Testing)

| API 名称 | 描述 | 参数 | 返回值 | 错误处理 (Error Handling) |
| :--- | :--- | :--- | :--- | :--- |
| `int_array_print` | 将数组内容打印到标准输出，用于调试。格式示例：`[10, 20, 30, ...]` | `arr` (`const int_array *`): 待打印的数组。 | `void` | 无。 |
| `int_array_fill_random` | 使用随机整数填充数组的整个容量。 | `arr` (`int_array *`): 待填充的数组。 | `void` | 无。 |

