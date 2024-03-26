#include "warehouse.h"

void Warehouse::addProduct(Product& product) {
    if (products.size() < max_capacity) {
        products.push_back(product);
    }
    else {
        cout << "Warehouse is full. Cannot add more products." << endl;
    }
}

void Warehouse::displayProducts(const string& warehouseName) {
    cout << "Products in " << warehouseName << ":" << endl;
    for (const auto& product : products) {
        cout << product.name << " - " << product.quantity << " - " << product.type << endl;
    }
}
