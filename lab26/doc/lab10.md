
# Лабораторна робота №10. Спадкування

## 1. Вимоги

### 1.1 Розробник
 
- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 03-травня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
	 1. **Додати** класи-спадкоємці, котрі будуть поширювати функціонал базового класу відповідно до індивідуального завдання;

	2. **Додати** клас-список для кожного класу-спадкоємця, який буде керувати лише елементами стосовно класа-спадкоємця.

 
### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів

### 2.2 Опис логічної структури програми
Загальне завдання виконується за допомогою наступних методів:
`FindGermanVelourBackpack`,  `FindSuedeNoLiningBackpack`,  `FindBlueMaxVolumeBackpack`.

_Метод:_  `FindGermanVelourBackpack`: Виконує завдання 1 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку для спадкоємця 1 знаходимо німецький міський рюкзак з велюру.
_Схема алгоритму метода `FindGermanVelourBackpack`_ подана на рис. 1.
![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab26/doc/assets/FindGermanVelourBackpack.png?raw=true)

Рисунок 1 --- Схема алгоритму метода`FindGermanVelourBackpack`

_Метод_ `FindSuedeNoLiningBackpack` Виконує завдання 2 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку для спадкоємця 1 знаходимо замшевий рюкзак без підкладки.

_Метод_   `FindBlueMaxVolumeBackpack`Виконує завдання 3 з "методи для роботи з колекцією"; За допомогою даного методу в класах-списках для спадкоємців 1 та 2 знаходимо синій рюкзак з найбільшим об'ємом.



### 2.3 Важливі фрагменти програми

#### Метод пошуку німецького міського рюкзака з велюру

``` 
LeatherBackpack& LeatherBackpackList::FindGermanVelourBackpack(){  
    LeatherBackpack *temp = new LeatherBackpack;  
    bool flag = true;  
    for (int i = 0; i < Count; ++i) {  
	    if ( getLeatherBackpack(i).getLeather() == VELOUR  
		    && getLeatherBackpack(i).getfirm().getCountry() == "Germany"  
		    && getLeatherBackpack(i).getpurpose() == URBAN){  
			    temp = &getLeatherBackpack(i);  
	            temp->Print();  
	            flag = false;  
        }  
   }  
   if (flag){  
	   cout << "ERROR: Nothing found";  
   }  
   return *temp;  
}
  
```
#### Метод пошуку замшевого рюкзака без підкладки

```
LeatherBackpack&  LeatherBackpackList::FindSuedeNoLiningBackpack(){  
    LeatherBackpack *temp = new LeatherBackpack;  
    bool flag = true;  
    for (int i = 0; i < Count; ++i) {  
		  if ( getLeatherBackpack(i).getLeather() == SUEDE  
		  && getLeatherBackpack(i).getlining() == false){  
			  temp = &getLeatherBackpack(i);  
              temp->Print();  
              flag = false;  
          }  
	}  
	if (flag){  
        cout << "ERROR: Nothing found";  
    }  
    return *temp;  
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація  роботи методів пошуку

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab26/doc/assets/Screenshot_2.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Результат виконання всієї програми

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab26/doc/assets/Screenshot_1.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Демонстрація відсутності витоків пам'яті.

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab26/doc/assets/valgrind.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3


### Структура проекту

	├── lab26
	    ├── doc
	        ├── lab10.md
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

Ми навчились працювати з класами-спадкоємцями та списками для них

