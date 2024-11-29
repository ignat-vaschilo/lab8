#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
using namespace std;

struct Worker {
    string name;
    string dateStart;
    string dateEnd;
    string post;
    int salary;
};

void stringToWorker(string& str, Worker& worker) {
    stringstream ss(str);
    ss >> worker.name >> worker.dateStart >> worker.dateEnd >> worker.post >> worker.salary;
}

void printWorkers(list<Worker>& workers) {
    for (auto& worker : workers) {
        cout << worker.name << " " 
             << worker.dateStart << " "
             << worker.dateEnd << " "
             << worker.post << " "
             << worker.salary << endl;
    }
}

bool sortForSalary(Worker& worker1, Worker& worker2) {
    return worker1.salary < worker2.salary;
}

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);

    list<Worker> workers;
    string line;
    while (getline(file, line)) {
        Worker new_worker;
        stringToWorker(line, new_worker);
        workers.push_back(new_worker);
    }
    printWorkers(workers);
    cout << "--------------------------------------------------------------------" << endl;

    workers.sort(sortForSalary);
    printWorkers(workers);
    file.close();
}