#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

// ����� ������ �������� ���, ���������� � ��� ������
class Product {
public:
    string name;
    int quantity;
    string type;

    Product(string _name, int _quantity, string _type);
};

#endif // PRODUCT_H
