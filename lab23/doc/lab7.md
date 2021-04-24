
# Лабораторна робота №7. Вступ до ООП

## 1. Вимоги

### 1.1 Розробник

- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 24-квітня-2021

### 1.2 Загальне завдання

 1. **Розробити клас**, що відображає сутність базового класу, у тому числі:
	 * конструктор за замовчуванням
	 * конструктор копіювання
	 * конструктор з аргументами
	 * деструктор 

 2. **Розробити клас**, що  має у собі:
	 * динамічний масив об'єктів базового класу
	 * метод додавання елемента
	 * метод видалення елемента
	 * метод отримання елемента по індексу
	 * метод виводу усіх елементів на екран
	 * метод 1 обходу колекції (знаходження німецького міського рюкзака) 
 
### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів. 

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених методів. Методи:  `addBackpack` додає нові елементи в список;`removeBackpack` видаляє елемент зі списку по індексу; `getBackpack` отримує елемент по індексу; `ShowAll` виводить список на екран;`FindGermanCityBackpack` виконує пошук елемента .

_Головна функція_`main()`. 
Створює елементи списку та додає їх у список, викликає усі розроблені методи


_Метод пошуку_ `FindGermanCityBackpack`. Метод 1 обходу колекції; Функція знаходить німецький міський рюкзак серед списку елементів.
_Схема алгоритму метода_ подана на рис. 1.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab23/doc/assets/FindGermanCityBackpack.png?raw=true)

Рисунок 1 --- Схема алгоритму методу `FindGermanCityBackpack`

_Метод_ `ShowAll`: Метод виводить список елементів на екран.

_Метод_ `getBackpack`: Метод повертає елемент зі списку по заданому індексу.

_Метод_ `removeBackpack`: Метод видаляє елемент зі списку по заданому індексу.

_Метод_ `addBackpack`: Метод додає елемент у список.




### 2.3 Важливі фрагменти програми

#### Метод пошуку німецького міського рюкзаку

``` 
Backpack& List::FindGermanCityBackpack() const{  
    string country = "Germany";  
    Purpose purpose = URBAN;  
    int index = - 1;  
    for (int i = 0; i < this->Count; ++i) {  
		  Backpack temp = getBackpack(i);  
          if(country == temp.getfirm().getCountry() && purpose == temp.getpurpose()){  
			  temp.Print();  
              index = i;  
        }  
   }  if (index == -1){  
		  cout << "ERROR: German city backpack not found" << endl;  
          return getBackpack(0);  
    } else {  
		  return getBackpack(index);  
    }  
}
  
```
#### Метод виводу не екран

```
 void List::ShowAll() const {  
    for (int i = 0; i < this->Count; ++i) {  
    Backpack temp = getBackpack(i);  
        temp.Print();  
    }  
  }
```
#### Метод видалення  елементу
```
void List::removeBackpack(int index) {  
	auto **temp = new Backpack*[this->Count - 1];  
    if(index < 0){  
		index= 0;  
    }  
    if(index >= this->Count) {  
		index = this->Count - 1;  
    }  
	memcpy(temp, backpacks, sizeof (Backpack) * (index));  
    memcpy(temp + index, backpacks + index + 1, sizeof (Backpack) * (Count - index));  
    delete [] this->backpacks;  
    this->backpacks = temp;  
    this->Count -= 1;  
}
```
#### Метод отримання елементу по індексу
```
Backpack& List::getBackpack(int index) const{  
  if(index < 0){  
  index= 0;  
    }  
  if(index >= this->Count) {  
  index = this->Count - 1;  
    }  
  
  return *backpacks[index];  
}
```
#### Метод додання елементу
```
void List::addBackpack(Backpack &backpack) {  
  auto **temp = new Backpack*[this->Count + 1];  
  for (int i = 0; i < this->Count; ++i) {  
	  temp[i] = new Backpack;  
      temp[i] = this->backpacks[i];  
  }  
  temp[Count] = &backpack;  
  this->backpacks = temp;  
  this->Count +=1;  
}
```
### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Результат роботи методу пошуку елементу

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab23/doc/assets/Screenshot_2.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Демонстрація відсутності витоків пам'яті.

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab23/doc/assets/Screenshot_6.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Результат роботи всієї програми

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab23/doc/assets/Screenshot_1.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3


### Структура проекту

	├── lab23
	    ├── doc
	        ├── lab7.md
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

Ми навчились створювати класи, та розробляти методи для роботи з ними.

