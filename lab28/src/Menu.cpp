//
// Created by Vlad on 05.05.2021.
//
#include "Menu.h"
#include "Task.h"

int Menu(){
    int action;

    cout << endl << "Select an action:" << endl;
    cout << "1. Determine the sum of two arrays;\n"
            "2. Multiply two arrays;\n"
            "3. Calculate the average value of the elements of the array;\n"
            "4. Find the element in the array with the maximum value;\n"
            "5. Find an element in the array with a minimum value;\n"
            "6. Determine the number of positive elements in the array;\n"
            "7. Determine the number of elements that belong to the range [a, b];\n"
            "8. Determine the number of negative elements in the array;\n"
            "9. Find in the array the number of the first element with the maximum value;\n"
            "10. Find the number of elements with the maximum value in the array." << endl;
    cout << endl << " > Your choice: ";
    cin >> action;
    if(action > 10 || action < 1){
        throw out_of_range("Out of range exception");
    } else{
        return action;
    }
}

void Task::CallingSelectedFunction(int number){
    int i1, i2;
    switch (number) {
        case 1:
            cout << " > Enter Input Indexes of Arrays: ";
            cin >> i1 >> i2;
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func(A + B)" << endl;
            result = SumArrays(i1, i2);
            break;
        case 2:
            cout << " > Enter Input Indexes of Arrays: ";
            cin >> i1 >> i2;
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func(A * B)" << endl;
            result = MultiplyArrays(i1, i2);
            break;
        case 3:
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func calc average" << endl;
            result = CalcAverage();
            break;
        case 4:
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func find max elem" << endl;
            result = FindMaxElem();
            break;
        case 5:
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func find min elem" << endl;
            result = FindMinElem();
            break;
        case 6:
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func find positive elem" << endl;
            result = FindPositiveNumber();
            break;
        case 7:
            cout << " > Enter range: ";
            cin >> i1 >> i2;
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func find count element in range" << endl;
            result = SearchInRange(i1, i2);
            break;
        case 8:
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func find negative elem" << endl;
            result = FindNegativeNumber();
            break;
        case 9:
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func find pos max elem" << endl;
            result = FindMaxElemPos();
            break;
        case 10:
            if (result != nullptr){
                delete[] result;
            }
            cout << " > Calling func find count max elem" << endl;
            result = FindCountMaxElem();
            break;
        default:
            break;
    }
}

