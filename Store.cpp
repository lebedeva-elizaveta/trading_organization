#include "store.h"

void Store::addProduct(Product& product) {
    if (products.size() < max_capacity) {
        products.push_back(product);
    }
    else {
        cout << "Store is full. Cannot add more products." << endl;
    }
}

void Store::displayProducts(const string& storeName) {
    cout << "Products in " << storeName << ":" << endl;
    for (const auto& product : products) {
        cout << product.name << " - " << product.quantity << " - " << product.type << endl;
    }
}
