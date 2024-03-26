#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

/* в магазине помещается 1000 единиц товара.
товары добавляются в магазин после того, как их привозит грузовик;
товары в магазине можно посмотреть */
class Store {
public:
    vector<Product> products;
    const int max_capacity = 1000;

    void addProduct(Product& product);

    void displayProducts(const string& storeName);
};

#endif // STORE_H
