#include "Organization.h"
#include "Supplier.h"
#include "WholesaleClient.h"
#include "RetailClient.h"
#include "Store.h"
#include "Warehouse.h"
#include "Truck.h"
#include "Product.h"

int main() {

    //выделяем память для объектов
    Organization* org = new Organization();

    Warehouse* warehouse1 = new Warehouse();
    Warehouse* warehouse2 = new Warehouse();
    Store* store1 = new Store();
    Store* store2 = new Store();

    Supplier* supplier = new Supplier();
    Truck* truck = new Truck();

    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Products" << endl;
        cout << "3. Buy Products" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // добавляем товар
            string name, type;
            int quantity;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product type: ";
            cin >> type;
            cout << "Enter product quantity: ";
            cin >> quantity;
            supplier->sendToTruck(name, quantity, type, *truck, *store1, *store2, *warehouse1, *warehouse2);
            cout << "Product added successfully." << endl;
            std::cout << std::endl;
            break;
        }

        case 2:
            // смотрим товары
            warehouse1->displayProducts("Warehouse 1");
            std::cout << std::endl;
            warehouse2->displayProducts("Warehouse 2");
            std::cout << std::endl;
            store1->displayProducts("Store 1");
            std::cout << std::endl;
            store2->displayProducts("Store 2");
            std::cout << std::endl;
            break;

        case 3: {
            // покупаем товары
            string name;
            int quantity;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter quantity to buy: ";
            cin >> quantity;

            bool productFound = false;

            if (quantity < 10) {
                //начинаем искать товары в магазинах store1 и store2, т.к. пришел розничный покупатель
                for (auto it = store1->products.begin(); it != store1->products.end(); ++it) {
                    if (it->name == name && it->quantity >= quantity) {
                        productFound = true;
                        RetailClient* retailClient = new RetailClient();
                        retailClient->buy(*it, quantity, *warehouse1, *store1);
                        delete retailClient;
                        it->quantity -= quantity;
                        if (it->quantity == 0) {
                            // удаляем вообще данный товар из магазина, если он закончился
                            store1->products.erase(it);
                        }
                        break;
                    }
                }
                // ищем товар в store2, если он не был найден в store1
                if (!productFound) {
                    for (auto it = store2->products.begin(); it != store2->products.end(); ++it) {
                        if (it->name == name && it->quantity >= quantity) {
                            productFound = true;
                            RetailClient* retailClient = new RetailClient();
                            retailClient->buy(*it, quantity, *warehouse2, *store2);
                            delete retailClient;
                            it->quantity -= quantity;
                            if (it->quantity == 0) {
                                store2->products.erase(it);
                            }
                            break;
                        }
                    }
                }
            }
            else {
                // теперь ищем на складах, потому что пришел оптовый покупатель с запросом >=10 товаров
                if (!productFound) {
                    // поиск по warehouse1
                    for (auto it = warehouse1->products.begin(); it != warehouse1->products.end(); ++it) {
                        if (it->name == name && it->quantity >= quantity) {
                            productFound = true;
                            WholesaleClient* wholesaleClient = new WholesaleClient();
                            wholesaleClient->buy(*it, quantity, *warehouse1, *store1);
                            delete wholesaleClient;
                            it->quantity -= quantity;
                            if (it->quantity == 0) {
                                warehouse1->products.erase(it);
                            }
                            break;
                        }
                    }
                }
                // поиск по warehouse2, если он не был найден в warehouse1
                if (!productFound) {
                    for (auto it = warehouse2->products.begin(); it != warehouse2->products.end(); ++it) {
                        if (it->name == name && it->quantity >= quantity) {
                            productFound = true;
                            WholesaleClient* wholesaleClient = new WholesaleClient();
                            wholesaleClient->buy(*it, quantity, *warehouse2, *store2);
                            delete wholesaleClient;
                            it->quantity -= quantity;
                            if (it->quantity == 0) {
                                warehouse2->products.erase(it);
                            }
                            break;
                        }
                    }
                }
            }
            // товар не нашелся
            if (!productFound) {
                cout << "Product not found or insufficient quantity available." << endl;
            }
        }
        // выход
        case 0:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    }

    // освобождаем память
    delete org;
    delete warehouse1;
    delete warehouse2;
    delete store1;
    delete store2;

    delete supplier;
    delete truck;

    return 0;
}
