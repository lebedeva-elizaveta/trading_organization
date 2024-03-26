#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

/* � �������� ���������� 1000 ������ ������.
������ ����������� � ������� ����� ����, ��� �� �������� ��������;
������ � �������� ����� ���������� */
class Store {
public:
    vector<Product> products;
    const int max_capacity = 1000;

    void addProduct(Product& product);

    void displayProducts(const string& storeName);
};

#endif // STORE_H
