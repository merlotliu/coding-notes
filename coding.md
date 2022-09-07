# 算法&数据结构

## 时间复杂度

## 选择排序

### 代码

```c++
void selectionSort(vector<int> &arr) {
    // already sorted
    if(arr.size() < 2) {
        return;
    }
    
    for(int i = 0; i < arr.size()-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[minIdx] > arr[j]) {
                minIdx = j
            }
        }
        if(minIdx != i) {
            swap(arr, i, minIdx);
        }
    }
}

void swap(vector<int> &arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
```



## 冒泡排序

## 异或运算

## 插入排序

## 对数器