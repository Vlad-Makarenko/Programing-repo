
# Лабораторна робота №14. STL. Вступ до Стандартної бібліотеки шаблонів(частина 1)

## 1. Вимоги

### 1.1 Розробник
 
- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 20-травня-2021

### 1.2 Загальне завдання

 * **Поширити**, лабораторну роботу №27 таким чином:
	 1. **Замінити** масив та CRUD методи роботи з ним на використання STL;

	2. **Оновити** всі методи роботи з колекцією на використання STL;
	
	3.  **Додати** функцію сортування колекції з використанням функтора.
	4.  **Додати** функцію об'єднання двох класів-списків.
* Додати можливість об'єднання двох STL-контейнерів типу map.

 
### 1.3 Індивідуальне завдання

Виконати завдання, згідно варіанту

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів

### 2.2 Опис логічної структури програми
Загальне завдання виконується за допомогою наступних методів:
`FindGermanVelourBackpack`,  `FindSuedeNoLiningBackpack`,  `FindBlueMaxVolumeBackpack`, `SortByVolume`,  `InsertList`, `ExcellentTask`.

_Метод:_  `FindGermanVelourBackpack`: Виконує завдання 1 з "методи для роботи з колекцією"; За допомогою STL-функції `find_if` предиката `PredG` в класі-списку  знаходимо німецький міський рюкзак з велюру.
_Схема алгоритму метода `FindGermanVelourBackpack`_ подана на рис. 1.
![Блок-схема](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab30/doc/assets/FindGermanVelourBackpack.png?raw=true)

Рисунок 1 --- Схема алгоритму метода`FindGermanVelourBackpack`

_Метод_ `FindSuedeNoLiningBackpack` Виконує завдання 2 з "методи для роботи з колекцією"; За допомогою STL-функції `find_if` предиката `PredS` в класі-списку знаходимо замшевий рюкзак без підкладки.

_Метод_   `FindBlueMaxVolumeBackpack`Виконує завдання 3 з "методи для роботи з колекцією"; За допомогою STL-функції `find_if` предиката `PredM`в класі-списку знаходимо синій рюкзак з найбільшим об'ємом.

_Метод_ `SortByVolume` Виконує сортування за допомогою STL-функції `sort` та розробленого функтора `functor`.

_Метод_ `InsertList` Виконує об'єднання двох класів-списків за допомогою STL-функції `Insert`.

_Метод_ `ExcellentTask` Виконує об'єднання двох STL-контейнерів тип map.


### 2.3 Важливі фрагменти програми

#### Метод пошуку німецького міського рюкзака з велюру

``` 
vector<LeatherBackpack*> List::FindGermanVelourBackpack(){  
    vector<LeatherBackpack*> res;  
    bool flag = true;  
    auto iter = backpacks.begin();  
    while (true) {  
    iter = std::find_if(iter, this->backpacks.end(), predG);  
        if(*iter == NULL){  
		    break;  
        }  
	    flag = false;  
        res.push_back((LeatherBackpack*)*iter);  
        ((LeatherBackpack*)*iter)->Print();  
        cout << endl;  
        iter++;  
    }  
    if (flag){  
	    cout << "ERROR: Nothing found" << endl;  
    }  
    return res;  
}
  
```
#### Метод пошуку замшевого рюкзака без підкладки

```
vector<LeatherBackpack*>  List::FindSuedeNoLiningBackpack(){  
    vector<LeatherBackpack*> res;  
    bool flag = true;  
    auto iter = backpacks.begin();  
    while (*iter) {  
    iter = std::find_if(iter, this->backpacks.end(), predS);  
        if(*iter == NULL){  
		    break;  
        }  
        flag = false;  
        ((LeatherBackpack*)*iter)->Print();  
        cout << endl;  
        res.push_back((LeatherBackpack*)*iter);  
        iter++;  
    }  
    if (flag){  
	    cout << "ERROR: Nothing found" << endl;  
    }  
    return res;  
}
```
#### Метод пошуку синього рюкзака з найбільшим об'ємом

```
Backpack*  List::FindBlueMaxVolumeBackpack(){  
    vector<Backpack*> temp;  
    temp.reserve(this->backpacks.size());  
    std::copy(this->backpacks.begin(), this->backpacks.end(), std::back_inserter(temp));  
    std::sort(temp.begin(), temp.end(), functorF);  
    auto iter = temp.begin();  
    iter = std::find_if(iter, temp.end(), predM);  
    if(*iter == NULL){  
		  cout << "ERROR: Nothing found" << endl;  
    }  
	if ( ((Backpack*)*iter)->GetType() == 'L' ){  
	    PrintForm1();  
        cout << endl;  
        ((LeatherBackpack*)*iter)->Print();  
        cout << endl;  
    } else{  
	    PrintForm2();  
        cout << endl;  
        ((FabricBackpack*)*iter)->Print();  
        cout << endl;  
    }  
    return ((Backpack*)*iter)->clone();  
}
```
#### Метод об'єднання двох класів-списків
```
void List::InsertList(List &in) {  
    this->backpacks.reserve(this->index + in.index);  
    auto iter = this->backpacks.end();  
    for (int i = 0; i < in.index; ++i) {  
	    this->backpacks.insert(iter + i, in.backpacks[i]);  
    }  
    this->index += in.index;  
}
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація роботи методу сортування

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab30/doc/assets/Screenshot_4.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (рис.3 ). Демонстрація  роботи методів пошуку

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab30/doc/assets/Screenshot_1.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Результат виконання методу об'єднання двох класів-списків

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab30/doc/assets/Screenshot_2.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3

_Крок 4_ (див. рис.5 ). Демонстрація  об'єднання двох STL-контейнерів тип map

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab30/doc/assets/Screenshot_3.png?raw=true)
Рисунок 5 --- Результат виконання кроку 4

_Крок 5_ (див. рис.6 ). Демонстрація відсутності витоків пам'яті.
![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab27/doc/assets/valgrind.png?raw=true)
Рисунок 6 --- Результат виконання кроку 5



### Структура проекту

	├── lab30
	    ├── doc
	        ├── lab14.md
	        └── assets
        ├── CMakelist.txt
		├── test
            ├── test.cpp
		└── src
		    ├── main.cpp
		    ├── Container.cpp
            ├── Container.h
		    ├── Backpack.cpp
		    └── Backpack.h
## Висновки

Ми навчилися працювати зі стандартною бібліотекою шаблонів, з STL-контейнерами  та їх методами і функціями.

