#ifndef LAB23_LIST_HPP
#define LAB23_LIST_HPP

#include "Backpack.h"

template <typename Type>
class List{
    Type *elements[ARRAY_SIZE];
    int index = 0;
public:
    List() {}


    virtual ~List() = default; // {
//        while (index >= 0){
//            delete elements[index];
//            index--;
//        }
//    }

    void addElement( Type * element ){
        //index += 1;
        if (index >= 255) {
            return;
        }
        elements[index] = element;
        index += 1;
    }


    Type& getElement (int index) const {
        if (index < 0) {
            index = 0;
        }
        if (index >= this->index) {
            index = this->index - 1;
        }

        return *elements[index];
    }

    void deleteElement(int index){
        if (index < 0) {
            index = 0;
        }
        if (index >= this->index) {
            index = this->index - 1;
        }
        for (int i = index; i < this->index; ++i) {
            elements[i] = elements[i+1];
        }
        this->index--;
    }

    Type& FindMinElement(){
        this->SortList();
        return *elements[0];
    }

    int FindIndexElement(Type &element){
        int result = -1;
        for (int i = 0; i < index; ++i) {
            if (*elements[i] == element){
                result = i;
            }
        }
        return result;
    };

    void ShowList() const{
        for (int i = 0; i < this->index; ++i) {
            cout << *elements[i] << endl;
        }
    }

    void SortList(){
        for(int i = 0; i < index; i++){
            for(int j = 0; j < index - 1; j++){
                if (*elements[j] > *elements[j + 1]){
                    Type temp = *elements[j];
                    *elements[j] = *elements[j +1];
                    *elements[j +1] = temp;
                }
            }
        }
    }

};


#endif //LAB23_LIST_HPP
