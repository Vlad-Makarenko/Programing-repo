//
// Created by Vlad on 05.05.2021.
//

#ifndef LAB28_TASK_H
#define LAB28_TASK_H


#include "Menu.h"




class Task {
    string fileName;
    int TaskNumber;
    int Count;
    int* sizes;
    int** arrays;
    int ResultSize;
    int *result;
public:
    Task();
    ~Task();
    void Run();
    void ReadFileName();
    void ReadFromFile();
    void WriteToFile();
    int getSize(int arrIndex);
    int getElem(int arrIndex, int index);
    void setSize(int arrIndex, int val);
    void setElem(int arrIndex, int index, int val);
    void CallingSelectedFunction(int number);
    int* SumArrays(int index1, int index2);
    int* MultiplyArrays(int index1, int index2);
    int* CalcAverage();
    int* FindMaxElem();
    int* FindMinElem();
    int* FindPositiveNumber();
    int* SearchInRange(int range1, int range2);
    int* FindNegativeNumber();
    int* FindMaxElemPos();
    int* FindCountMaxElem();
    void ForTest(int number);
};



#endif //LAB28_TASK_H
