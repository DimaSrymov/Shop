#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Product {
    string name;
    double price;
};

const vector<Product> storeProducts = {
    {"Bread", 25.50},
    {"Milk", 32.00},
    {"Eggs (10 pcs)", 45.00},
    {"Cheese", 120.00},
    {"Apples", 30.00}
};

void showinfo() {
    cout << "\n=== Available Products ===" << endl;
    for (size_t i = 0; i < storeProducts.size(); ++i) {
        cout << i + 1 << ". " << storeProducts[i].name
            << " - " << storeProducts[i].price << " UAH" << endl;
    }
    cout << "0. Finish shopping and get receipt" << endl;
    cout << "==========================" << endl;
}


void saveJsonReceipt(const vector<Product>& cart, double discount) {
    json receiptJson;
    double total = 0;

    for (const auto& item : cart) {
        receiptJson["items"].push_back({ {"name", item.name}, {"price", item.price} });
        total += item.price;
    }

    double discountAmount = total * (discount / 100.0);
    double finalTotal = total - discountAmount;

    receiptJson["subtotal"] = total;
    receiptJson["discount_percentage"] = discount;
    receiptJson["discount_amount"] = discountAmount;
    receiptJson["total_to_pay"] = finalTotal;

    ofstream file("receipt.json");
    if (file.is_open()) {
        file << receiptJson.dump(4);
        file.close();
        cout << "- Receipt saved to receipt.json" << endl;
    }
}


void saveTxtReceipt(const vector<Product>& cart, double discount) {
    ofstream file("Text.txt");
    if (file.is_open()) {
        double total = 0;
        file << "---------- SHOP RECEIPT ----------\n";
        for (size_t i = 0; i < cart.size(); ++i) {
            file << i + 1 << ". " << cart[i].name << " : "
                << cart[i].price << " UAH\n";
            total += cart[i].price;
        }

        double discountAmount = total * (discount / 100.0);
        double finalTotal = total - discountAmount;

        file << "----------------------------------\n";
        file << "Subtotal: " << total << " UAH\n";

        if (discount > 0) {
            file << "Discount (" << discount << "%): -" << discountAmount << " UAH\n";
        }

        file << "TOTAL TO PAY: " << finalTotal << " UAH\n";
        file << "Thank you for your purchase!";
        file.close();
        cout << "- Receipt saved to Text.txt" << endl;
    }
    else {
        cout << "Error opening Text.txt!" << endl;
    }
}
