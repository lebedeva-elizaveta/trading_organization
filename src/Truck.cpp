#include "truck.h"
#include <cmath>

/*
�������� ������������ ������ ����� �������� � ����������:
���������� 30% ������� �������� ����� � ������� store1, 70% - �� ����� warehouse1;
����� ����� � store1 �������� �������������, ����� ���, ��� �� �����������, ������������ � warehouse1;
����� 30% ������ �������� �������� �������� �� ������ ������� store2, � 70% ���������� �������� �� ����� warehouse1;
����� ����� � warehouse1 �������� �������������, ����� ���, ��� �� �����������, ������������ �� ������ ����� warehouse2;
����� 30% ������ �������� ���������� �������� � ������� store2, � 70% �������� �������� �� ����� warehouse2;
����� ����� � store2 �������� �������������, ����� ���, ��� �� �����������, ������������ � warehouse1, ���� ��� ��� ����
�����. ���� ��� - �� ����� warehouse2;
����� ����� � warehouse2 �������������, �� ��������� ��������� ������.
*/
void Truck::load(Product* product, Store& store1, Store& store2, Warehouse& warehouse1, Warehouse& warehouse2) {

    int store_quantity = static_cast<int>(round(product->quantity * 0.3));
    int warehouse_quantity = static_cast<int>(round(product->quantity * 0.7));
    int product_full_quantity = product->quantity;

    int store1_capacity = 0, warehouse1_capacity = 0, store2_capacity = 0, warehouse2_capacity = 0;

    for (const auto& p : store1.products)
        store1_capacity += p.quantity;
    cout << store1_capacity << endl;

    for (const auto& p : warehouse1.products)
        warehouse1_capacity += p.quantity;
    cout << warehouse1_capacity << endl;

    for (const auto& p : store2.products)
        store2_capacity += p.quantity;
    cout << store2_capacity << endl;

    for (const auto& p : warehouse2.products)
        warehouse2_capacity += p.quantity;
    cout << warehouse2_capacity << endl;

    if ((store1_capacity < store1.max_capacity) && (warehouse1_capacity < warehouse1.max_capacity)) {
        // ������������� 30/70 ����� store1 � warehouse1
        if ((store1.max_capacity - store1_capacity >= store_quantity) &&
        (warehouse1.max_capacity - warehouse1_capacity >= warehouse_quantity)) {
            product->quantity = store_quantity;
            store1.addProduct(*product);
            product->quantity = warehouse_quantity;
            warehouse1.addProduct(*product);
        }
        // ��, ��� ���������� � store1, ��������� ����. ��������� - � warehouse1
        else if ((store1.max_capacity - store1_capacity < store_quantity) && 
            (warehouse1.max_capacity - warehouse1_capacity >= product_full_quantity)) {
            if(store1.max_capacity - store1_capacity > 0) {
                product->quantity = store1.max_capacity - store1_capacity;
                store1.addProduct(*product);
            }
            product->quantity = product_full_quantity - (store1.max_capacity - store1_capacity);
            warehouse1.addProduct(*product);
       }
    }

    else if (store1_capacity == store1.max_capacity) {
        // ������������� 30/70 ����� store2 � warehouse1
        if ((store2.max_capacity - store2_capacity >= store_quantity) &&
            (warehouse1.max_capacity - warehouse1_capacity >= warehouse_quantity)) {
            product->quantity = store_quantity;
            store2.addProduct(*product);
            product->quantity = warehouse_quantity;
            warehouse1.addProduct(*product);
        }
        // ��, ��� ���������� � store2, ��������� ����. ��������� - � warehouse1
        else if ((store2.max_capacity - store2_capacity < store_quantity) &&
            (warehouse1.max_capacity - warehouse1_capacity >= product_full_quantity)) {
            if (store2.max_capacity - store2_capacity > 0) {
                product->quantity = store2.max_capacity - store2_capacity;
                store2.addProduct(*product);
            }
            product->quantity = product_full_quantity - (store2.max_capacity - store2_capacity);
            warehouse1.addProduct(*product);
        }
    }

     if (warehouse1_capacity == warehouse1.max_capacity) {
         // ������������� 30/70 ����� store2 � warehouse2
         if ((store2.max_capacity - store2_capacity >= store_quantity) &&
             (warehouse2.max_capacity - warehouse2_capacity >= warehouse_quantity)) {
             product->quantity = store_quantity;
             store2.addProduct(*product);
             product->quantity = warehouse_quantity;
             warehouse2.addProduct(*product);
         }
         // ��, ��� ���������� � store2, ��������� ����. ��������� - � warehouse2
         else if ((store2.max_capacity - store2_capacity < store_quantity) &&
             (warehouse2.max_capacity - warehouse2_capacity >= product_full_quantity)) {
             if (store2.max_capacity - store2_capacity > 0) {
                 product->quantity = store2.max_capacity - store2_capacity;
                 store2.addProduct(*product);
             }
             product->quantity = product_full_quantity - (store2.max_capacity - store2_capacity);
             warehouse2.addProduct(*product);
         }
     }

     // ��, ��� ���������� � warehouse1, ��������� ����. ��������� - � warehouse2
     if ((warehouse1.max_capacity - warehouse1_capacity < product_full_quantity) && 
         (warehouse2.max_capacity - warehouse2_capacity >= product_full_quantity)) {
         if (warehouse1.max_capacity - warehouse1_capacity > 0) {
             product->quantity = warehouse1.max_capacity - warehouse1_capacity;
             warehouse1.addProduct(*product);
         }
         product->quantity = product_full_quantity - (warehouse1.max_capacity - warehouse1_capacity);
         warehouse2.addProduct(*product);
     }
     // ��, ��� ���������� � warehouse2, ��������� ����. ��������� �� ���������
     else if (warehouse2.max_capacity - warehouse2_capacity < product_full_quantity) {
         product->quantity = warehouse2.max_capacity - warehouse2.products.size();
         if (warehouse2.max_capacity - warehouse2_capacity > 0) {
             product->quantity = warehouse2.max_capacity - warehouse2_capacity;
             warehouse2.addProduct(*product);
             cout << "All storage locations are full. Product cannot be accepted." << endl;
         }
     }

     // ����� �����������
     if (warehouse2.max_capacity == warehouse2_capacity) {
        cout << "All storage locations are full. Product cannot be accepted." << endl;
     }
}
