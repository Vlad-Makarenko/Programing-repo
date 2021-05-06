//
// Created by Vlad on 05.05.2021.
//

#include "Task.h"


Task::Task() : fileName(), TaskNumber(0), Count(0), sizes(nullptr), arrays(nullptr), ResultSize(0), result(nullptr) {}

Task::~Task() {
    if (arrays)
        for (int i = 0; i < Count; i++)
            delete[] arrays[i];
    delete[] arrays;
    delete[] sizes;
    delete[] result;
}

void Task::Run() {
    for (;;) {
        try {
            cout << "Enter Input FileName: ";
            ReadFileName();
            if (fileName == "\\exit") // \\exit => "\exit"
                return;
            cout << "Reading... " <<endl;
            ReadFromFile();
            TaskNumber = Menu();
            CallingSelectedFunction(TaskNumber);
            cout << endl << "Enter Output FileName: ";
            ReadFileName();
            if (fileName == "\\exit")
                return;
            cout << "Writing... " << endl;
            WriteToFile();
        }
        catch (out_of_range& e) {
            cout << e.what() << endl;
        }
        catch (std::ios_base::failure& e) {
            cout << e.what() << endl;
        }
        catch (std::invalid_argument& e) {
            cout << e.what() << endl;
        }
        cout << endl << "-----------------------------------------" << endl << endl;
        //system("pause&cls");
    }
}

void Task::ReadFileName() {
    cin >> fileName;
}

void Task::ReadFromFile() {
    ifstream fin;
    fin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fin.open(fileName, std::ios_base::in);
    fin >> Count;
    if (Count < 0) {
        throw std::invalid_argument("Bad Argument");
    }
    sizes = new int[Count];
    arrays = new int*[Count];
    for (int i = 0; i < Count; i++) {
        int val_size;
        fin >> val_size;
        setSize(i, val_size);
        arrays[i] = new int[getSize(i)];
        for (int j = 0; j < getSize(i); j++)
        {
            int val;
            fin >> val;
            setElem(i, j, val);
        }
    }
    fin.close();
}

void Task:: WriteToFile() {
    ofstream fout;
    fout.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fout.open(fileName, std::ios_base::out);
    for (int i = 0; i < ResultSize; i++){
        fout << result[i] << " ";
    }
    fout.close();
}

int Task:: getSize(int arrIndex) {
    if (arrIndex >= Count || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return sizes[arrIndex];
    }
}
int Task:: getElem(int arrIndex, int index) {
    if (arrIndex >= Count || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return arrays[arrIndex][index];
    }
}
void Task:: setSize(int arrIndex, int val) {
    if (arrIndex >= Count || arrIndex < 0 || val < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        sizes[arrIndex] = val;
    }
}
void Task:: setElem(int arrIndex, int index, int val) {
    if (arrIndex >= Count || arrIndex < 0 ){
        throw out_of_range("Out of range exception:");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        arrays[arrIndex][index] = val;
    }
}

int* Task::SumArrays(int index1, int index2){
    if (getSize(index1) != getSize(index2)) {
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    ResultSize = getSize(index1);
    int *temp_res = new int[ResultSize];
    for (int i = 0; i < ResultSize; i++)
        temp_res[i] = getElem(index1, i) + getElem(index2, i);
    return temp_res;
}

int* Task::MultiplyArrays(int index1, int index2) {
    if (getSize(index1) != getSize(index2)) {
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    ResultSize = getSize(index1);
    int *temp_res = new int[ResultSize];
    for (int i = 0; i < ResultSize; i++)
        temp_res[i] = getElem(index1, i) * getElem(index2, i);
    return temp_res;
}

int* Task::CalcAverage() {
    int *temp_res = new int[Count];
    int sum = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            sum += getElem(i, j);
        }
        temp_res[i] = sum / getSize(i);
        sum = 0;
    }
    return temp_res;
}

int* Task::FindMaxElem(){
    int *temp_res = new int[Count];
    int elem = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}

int* Task::FindMinElem(){
    int *temp_res = new int[Count];
    int elem = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem > getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}

int* Task::FindPositiveNumber() {
    int *temp_res = new int[Count];
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) >= 0){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Task::SearchInRange(int range1, int range2) {
    if(range1 >= range2){
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    int *temp_res = new int[Count];
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) >= range1 && getElem(i, j) <= range2) {
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Task::FindNegativeNumber() {
    int *temp_res = new int[Count];
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) < 0){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Task::FindMaxElemPos(){
    int *temp_res = new int[Count];
    int pos = 0;
    int elem = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
                pos = j;
            }
        }
        temp_res[i] = pos;
    }
    return temp_res;
}

int* Task::FindCountMaxElem() {
    int *temp_res = new int[Count];
    int elem = 0;
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        for (int j = 0; j < getSize(i); ++j) {
            if(elem == getElem(i, j)){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

void Task::ForTest(int number){
    fileName = "test.txt";
    TaskNumber = number;
    ReadFromFile();
    CallingSelectedFunction(TaskNumber);
    fileName = "TestResult.txt";
    WriteToFile();
}
