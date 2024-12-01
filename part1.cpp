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
    int sm = 0;
    for(int i = 0; i < size; i++) {
        auto start = high_resolution_clock::now();
        lst.push_back(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        sm += duration.count();
    }

    
    cout << "List - Добавление в конец: " << (double)sm / size << " мкс\n";

    sm = 0;
    for(int i = 0; i < size; i++) {
        auto start = high_resolution_clock::now();
        deq.push_back(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        sm += duration.count();
    }
    cout << "Deque - Добавление в конец: " << (double)sm / size << " мкс\n\n";

    // 2. Поиск элементов
    int searchValue = size / 2;

    auto start = high_resolution_clock::now();
    auto it_list = find(lst.begin(), lst.end(), searchValue);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "List - Поиск элемента: " << duration.count() << " мкс\n";

    start = high_resolution_clock::now();
    auto it_deque = find(deq.begin(), deq.end(), searchValue);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Deque - Поиск элемента: " << duration.count() << " мкс\n\n";

    // 3. Удаление элементов из начала
    sm = 0;
    for(int i = 0; i < size; i++) {
        auto start = high_resolution_clock::now();
        lst.pop_front();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        sm += duration.count();
    }
    cout << "List - Удаление с начала: " << (double)sm / size << " мкс\n";

    sm = 0;
    for(int i = 0; i < size; i++) {
        auto start = high_resolution_clock::now();
        deq.pop_front();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        sm += duration.count();
    }
    cout << "Deque - Удаление с начала: " << (double)sm / size << " мкс\n";
    cout << "----------------------------------------\n\n";
}

int main() {
    vector<int> sizes = {10000, 100000};
    
    for(int size : sizes) {
        testContainers(size);
    }

    return 0;
}