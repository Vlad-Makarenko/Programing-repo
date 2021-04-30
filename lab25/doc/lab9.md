
# Лабораторна робота №9. Перевантаження операторів

## 1. Вимоги

### 1.1 Розробник
 
- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 30-квітня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
 1. **У базовому класі**, та класі/класах-спадкоємцях перевантажити:
	 * оператор присвоювання;
	 * оператор порівняння ( ``==`` ) ;
	 * оператор введення/виведення;
2. **У класі-списку** перевантажити:
	 * оператор індексування ( ``[]`` ) ;
	 * введення/виведення з акцентом роботи, у тому числі і з файлами.
* При цьому продовжувати використовувати регулярні вирази для валідації введених даних.

 
### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених перевантажень операторів 

### 2.2 Опис логічної структури програми

_Перевантаження:_  `operator=(const Backpack &backpack)`  
перевантажує оператор присвоювання (``=``) для классу ``Backpack``.
_Схема алгоритму перевантаження оператора_ подана на рис. 1.
![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab25/doc/assets/operator=.png?raw=true)

Рисунок 1 --- Схема алгоритму перегрузки оператора `=`

_Перевантаження:_ `operator==(const Backpack& A, const Backpack& B)`. перевантажує оператор порівняння (``==``) для классу ``Backpack``.

_Перевантаження:_  `operator<<(ostream &out ,const Backpack& backpack)` перевантажує оператор виводу (``<<``) для классу ``Backpack``.

_Перевантаження:_  `operator>>(istream &in, Backpack& backpack)`перевантажує оператор вводу (``>>``) для классу ``Backpack``.

_Перевантаження:_  `operator[](const size_t index)`перевантажує оператор індексування (``[]``) для классу-списку ``List``.

_Перевантаження:_  `operator>>(ifstream &in, List& list)`перевантажує оператор читання з файлу (``>>``) для классу-списку ``List``.

_Перевантаження:_  `operator<<(ofstream &out ,const List& list)` перевантажує оператор запису в файл (`<<`) для классу-списку ``List``.





### 2.3 Важливі фрагменти програми

#### Перевантаження оператора порівняння

``` 
bool operator==(const Backpack& A, const Backpack& B){  
  bool result = true;  
  if (A.getlaptop_department() == B.getlaptop_department()  
  && A.getcolor() == B.getcolor()  
  && A.getvolume() == B.getvolume()  
  && A.getpurpose() == B.getpurpose()  
  && A.getfirm().getName() == B.getfirm().getName()  
  && A.getfirm().getCountry() == B.getfirm().getCountry()){  
  result &= true;  
  }else{  
	  result &= false;  
  }  
  return result;  
}
  
```
#### Перевантаження оператора присвоювання 

```
string Backpack::toString() const {  
    stringstream result;  
    result << getlaptop_department() << " " << getcolor() << " " << getvolume() << " " << getpurpose() << " "  
	  << getfirm().getName() << " " << getfirm().getCountry() << endl;  
    return result.str();  
}
```
#### Перевантаження оператора виводу для базового класу
```
ostream & operator<<(ostream &out ,const Backpack& backpack){  
    out.width(17);  
    out << backpack.getlaptop_department();  
    out.width(15);  
    out << backpack.getcolor();  
    out.width(17);  
    out << backpack.getvolume();  
    out.width(18);  
    out << backpack.getpurpose();  
    out.width(15);  
    out << backpack.getfirm().getName();  
    out.width(18);  
    out << backpack.getfirm().getCountry() << endl;  
    return out;  
}
```
#### Перевантаження оператора вводу для базового класу
```
istream & operator>>(istream &in, Backpack& backpack){  
   int LD;  
    int volume;  
    string color;  
    int aim;  
    string name;  
    string country;  
    cout << "Enter the data in this order: PlaceFofLaptop Color Volume Aim Name Country\n";  
    in >> LD;  
    in >> color;  
    in >> volume;  
    in >> aim;  
    in >> name;  
    in >> country;  
    stringstream buffer;  
    buffer << LD << " " << color << " " << volume << " " << aim << " " << name << " " << country;  
    regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,3} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]*");  
    if(regex_match(buffer.str(), reg)) {  
	    backpack.setlaptop_department(LD);  
        backpack.setcolor(color);  
        backpack.setvolume(volume);  
        switch (aim) {  
		    case 0:  
                backpack.setpurpose(URBAN);  
                break;  
            case 1:  
                backpack.setpurpose(TACTICAL);  
                break;  
            case 2:  
                backpack.setpurpose(TOURIST);  
                break;  
            default:  
                break;  
        }  
    Firm firm(name, country);  
        backpack.setfirm(&firm);  
        return in;  
    }else {  
	    cout << "ERROR: invalid text" << endl;  
        in.clear();  
        return in;  
    }  
}
```
#### Перевантаження оператора індексування для класа-списка 
```
Backpack& List::operator[](const size_t index) const{  
  if (index < Count){  
  return *backpacks[index];  
    } else{  
  return nullptr;  
    }  
}
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація  роботи перегрузки методу вводу базового класу

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab25/doc/assets/Screenshot_2.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Демонстрація  роботи перегрузки методу виводу класу-списка 

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab25/doc/assets/Screenshot_1.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Демонстрація відсутності витоків пам'яті.

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab25/doc/assets/valgrind.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3


### Структура проекту

	├── lab25
	    ├── doc
	        ├── lab9.md
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

Ми навчились перевантажувати оператори для роботи з классами.

