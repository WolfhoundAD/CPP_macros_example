#include <iostream>
#include <string>

/*
В этом примере макрос GET_SET_PROPERTY генерирует геттеры и сеттеры для заданного свойства (поля) в классе Person.
Хотя такой подход с использованием макросов может быть мощным средством для автоматизации создания повторяющегося кода,
он также может усложнить отладку и понимание кода, поэтому использовать рекомендуется оккуратно.
*/
#define GET_SET_PROPERTY(type, name) \
private: \
    type name##_; \
public: \
    const type& get_##name() const { \
        return name##_; \
    } \
    void set_##name(const type& value) { \
        name##_ = value; \
    }

class Person {
    GET_SET_PROPERTY(std::string, Name)
        GET_SET_PROPERTY(int, Age)
        GET_SET_PROPERTY(double, Salary)
public:
    // Конструктор
    Person(const std::string& name, int age, double salary)
        : Name_(name), Age_(age), Salary_(salary) {}

    // Другие методы класса...
};

int main() {
    Person person("John Doe", 25, 50000.0);

    // Использование геттеров
    std::cout << "Name: " << person.get_Name() << std::endl;
    std::cout << "Age: " << person.get_Age() << std::endl;
    std::cout << "Salary: " << person.get_Salary() << std::endl;

    // Использование сеттеров
    person.set_Name("Jane Doe");
    person.set_Age(30);
    person.set_Salary(60000.0);

    // Проверка изменений
    std::cout << "\nUpdated Information:\n";
    std::cout << "Name: " << person.get_Name() << std::endl;
    std::cout << "Age: " << person.get_Age() << std::endl;
    std::cout << "Salary: " << person.get_Salary() << std::endl;

    return 0;
}
