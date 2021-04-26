
# Лабораторна робота №8. ООП. Потоки

## 1. Вимоги

### 1.1 Розробник
 
- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 26-квітня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
	 * використання функцій `printf/scanf` замінити на `cin/cout`;
	 * усі конкатенації строк замінити на використання `stringstream`;  
	 * замінити метод вводу інформації про об'єкт на метод, що приймає рядок з інформацією про об'єкт, обробляє його та створює об'єкт  на базі цієї інформації;
	 * поширити клас-список, шляхом реалізації методів роботи з файлами.

 
### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів. 

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених методів. Методи:  `SplitLineToObject` обробляє строку;`toString()` перетворює об'єкт в строку; `ReadFromFile` зчитує масив елементів з файлу; `WriteToFile` записує масив елементів у файл .

_Головна функція_`main()`. 
Створює елементи списку та додає їх у список, викликає усі розроблені методи


_Метод пошуку_ `SplitLineToObject`. Метод який приймає строку, та обробляє її таким чином, щоб на основі даної строки зробити об'єкт списку
_Схема алгоритму метода_ подана на рис. 1.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab24/doc/assets/SplitLineToObject.png?raw=true)

Рисунок 1 --- Схема алгоритму методу `SplitLineToObject`

_Метод_ `ReadFromFile`: Метод зчитує масив елементів з файлу.

_Метод_ `WriteToFile`: Метод записує масив елементів у файл.





### 2.3 Важливі фрагменти програми

#### Метод обробки рядка в об'єкт

``` 
Backpack& Backpack::SplitLineToObject(const string &object) const{  
    string buffer = object;  
    string str;  
    stringstream buf;  
    int flag = 0;  
    int pos = 0;  
    auto *temp = new Backpack;  
    int len = object.length();  
    for (int i = 0; i < len; ++i) {  
		if(object[i] == ' '){  
			if (flag == 0){  
				pos = buffer.find(' ');  
                str = buffer.substr(0, pos);  
                int LD;  
                buf << str;  
                buf >> LD;  
                temp->setlaptop_department(LD);  
                buffer.erase(0, pos + 1);  
                buf.clear();  
                flag++;  
                pos = i;  
            }else if (flag == 1){  
			    pos = buffer.find(' ');  
                str = buffer.substr(0, pos);  
                temp->setcolor(str);  
                buffer.erase(0, pos + 1);  
                flag++;  
            }else if (flag == 2) {  
			    pos = buffer.find(' ');  
                str = buffer.substr(0, pos);  
                int vol;  
                buf << str;  
                buf >> vol;  
                temp->setvolume(vol);  
                buffer.erase(0, pos + 1);  
                buf.clear();  
                flag++;  
            } else if (flag == 3){  
			    pos = buffer.find(' ');  
                str = buffer.substr(0, pos);  
                int aim;  
                buf << str;  
                buf >> aim;  
                switch (aim) {  
				    case 0:  
                        temp->setpurpose(URBAN);  
                        break;  
                    case 1:  
                        temp->setpurpose(TACTICAL);  
                        break;  
                    case 2:  
                        temp->setpurpose(TOURIST);  
                    default:  
                        break;  
                }  
			    buf.clear();  
                buffer.erase(0, pos + 1);  
                flag++;  
            }else if(flag == 4){   
				  for (int j = 0; j < buffer.length(); ++j) {  
					if(buffer[j] == ' '){  
					    pos = buffer.find(' ');  
                        string name = buffer.substr(0, pos);  
                        buffer.erase(0, pos + 1);  
                        pos = buffer.find('\r');  
                        string country = buffer.substr(0, pos);  
                        Firm *firm = new Firm(name, country);  
                        temp->setfirm(firm);  
                        break;  
                    }  
				  }  
				  break;  
            }  
   }
   return *temp;  
}
  
```
#### Метод перетворення об'єкта в строку

```
string Backpack::toString() const {  
  stringstream result;  
    result << getlaptop_department() << " " << getcolor() << " " << getvolume() << " " << getpurpose() << " "  
	  << getfirm().getName() << " " << getfirm().getCountry() << endl;  
    return result.str();  
}
```
#### Метод зчитування елементів з файлу
```
void List::ReadFromFile(const string &path) {  
    ifstream fin;  
    fin.open(path);  
    string obj;  
    this->setCount(6);  
    this->backpacks = new Backpack*[Count];  
    for (int i = 0; i < Count; ++i) {  
		if (!fin.is_open()) {  
		    cout << "ERROR: The file did not open!" << endl;  
        } else {  
		    getline(fin, obj);  
            this->backpacks[i] = &this->SplitLineToObject(obj);  
        }  
	}  
  fin.close();  
}
```
#### Метод запису масиву елементів у файл
```
void List::WriteToFile(const string &path) {  
    ofstream fout;  
    fout.open(path);  
    for (int i = 0; i < Count; ++i) {  
		  if (!fout.is_open()) {  
			  cout << "ERROR: The file did not open!" << endl;  
        } else {  
			  fout << this->getBackpack(i).toString();  
        }  
 }
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Результат роботи методу обробки перетворення об'єкта в строку

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab24/doc/assets/Screenshot_1.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Результат роботи методу перетворення строки в об'єкт.

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab24/doc/assets/Screenshot_2.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Демонстрація відсутності витоків пам'яті.

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab23/doc/assets/Screenshot_6.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3


### Структура проекту

	├── lab24
	    ├── doc
	        ├── lab8.md
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

Ми навчились працювати з потоками.

