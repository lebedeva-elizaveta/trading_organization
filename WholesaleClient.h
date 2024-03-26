#ifndef WHOLESALECLIENT_H
#define WHOLESALECLIENT_H

#include "client.h"
#include "warehouse.h"
#include "store.h"
#include <iostream>

// ���������� ��������� �������, ���� �� ���������� ������ >= 10 ������ ������
class WholesaleClient : public Client {
public:
    void buy(Product& product, int quantity, Warehouse& warehouse, Store& store) override;
};

#endif // WHOLESALECLIENT_H
