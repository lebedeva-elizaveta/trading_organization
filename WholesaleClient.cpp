#include "wholesaleclient.h"

void WholesaleClient::buy(Product& product, int quantity, Warehouse& warehouse, Store& store) {
    if (quantity > 0 && quantity <= product.quantity) {
        // еще раз проверяем количество, точно ли >= 10
        if (quantity >= 10) {
            if (quantity <= warehouse.products.size()) {
                product.quantity -= quantity;
                warehouse.products.erase(warehouse.products.begin(), warehouse.products.begin() + quantity);
                std::cout << "Wholesale purchase successful. " << quantity << " units of " << product.name << " bought from warehouse." << std::endl;
            }
        }
    }
}
