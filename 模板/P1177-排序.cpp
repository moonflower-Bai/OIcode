#include <bits/stdc++.h>
template<typename T>
void bubble_sort(std::unique_ptr<T[]>& array, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(array[j] > array[j + 1]){
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template<typename T>
void select_sort(std::unique_ptr<T[]>& array, int length){
    #define optimize

    #pragma region 无优化
    #ifndef optimize
    for(int i = 0; i < length; i++){
        int mx = 0;
        for(int j = 0; j < length - i; j++){
            if(array[mx] < array[j]){
                mx = j;
            }
        }
        std::swap(array[mx], array[length - 1 - i]);
    }
    #endif
    #pragma endregion

    #pragma region 比较次数优化
    #ifdef optimize
    bool sorted = false;
    for(int i = 0; i < length; i++){
        int mx = 0;
        sorted = true;
        for(int j = 0; j < length - i; j++){
            if(array[mx] <= array[j]){
                mx = j;
            }
            else{
                sorted = false;
            }
        }
        std::swap(array[mx], array[length - 1 - i]);
    }
    #endif
    #pragma endregion
}

template<typename T>
void insert_sort(std::unique_ptr<T[]>& array, int length){
    for(int i = 1; i < length; i++){
        int pos = array[i];
        int l = 0, r = i;
        while(l < r){
            int mid = (l + r) >> 1;
            if(array[mid] >= pos){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        for(int j = i; j > l; j--){
            array[j] = array[j - 1];
        }
        array[l] = pos;
    }
}

template <typename T>
void count_sort(std::unique_ptr<T[]>& array, int length){
    auto rnk = std::make_unique<T[]>(length + 1);
    for(int i = 0; i < length; i++){
        for(int j = 0; j < i; j++){
            if(array[i] > array[j]){
                rnk[i]++;
            }
            else if(array[i] < array[j]){
                rnk[j]++;
            }
        }
    }

    #define optmize

    #pragma region 未优化
    #ifndef optmize
    auto temp = std::make_unique<T[]>(length + 1);
    for(int i = 0; i < length; i++){
        temp[rnk[i]] = array[i];
    }
    memcpy(array.get(), temp.get(), sizeof(int) * length);
    #endif
    #pragma endregion

    #pragma region 优化存储空间
    #ifdef optmize
    for(int i = 0; i < length; i++){
        while(i != rnk[i]){
            int num = rnk[i];
            std::swap(array[i], array[num]);
            std::swap(rnk[num], rnk[i]);
        }
    }
    #endif
    #pragma endregion
}
template<typename T>
std::string print_array(std::unique_ptr<T[]>& array, int length){
    std::ostringstream oss;
    oss << '[';
    for(int i = 0; i < length; i++){
        oss << array[i];
        if(i < length - 1){
            oss << ',';
        }
    }
    oss << ']';
    return oss.str();
}
int main(){
    std::cout << "input length of array: ";
    std::random_device rd;
    std::mt19937 rnd(rd());
    std::uniform_int_distribution<int> dis(-1000, 1000);
    int n;
    std::cin >> n;
    auto array = std::make_unique<int[]>(n);
    for(int i = 0; i < n; i++){
        array[i] = dis(rnd);
    }
    std::cout << "origin array: " << print_array(array, n) << std::endl;
    auto temp = std::make_unique<int[]>(n);

    memcpy(temp.get(), array.get(), sizeof(int) * n);
    bubble_sort(temp, n);
    std::cout << "bubble sort:  " << print_array(temp, n) << std::endl;

    memcpy(temp.get(), array.get(), sizeof(int) * n);
    insert_sort(temp, n);
    std::cout << "insert sort:  " << print_array(temp, n) << std::endl;

    memcpy(temp.get(), array.get(), sizeof(int) * n);
    count_sort(temp, n);
    std::cout << "count sort:   " << print_array(temp, n) << std::endl;

    memcpy(temp.get(), array.get(), sizeof(int) * n);
    select_sort(temp, n);
    std::cout << "select sort:  " << print_array(temp, n) << std::endl;

    return 0;
}