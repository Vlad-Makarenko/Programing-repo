
# Лабораторна робота №11. Поліморфізм

## 1. Вимоги

### 1.1 Розробник
 
- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 08-травня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
	 1. **Зробити** базовий клас абстрактним, додати абстрактні методи;

	2. **Розроблені** класи-списки поєднуються до одного класу списку таким чином, щоб він міг працювати як з базовим класом, так і з класами-спадкоємцями;
	
	4.  **Обов'язково** використовувати ключові слова ``override`` або ``final``.

 
### 1.3 Індивідуальне завдання

Реалізувати методи 1-3 із розрахункового завдання:
1. **Знайти** німецький міський рюкзак з велюру;
2. **Знайти** замшевий рюкзак без підкладки;
3. **Знайти** рюкзак синього кольору з найбільшим об'ємом.

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів

### 2.2 Опис логічної структури програми
Індивідуальне  завдання виконується за допомогою наступних методів:
`FindGermanVelourBackpack`,  `FindSuedeNoLiningBackpack`,  `FindBlueMaxVolumeBackpack`.

_Метод:_  `FindGermanVelourBackpack`: Виконує завдання 1 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку  знаходимо німецький міський рюкзак з велюру.
_Схема алгоритму метода `FindGermanVelourBackpack`_ подана на рис. 1.
![Блок-схема](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab27/doc/assets/FindGermanVelourBackpack%28%29.png?raw=true)

Рисунок 1 --- Схема алгоритму метода`FindGermanVelourBackpack`

_Метод_ `FindSuedeNoLiningBackpack` Виконує завдання 2 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку знаходимо замшевий рюкзак без підкладки.

_Метод_   `FindBlueMaxVolumeBackpack`Виконує завдання 3 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку знаходимо синій рюкзак з найбільшим об'ємом.



### 2.3 Важливі фрагменти програми

#### Метод пошуку німецького міського рюкзака з велюру

``` 
LeatherBackpack* List::FindGermanVelourBackpack(){  
    LeatherBackpack *temp;// = new LeatherBackpack;  
    bool flag = true;  
    for (int i = 0; i <= index; ++i) {  
	    if (backpacks[i]->GetType() == 'L'){  
		    temp = (LeatherBackpack*)getBackpack(i);  
            if ( temp->getLeather() == VELOUR  
                 && temp->getfirm().getCountry() == "Germany"  
                 && temp->getpurpose() == URBAN){  
				    temp->Print();  
	                cout << endl;  
	                flag = false;  
	                break;  
            }  
	   }  
   }  
   if (flag){  
	    cout << "ERROR: Nothing found" << endl;  
        return nullptr;  
   }  
   return temp;  
}
  
```
#### Метод пошуку замшевого рюкзака без підкладки

```
LeatherBackpack*  List::FindSuedeNoLiningBackpack(){  
    LeatherBackpack *temp;// = new LeatherBackpack;  
    bool flag = true;  
    for (int i = 0; i <= index; ++i) {  
	    if (backpacks[i]->GetType() == 'L'){  
		    temp = (LeatherBackpack*)getBackpack(i);  
            if ( temp->getLeather() == SUEDE && temp->getlining() == false) {  
			    temp->Print();  
                cout << endl;  
                flag = false;  
                break;  
            }  
	    }  
   }  
   if (flag){  
	    cout << "ERROR: Nothing found" << endl;  
        return nullptr;  
   }  
   return temp;  
}
```
#### Метод пошуку синього рюкзака з найбільшим об'ємом

```
Backpack* List::FindBlueMaxVolumeBackpack(){  
    LeatherBackpack *temp1;  
    FabricBackpack *temp2;  
    bool flag1 = false;  
    bool flag2 = false;  
    SortByVolume();  
    for (int i = index; i >= 0; --i) {  
	    if (backpacks[i]->GetType() == 'L') {  
		    temp1 = (LeatherBackpack *) getBackpack(i);  
            if (temp1->getcolor() == "Blue" ){  
			    PrintForm1();  
                cout << endl;  
                temp1->Print();  
                cout << endl;  
                flag1 = true;  
                break;  
            }  
	   }  
	   if (backpacks[i]->GetType() == 'F') {  
		    temp2 = (FabricBackpack *) getBackpack(i);  
            if (temp2->getcolor() == "Blue" ){  
			    PrintForm2();  
                cout << endl;  
                temp2->Print();  
                cout << endl;  
                flag2 = true;  
                break;  
            }  
	  }  
   }  
   if (flag1){  
	   return temp1;  
   }  
   if (flag2 ){  
	   return temp2;  
   } else{  
	   cout << "ERROR: Nothing found" << endl;  
       return nullptr;  
   }  
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація  роботи методів пошуку

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab27/doc/assets/Screenshot_2.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Результат виконання всієї програми

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab27/doc/assets/Screenshot_1.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Демонстрація відсутності витоків пам'яті.

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab26/doc/assets/valgrind.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3


### Структура проекту

	├── lab27
	    ├── doc
	        ├── lab11.md
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

Ми зрозуміли що таке "Поліморфізм"; навчились працювати з класами-спадкоємцями та зі списком для них.

