#include <iostream>
#include <list>
#include <deque>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void testContainers(int size) {
    list<int> lst;
    deque<int> deq;
    
    cout << "Тестирование для " << size << " элементов:\n";
    cout << "----------------------------------------\n";

    // 1. Добавляем элементы в конец
    auto start = high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        lst.push_back(i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "List - Добавление в конец: " << duration.count() << " мкс\n";

    start = high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        deq.push_back(i);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Deque - Добавление в конец: " << duration.count() << " мкс\n\n";

    // 2. Поиск элементов
    int searchValue = size / 2;

    start = high_resolution_clock::now();
    auto it_list = find(lst.begin(), lst.end(), searchValue);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "List - Поиск элемента: " << duration.count() << " мкс\n";

    start = high_resolution_clock::now();
    auto it_deque = find(deq.begin(), deq.end(), searchValue);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Deque - Поиск элемента: " << duration.count() << " мкс\n\n";

    // 3. Удаление элементов из начала
    start = high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        lst.pop_front();
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "List - Удаление с начала: " << duration.count() << " мкс\n";

    start = high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        deq.pop_front();
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Deque - Удаление с начала: " << duration.count() << " мкс\n";
    cout << "----------------------------------------\n\n";
}

int main() {
    vector<int> sizes = {1000, 10000, 100000};
    
    for(int size : sizes) {
        testContainers(size);
    }

    return 0;
}