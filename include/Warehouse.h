#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

/* на складе помещается 10000 единиц товара.
товары добавляются на склад после того, как их привозит грузовик;
товары на складе можно посмотреть */
class Warehouse {
public:
    vector<Product> products;
    const int max_capacity = 10000;

    void addProduct(Product& product);

    void displayProducts(const string& warehouseName);
};

#endif // WAREHOUSE_H
