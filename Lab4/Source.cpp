#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ��������� ���� ������
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ������� ��� �������� ������
struct Node* CreateTree(struct Node* root, int data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        if (root == NULL) {
            printf("������ ��������� ������\n");
            exit(0);
        }
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    return root;
}


// ������� ��� ������ ������ �� �����
void print_tree(struct Node* r, int l) {
    if (r == NULL) {
        return;
    }

    print_tree(r->right, l + 1);  // ������ ���������
    for (int i = 0; i < l; i++) {
        printf(" ");
    }
    printf("%d\n", r->data);  // ������� ������ ����
    print_tree(r->left, l + 1);  // ����� ���������
}

// ������� ��� ������ �������� � ������
struct Node* search(struct Node* root, int key) {
    // ���� ������ ������ ��� �������� �������
    if (root == NULL || root->data == key) {
        return root;
    }

    // ���� ���� ������ �������� ����, ���� � ����� ���������
    if (key < root->data) {
        return search(root->left, key);
    }

    // ���� ���� ������ �������� ����, ���� � ������ ���������
    return search(root->right, key);
}

// ������� ��� �������� ����� ��������� ��������� �������� � ������
int countOccurrences(struct Node* root, int key) {
    if (root == NULL) {
        return 0;  // ���� ������ �����, ���������� 0
    }

    int count = 0;
    if (root->data == key) {
        count = 1;  // ���� ������� ������� ��������� � �������, ����������� �������
    }

    // ���������� ���� � ����� � ������ �����������
    count += countOccurrences(root->left, key);
    count += countOccurrences(root->right, key);

    return count;
}

int main() {
    setlocale(LC_ALL, "");  // ��� ����������� ����������� ���������

    int D, start = 1;
    struct Node* root = NULL;

    printf("-1 - ��������� ���������� ������\n");
    while (start) {
        printf("������� �����: ");
        scanf("%d", &D);  
        if (D == -1) {
            printf("���������� ������ ��������\n\n");
            start = 0;
        }
        else {
            root = CreateTree(root, D);
        }
    }

    printf("����� ������:\n");
    print_tree(root, 0);  // ������� ������

    // ����� �������� � ������
    printf("������� �������� ��� ������ � ������: ");
    scanf("%d", &D);
    struct Node* foundNode = search(root, D);
    if (foundNode != NULL) {
        printf("������� %d ������ � ������.\n", D);
    }
    else {
        printf("������� %d �� ������ � ������.\n", D);
    }

    // ������� ����� ��������� ��������
    int occurrences = countOccurrences(root, D);
    printf("����� ��������� �������� %d � ������: %d\n", D, occurrences);

    return 0;
}
