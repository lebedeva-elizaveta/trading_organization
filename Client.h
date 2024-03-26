#ifndef CLIENT_H
#define CLIENT_H

#include "product.h"
#include "warehouse.h"
#include "store.h"

// клиент может только покупать товары
class Client {
public:
    virtual void buy(Product& product, int quantity, Warehouse& warehouse, Store& store) = 0;
};

#endif // CLIENT_H
