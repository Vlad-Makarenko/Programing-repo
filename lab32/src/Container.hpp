//
// Created by Vlad on 20.04.2021.
//

#ifndef LAB23_CONTAINER_H
#define LAB23_CONTAINER_H

#include "Backpack.h"



template<typename T>
class List{
    vector<T*> backpacks;
public:
    List() = default;
    List(List &copy) = default;

    virtual ~List(){
        while (!backpacks.empty()){
            backpacks.pop_back();
        }
        backpacks.clear();
        backpacks.shrink_to_fit();
    }


    typedef typename std::vector<T*>::iterator iterator;

    iterator begin(){
        return backpacks.begin();
    }

    iterator end(){
        return backpacks.end();
    }


    void addItem( T* item){
        this->backpacks.push_back(item);
    }

    vector<T*> getBackpack (){
        return this->backpacks;
    }

    void ShowAll(){
        for(T &o : backpacks){
            cout << o.get() << endl;
        }
    }


};

#endif //LAB23_CONTAINER_H
