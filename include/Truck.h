#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include "product.h"
#include "store.h"
#include "warehouse.h"

using namespace std;

// грузовик распределяет товары между складами и магазинами
class Truck {
public:
    void load(Product* product, Store& store1, Store& store2, Warehouse& warehouse1, Warehouse& warehouse2);
};

#endif // TRUCK_H
