#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "warehouse.h"
#include "store.h"

 // торговая организация содержит магазины и склады
class Organization {
public:
    Warehouse warehouse;
    Store store;
};

#endif // ORGANIZATION_H
