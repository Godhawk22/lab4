#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Структура узла дерева
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Функция для создания дерева
struct Node* CreateTree(struct Node* root, int data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        if (root == NULL) {
            printf("Ошибка выделения памяти\n");
            exit(0);
        }
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    return root;
}


// Функция для вывода дерева на экран
void print_tree(struct Node* r, int l) {
    if (r == NULL) {
        return;
    }

    print_tree(r->right, l + 1);  // Правое поддерево
    for (int i = 0; i < l; i++) {
        printf(" ");
    }
    printf("%d\n", r->data);  // Выводим данные узла
    print_tree(r->left, l + 1);  // Левое поддерево
}

// Функция для поиска элемента в дереве
struct Node* search(struct Node* root, int key) {
    // Если корень пустой или значение найдено
    if (root == NULL || root->data == key) {
        return root;
    }

    // Если ключ меньше текущего узла, ищем в левом поддереве
    if (key < root->data) {
        return search(root->left, key);
    }

    // Если ключ больше текущего узла, ищем в правом поддереве
    return search(root->right, key);
}

// Функция для подсчёта числа вхождений заданного элемента в дерево
int countOccurrences(struct Node* root, int key) {
    if (root == NULL) {
        return 0;  // Если дерево пусто, возвращаем 0
    }

    int count = 0;
    if (root->data == key) {
        count = 1;  // Если текущий элемент совпадает с искомым, увеличиваем счетчик
    }

    // Рекурсивно ищем в левом и правом поддеревьях
    count += countOccurrences(root->left, key);
    count += countOccurrences(root->right, key);

    return count;
}

int main() {
    setlocale(LC_ALL, "");  // Для корректного отображения кириллицы

    int D, start = 1;
    struct Node* root = NULL;

    printf("-1 - окончание построения дерева\n");
    while (start) {
        printf("Введите число: ");
        scanf("%d", &D);  
        if (D == -1) {
            printf("Построение дерева окончено\n\n");
            start = 0;
        }
        else {
            root = CreateTree(root, D);
        }
    }

    printf("Вывод дерева:\n");
    print_tree(root, 0);  // Выводим дерево

    // Поиск элемента в дереве
    printf("Введите значение для поиска в дереве: ");
    scanf("%d", &D);
    struct Node* foundNode = search(root, D);
    if (foundNode != NULL) {
        printf("Элемент %d найден в дереве.\n", D);
    }
    else {
        printf("Элемент %d не найден в дереве.\n", D);
    }

    // Подсчёт числа вхождений элемента
    int occurrences = countOccurrences(root, D);
    printf("Число вхождений элемента %d в дерево: %d\n", D, occurrences);

    return 0;
}
