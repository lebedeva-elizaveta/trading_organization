#include "retailclient.h"

void RetailClient::buy(Product& product, int quantity, Warehouse& warehouse, Store& store) {
    if (quantity > 0 && quantity <= product.quantity) {
        // еще раз проверяем количество, точно ли меньше 10
        if (quantity < 10) {
            if (quantity <= store.products.size()) {
                product.quantity -= quantity;
                store.products.erase(store.products.begin(), store.products.begin() + quantity);
                std::cout << "Retail purchase successful. " << quantity << " units of " << product.name 
                    << " bought from store." << std::endl;
            }
        }
    }
}
