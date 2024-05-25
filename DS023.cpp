#include <iostream>
#include <iomanip>
using namespace std;

class Product {
private:
    string name;
    double price;
    double discount;
    string manufacturer;
    double size;

public:
    // 생성자
    Product(string n, double p, double d, string m, double s) {
        name = n;
        price = p;
        discount = d;
        manufacturer = m;
        size = s;
    }

    // 상품 정보를 입력받는 메소드
    void setProduct(string n, double p, double d, string m, double s) {
        name = n;
        price = p;
        discount = d;
        manufacturer = m;
        size = s;
    }

    // 상품 정보를 출력하는 메소드
    void displayProduct() {
        double discountedPrice = calculateDiscountedPrice();
        cout << setw(10) << discountedPrice << " (" << setw(3) << discount << "%) " 
             << setw(20) << name << setw(10) << size << "g " << setw(10) << manufacturer << endl;
    }

    // 할인된 가격을 계산하는 메소드
    double calculateDiscountedPrice() {
        return price * (1 - discount / 100);
    }
};

// 상품을 관리하는 배열 및 개수를 다루는 전역 변수
Product* products[100];
int productCount = 0;

// 상품을 추가하는 함수
void addProduct(string name, double price, double discount, string manufacturer, double size) {
    products[productCount] = new Product(name, price, discount, manufacturer, size);
    productCount++;
}

// 모든 상품을 출력하는 함수
void displayAllProducts() {
    for (int i = 0; i < productCount; i++) {
        products[i]->displayProduct();
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add  2. List  3. Quit > ";
        cin >> choice;
        cin.ignore(); // 버퍼 비우기
        
        if (choice == 1) {
            string name, manufacturer;
            double price, discount, size;
            
            cout << "상품명: ";
            getline(cin, name);
            cout << "가격: ";
            cin >> price;
            cout << "할인율: ";
            cin >> discount;
            cout << "크기: ";
            cin >> size;
            cin.ignore(); // 버퍼 비우기
            cout << "제조사: ";
            cin >> manufacturer;
            
            addProduct(name, price, discount, manufacturer, size);
        } else if (choice == 2) {
            displayAllProducts();
        }
    } while (choice != 3);

    // 동적 할당한 메모리를 해제
    for (int i = 0; i < productCount; i++) {
        delete products[i];
    }

    return 0;
}
