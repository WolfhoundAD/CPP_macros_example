#include <iostream>
#include <vector>
/*
Этот макрос DECLARE_TYPED_CONTAINER определяет простую структуру контейнера, специфичную для типа. 
Обратите внимание, что это не идеальный способ создания типобезопасных контейнеров, и лучше всего использовать 
шаблоны для этой цели. В реальном коде сложные макросы могут становиться трудными для понимания и отладки.
*/
#define DECLARE_TYPED_CONTAINER(ContainerType, ElementType) \
    struct ContainerType { \
        std::vector<ElementType> elements; \
        \
        void add(ElementType element) { \
            elements.push_back(element); \
        } \
        \
        void display() const { \
            std::cout << "Contents of " #ContainerType ": "; \
            for (const auto& element : elements) { \
                std::cout << element << " "; \
            } \
            std::cout << std::endl; \
        } \
    };

// Использование макроса для создания типобезопасного контейнера
DECLARE_TYPED_CONTAINER(IntContainer, int)

int main() {
    IntContainer container;
    container.add(1);
    container.add(2);
    container.display();

    return 0;
}
