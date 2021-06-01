
# Лабораторна робота №16. ООП. Розумні вказівники

## 1. Вимоги

### 1.1 Розробник
 
- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 30-травня-2021

### 1.2 Загальне завдання

 * **Створити** STL-контейнер, що містить у собі об'єкти ієрархії класів, використати розумні вказівники:
	 * `unique_ptr`
	 * `shared_ptr`
	 * `weak_ptr  `

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розумних вказівників: `unique_ptr`, `shared_ptr` та `weak_ptr`.

### 2.2 Опис логічної структури програми

_Вказівник:_  `unique_ptr`: Унікальний вказівник, який використовується для управління будь-яким динамічно виділеним об'єктом / ресурсом, але з умовою, що `unique_ptr` повністю володіє переданим йому об'єктом, а не «ділиться володінням» ще з іншими вказівниками. Таким чином, не можна  `unique_ptr` покажчику присвоїти інший  `unique_ptr` покажчик, який посилається на інший об'єкт. 


_Вказівник:_  `shared_ptr`: даний розумний покажчик  використовується для володіння одним динамічно виділеним ресурсом відразу декількома розумними покажчиками. Ресурс буде знищений, коли останній `shared_ptr` вийде з зони видимості.

_Вказівник:_  `weak_ptr`: використовується для вирішення проблеми «циклічної залежності», яку може створити`shared_ptr`.  `weak_ptr`є «спостерігачем» - він може спостерігати і отримувати доступ до того ж об'єкту, на який вказує `shared_ptr`, але не рахуватися власником цього об'єкта. І коли `shared_ptr` виходить з області видимості, він перевіряє, чи є інші власники `shared_ptr`. А **`weak_ptr`власником не рахується!**


### 2.3 Важливі фрагменти програми

####  Створення контейнеру на основі `unique_ptr`

``` 
List<unique_ptr<Backpack>> list;  
  
unique_ptr<Backpack> uniquePtr(new LeatherBackpack(leatherBackpack));  
unique_ptr<Backpack> uniquePtr1(new LeatherBackpack(leatherBackpack1));  
unique_ptr<Backpack> uniquePtr2(new LeatherBackpack(leatherBackpack2));  
unique_ptr<Backpack> uniquePtr3(new FabricBackpack(fabricBackpack));  
unique_ptr<Backpack> uniquePtr4(new FabricBackpack(fabricBackpack1));  
unique_ptr<Backpack> uniquePtr5(new FabricBackpack(fabricBackpack2));

list.addItem(&uniquePtr);  
list.addItem(&uniquePtr1);  
list.addItem(&uniquePtr2);  
list.addItem(&uniquePtr3);  
list.addItem(&uniquePtr4);  
list.addItem(&uniquePtr5);

for (auto &backpack : list) {  
	  backpack->get()->Print();  // используем метод get() для конвертации std::unique_ptr в обычный указатель  
	  cout << endl;  
}
```

####  Створення контейнеру на основі `shared_ptr`

``` 
List<shared_ptr<Backpack>> list;  
  
shared_ptr<Backpack> sharedPtr (new LeatherBackpack(leatherBackpack));  
shared_ptr<Backpack> sharedPtr1 (new LeatherBackpack(leatherBackpack1));  
shared_ptr<Backpack> sharedPtr2 (new LeatherBackpack(leatherBackpack2));  
shared_ptr<Backpack> sharedPtr3 (new FabricBackpack(fabricBackpack));  
shared_ptr<Backpack> sharedPtr4 (new FabricBackpack(fabricBackpack1));  
shared_ptr<Backpack> sharedPtr5 (new FabricBackpack(fabricBackpack2));

ist.addItem(&sharedPtr);  
list.addItem(&sharedPtr1);  
list.addItem(&sharedPtr2);  
list.addItem(&sharedPtr3);  
list.addItem(&sharedPtr4);  
list.addItem(&sharedPtr5);

for (auto &backpack : list) {  
	  backpack->get()->Print();  // используем метод get() для конвертации std::shared_ptr в обычный указатель  
	  cout << endl;  
}
```

####  Створення контейнеру на основі `shared_ptr`

``` 
List<weak_ptr<Backpack>> list;  
  
// weak_ptr используется, когда нужен умный указатель, который имеет доступ к ресурсу, но не считается его владельцем.  
weak_ptr<Backpack> weakPtr = sharedPtr;  
weak_ptr<Backpack> weakPtr1 = sharedPtr1;  
weak_ptr<Backpack> weakPtr2 = sharedPtr2;  
weak_ptr<Backpack> weakPtr3 = sharedPtr3;  
weak_ptr<Backpack> weakPtr4 = sharedPtr4;  
weak_ptr<Backpack> weakPtr5 = sharedPtr5;  
weak_ptr<Backpack> weakPtr6 = weakPtr;

list.addItem(&weakPtr);  
list.addItem(&weakPtr1);  
list.addItem(&weakPtr2);  
list.addItem(&weakPtr3);  
list.addItem(&weakPtr4);  
list.addItem(&weakPtr5);  
list.addItem(&weakPtr6);

for (auto &backpack : list) {  
	  backpack->lock()->Print();  //используем метод lock() для конвертации std::weak_ptr в std::shared_ptr  
	  cout << endl;  
}
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.1 ). Демонстрація контейнеру на основі `unique_ptr`

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab32/doc/assets/Screenshot_1.png?raw=true)
Рисунок 1 --- Результат виконання кроку 1

_Крок 2_ (рис.2 ). Демонстрація контейнеру на основі `shared_ptr`

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab32/doc/assets/Screenshot_2.png?raw=true)
Рисунок 2 --- Результат виконання кроку 2

_Крок 3_ (рис.3 ). Демонстрація контейнеру на основі `weak_ptr`

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab32/doc/assets/Screenshot_3.png?raw=true)
Рисунок 3 --- Результат виконання кроку 3


### Структура проекту

	├── lab32
	    ├── doc
	        ├── lab16.md
	        └── assets
        ├── CMakelist.txt
		└── src
		    ├── main.cpp
            ├── Container.hpp
		    ├── Backpack.cpp
		    └── Backpack.h
## Висновки

Ми навчилися працювати зі стандартною бібліотекою шаблонів, з STL-контейнерами, їх методами і функціями. Також навчились використовувати розумні вказівники та дізналися різницю між ними.

