#include "truck.h"
#include <cmath>

/*
грузовик распределяет товары между складами и магазинами:
изначально 30% товаров грузовик везет в магазин store1, 70% - на склад warehouse1;
когда место в store1 начинает заканчиваться, тогда все, что не поместилось, отправляется в warehouse1;
далее 30% товара грузовик начинает отвозить во второй магазин store2, а 70% продолжать отвозить на склад warehouse1;
когда место в warehouse1 начинает заканчиваться, тогда все, что не поместилось, отправляется на другой склад warehouse2;
далее 30% товара грузовик продолжает отвозить в магазин store2, а 70% начинает отвозить на склад warehouse2;
когда место в store2 начинает заканчиваться, тогда все, что не поместилось, отправляется в warehouse1, если там еще есть
место. если нет - на склад warehouse2;
когда место в warehouse2 заканчивается, мы перестаем принимать товары.
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
        // распределение 30/70 между store1 и warehouse1
        if ((store1.max_capacity - store1_capacity >= store_quantity) &&
        (warehouse1.max_capacity - warehouse1_capacity >= warehouse_quantity)) {
            product->quantity = store_quantity;
            store1.addProduct(*product);
            product->quantity = warehouse_quantity;
            warehouse1.addProduct(*product);
        }
        // то, что помещается в store1, добавляем туда. остальное - в warehouse1
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
        // распределение 30/70 между store2 и warehouse1
        if ((store2.max_capacity - store2_capacity >= store_quantity) &&
            (warehouse1.max_capacity - warehouse1_capacity >= warehouse_quantity)) {
            product->quantity = store_quantity;
            store2.addProduct(*product);
            product->quantity = warehouse_quantity;
            warehouse1.addProduct(*product);
        }
        // то, что помещается в store2, добавляем туда. остальное - в warehouse1
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
         // распределение 30/70 между store2 и warehouse2
         if ((store2.max_capacity - store2_capacity >= store_quantity) &&
             (warehouse2.max_capacity - warehouse2_capacity >= warehouse_quantity)) {
             product->quantity = store_quantity;
             store2.addProduct(*product);
             product->quantity = warehouse_quantity;
             warehouse2.addProduct(*product);
         }
         // то, что помещается в store2, добавляем туда. остальное - в warehouse2
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

     // то, что помещается в warehouse1, добавляем туда. остальное - в warehouse2
     if ((warehouse1.max_capacity - warehouse1_capacity < product_full_quantity) && 
         (warehouse2.max_capacity - warehouse2_capacity >= product_full_quantity)) {
         if (warehouse1.max_capacity - warehouse1_capacity > 0) {
             product->quantity = warehouse1.max_capacity - warehouse1_capacity;
             warehouse1.addProduct(*product);
         }
         product->quantity = product_full_quantity - (warehouse1.max_capacity - warehouse1_capacity);
         warehouse2.addProduct(*product);
     }
     // то, что помещается в warehouse2, добавляем туда. остальное не добавляем
     else if (warehouse2.max_capacity - warehouse2_capacity < product_full_quantity) {
         product->quantity = warehouse2.max_capacity - warehouse2.products.size();
         if (warehouse2.max_capacity - warehouse2_capacity > 0) {
             product->quantity = warehouse2.max_capacity - warehouse2_capacity;
             warehouse2.addProduct(*product);
             cout << "All storage locations are full. Product cannot be accepted." << endl;
         }
     }

     // место закончилось
     if (warehouse2.max_capacity == warehouse2_capacity) {
        cout << "All storage locations are full. Product cannot be accepted." << endl;
     }
}
