## Подключение и создание

```cpp
#include <vector>
#include <string>

```

### Создать vector

```cpp
vector<int> v1;           // пустой
vector<int> v2(5);        // 5 нулей
vector<int> v3(5, 42);    // 5 × 42
vector<int> v4 = {1,2,3}; // список инициализации
```

### Создать string

```cpp
string s1;                // пустая
string s2 = "hello";      // из литерала
string s3(5, 'a');        // "aaaaa"
string s4 = s2;           // копия
```

---

## Добавление и удаление элементов — `vector`

```cpp
v.push_back(10);          // добавить в конец
v.pop_back();             // удалить последний
v.clear();                // очистить всё

// вставить 99 перед индексом 2:
v.insert(v.begin() + 2, 99);

// удалить элемент с индексом 1:
v.erase(v.begin() + 1);
```

> ⚠️ Вставка/удаление в середину — медленно для больших векторов.

---

## Доступ к элементам — `vector` и `string`

```cpp
v[0];          // без проверки границ
v.at(0);       // с проверкой (безопаснее)
v.front();     // первый элемент
v.back();      // последний элемент

v.size();      // количество элементов
v.empty();     // true если пусто
v.capacity();  // выделено памяти
v.resize(10);  // изменить размер
```

---

## Перебор элементов — `vector` и `string`

```cpp
// Range-based for (рекомендуется)
for (auto x : v) {
    cout << x << " ";
}

// Изменение элементов — нужна &
for (auto& x : v) {
    x *= 2;
}

// Классический for
for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i];
}

// Перебор символов строки
for (char c : s) {
    cout << c;
}
```

---

## Работа со строками — `string`

### Склеивание и добавление

```cpp
s1 + s2;            // новая строка
s1 += " world";     // добавить в конец
s1 += '!';          // добавить символ
s.append("abc");    // то же, что +=
```

### Поиск и подстроки

```cpp
// найти позицию подстроки:
size_t pos = s.find("lo"); // вернёт индекс или string::npos
if (pos != string::npos) {
    // нашли!
}

// вырезать подстроку (start, length):
string sub = s.substr(1, 3);
```

### Сравнение и размер

```cpp
s1 == s2;     // сравнение
s1 < s2;      // лексикографически
s.size();     // длина строки
s.length();   // то же самое
s.empty();    // пустая?
s.clear();    // очистить
```

### Конвертация

```cpp
// число → строка:
string s = to_string(42);

// строка → число:
int    n = stoi("42");
double d = stod("3.14");
```

---

## Алгоритмы из `<algorithm>` — `vector`

```cpp
#include <algorithm>

sort(v.begin(), v.end());           // сортировка
reverse(v.begin(), v.end());        // разворот
auto it = find(v.begin(), v.end(), 42); // поиск значения
int m = *max_element(v.begin(), v.end()); // максимум
```

> 💡 Все алгоритмы принимают `begin()` и `end()` — диапазон элементов.

---