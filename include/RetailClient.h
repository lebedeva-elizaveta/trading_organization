#ifndef RETAILCLIENT_H
#define RETAILCLIENT_H

#include "client.h"
#include "warehouse.h"
#include "store.h"
#include <iostream>

// ���������� ��������� ���������, ���� �� ����� ������ <10 ������ ������
class RetailClient : public Client {
public:
    void buy(Product& product, int quantity, Warehouse& warehouse, Store& store) override;
};

#endif // RETAILCLIENT_H
