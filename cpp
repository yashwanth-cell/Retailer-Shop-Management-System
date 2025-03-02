#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Product class to handle product information
class Product {
public:
    string name;
    float price;
    int quantity;

    Product(string productName, float productPrice, int productQuantity)
        : name(productName), price(productPrice), quantity(productQuantity) {}

    void displayProduct() {
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

// Customer class to manage customer information
class Customer {
public:
    string name;
    string address;
    string phone;

    Customer(string customerName, string customerAddress, string customerPhone)
        : name(customerName), address(customerAddress), phone(customerPhone) {}

    void displayCustomer() {
        cout << "Customer Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Sales class to handle sales transactions
class Sales {
public:
    void makeSale(vector<Product>& products) {
        string productName;
        int quantitySold;
        float totalAmount = 0.0f;
        bool productFound = false;

        cout << "Enter product name: ";
        cin >> productName;
        cout << "Enter quantity: ";
        cin >> quantitySold;

        // Find product and calculate sale
        for (auto& product : products) {
            if (product.name == productName && product.quantity >= quantitySold) {
                product.quantity -= quantitySold;  // Reduce quantity in stock
                totalAmount = quantitySold * product.price;
                cout << "Sale Successful!" << endl;
                cout << "Total Amount: " << fixed << setprecision(2) << totalAmount << endl;
                productFound = true;
                break;
            }
        }

        if (!productFound) {
            cout << "Product not found or insufficient stock!" << endl;
        }
    }
};

// Inventory class to manage products and stock
class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayProducts() {
        if (products.empty()) {
            cout << "No products available!" << endl;
            return;
        }
        cout << "List of Products: " << endl;
        for (const auto& product : products) {
            product.displayProduct();
            cout << "-------------------------" << endl;
        }
    }

    void updateProduct(string name, int quantity) {
        for (auto& product : products) {
            if (product.name == name) {
                product.quantity += quantity;
                cout << "Stock updated successfully!" << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }
};

// Main program to handle user interaction
int main() {
    Inventory inventory;
    Sales sales;
    int choice;
    
    while (true) {
        cout << "\nRetailer Shop Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Make a Sale\n";
        cout << "4. Update Product Stock\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                float price;
                int quantity;

                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;

                Product product(name, price, quantity);
                inventory.addProduct(product);
                cout << "Product added successfully!" << endl;
                break;
            }

            case 2:
                inventory.displayProducts();
                break;

            case 3:
                sales.makeSale(inventory.products);
                break;

            case 4: {
                string productName;
                int newQuantity;
                
                cout << "Enter product name to update stock: ";
                cin >> productName;
                cout << "Enter quantity to add: ";
                cin >> newQuantity;

                inventory.updateProduct(productName, newQuantity);
                break;
            }

            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
