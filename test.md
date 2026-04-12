Что выведет код?
```c++
int a = 1;
int b = 2;
std::cout << a / b << std::endl;
```

Что выведет код?
```c++
int a = 5;
int* p = &a;
*p = 10;
std::cout << a;
```

Что означает следующее объявление?
```c++
const int* const ptr = &x;
```

Как изменится значение?
```c++
void foo(int x) { x + 1; }
void bar(int& x) { x + 1; }

int x = 1;

foo(x);
bar(x);
```

Что означают эти ключевые слова?

```c++
static
inline
```

Что это такое?

    Local storage
    Static storage
    Dynamic storage


Что здесь происходит и есть ли проблемы?
```c++
int main() {
    int* x = new 5;
}
```

Описать контейнеры и сложность их операций.
```c++
std::vector<int> vector;
std::list<int> list;
std::map<std::string_vew, int> map;
std::unordered_map<std::string_vew, int> umap;
```

В чем разница?
```c++
std::vector<int> vector;

vector.resize(5);
vector.reserve(5);
```


Что выведет код?
```c++
class Base {
public:
    virtual void print() { std::cout << "Base"; }
};

class Derived : public Base {
public:
    void print() { std::cout << "Derived"; }
};

Base* b = new Derived();
b->print();
```

Для чего нужен виртуальный деструктор в базовом классе?

Что это такое и в чем разница?
```c++
std::unique_ptr<Foo> uptr;
std::shared_ptr<Foo> sptr;
```

Что такое "Большая Пятерка" или "Big Five"?

Что здесь происходит?
```c++

int a = 42;
int&& x = std::move(a);

```

Что выведет код?
```c++

template<typename T>
void foo(T) { std::cout << "T"; }

template<>
void foo<double>(double) { std::cout << "double"; }

void foo(int) { std::cout << "int"; }

int main() {
    double x = 1.0;
    foo(x);
}

```

Что выведет этот код?
```cpp
try {
    throw 42;
    cout << "A";
} catch (int e) {
    cout << "B";
    throw;
} catch (...) {
    cout << "C";
}
cout << "D";
```