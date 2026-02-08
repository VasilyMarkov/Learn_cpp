Реализация класса `StringBuilder`.
Класс преобразует переданный объект в строку.

Реализовать следующее поведение:
```c++
StringBuilder sb("Hello, world!");
std::cout << sb; ///оператор вывода, вывод в консоли: Hello, world!

StringBuilder sb1(5);
std::cout << sb1; //оператор вывода, вывод в консоли: 5

std::vector<int> vec = {1,2,3,4,5};
StringBuilder sb2(vec);

std::cout << sb2.size(); // размер строки

std::cout << sb2; //вывод всех элементов контейнера без разделителей, вывод в консоли: 12345

std::cout << sb + sb2; //конкатинация строк,  оператор должен вернуть новый StringBulder.

std::string str = sb2.str(); //возврат строки типа std::string
```

Типы объектов, которые можно передать в StringBuilder:
- Любой базовый тип либо строчный тип: (int, float, const char*, std::string).
- Любой не ассоциативный контейнер c базовым типом (std::vector<int>, std::list<float> и т.д)


### Дополнительно:

Добавить возможность задавать пользовательский разделитель для контейнеров.

Реализовать следующие методы используя паттерн `Fluent interface`:
```c++
template<typename T>
append(T val) //вставить значение в конец строки.

reverse() //развернуть строку.

std::vector<int> vec = {1,2,3,4,5};
StringBuilder sb = StringBuilder("Values: ").append(vec).reverse();

std::cout << sb; //54321 :seulaV
```