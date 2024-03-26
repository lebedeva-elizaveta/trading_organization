#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include "truck.h"
#include "store.h"
#include "warehouse.h"

using namespace std;

// поставщик просто принимает информацию о товаре и передает эти товары в грузовик
class Supplier {
public:
    void sendToTruck(string name, int quantity, string type, Truck& truck, Store& store1, Store& store2, Warehouse& warehouse1, Warehouse& warehouse2);
};

#endif // SUPPLIER_H
