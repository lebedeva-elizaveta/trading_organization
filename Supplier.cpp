#include "supplier.h"
#include "product.h"

void Supplier::sendToTruck(string name, int quantity, string type, Truck& truck, Store& store1, Store& store2, 
    Warehouse& warehouse1, Warehouse& warehouse2) {
    Product* product = new Product(name, quantity, type);
    truck.load(product, store1, store2, warehouse1, warehouse2);
    delete product;
}
