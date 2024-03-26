#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

/* �� ������ ���������� 10000 ������ ������.
������ ����������� �� ����� ����� ����, ��� �� �������� ��������;
������ �� ������ ����� ���������� */
class Warehouse {
public:
    vector<Product> products;
    const int max_capacity = 10000;

    void addProduct(Product& product);

    void displayProducts(const string& warehouseName);
};

#endif // WAREHOUSE_H
