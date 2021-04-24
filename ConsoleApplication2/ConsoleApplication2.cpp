#include<iostream>
#include<Windows.h>

using namespace std;


#define MAX 5

template<typename T>
class Stack {
private:
	T items[MAX];
	int top;
public:
	Stack() { top = -1; }
	bool push(T item) {
		if (top >= (MAX - 1)) {
			cout << "Stack overflow!";
			return false;
		}
		else {
			++top;
			items[top] = item;
			return true;
		}
	}
	T pop() {
		if (top < 0) {
			cout << "Stack is underflow!" << endl;
		}
		else {
			return items[top--];
		}
	}

	bool isEmpty() const { return top < 0; }
	bool isFull() const { return top == (MAX - 1); }
};



class Product {
public:
	int id = 0;
	string name = "No Name";
	Product() = default;
	Product(const int& id, const string& name) : id(id), name(name) {}

	void ShowProduct() {
		cout << "\nId --> " << this->id << endl;
		cout << "Name --> " << this->name << endl;
	}
};


class Wagon {
public:
	int no = 0;
	Stack<Product> products;

	Wagon() = default;
	Wagon(const int& no, Stack<Product> products) {
		this->no = no;
		this->products = products;
	}

	Wagon(const Wagon& other) {
		no = other.no;
		products = other.products;
	}

	Wagon& operator=(const Wagon& other) {
		no = other.no;
		products = other.products;
		return *this;
	}


	void ShowProduct() {
		Stack<Product> temp = products;


		cout << "\n=======================" << endl;
		cout << "Wagon No -->" << no << endl;
		while (!temp.isEmpty())
		{
			temp.pop().ShowProduct();
		}
	}
};



template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;

	Node(const T& data) {
		this->data = data;
	}
};


template<typename T>
class DoubleLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	DoubleLinkedList() :head(), tail() {}

	void forwardTravers()const {
		auto temp = head;
		while (temp != nullptr) {
			temp->data.ShowProduct();
			temp = temp->next;
		}cout << endl;
	}
	void backwardTravers()const {
		auto temp = tail;
		while (temp != nullptr) {
			temp->Data.ShowProduct();
			temp = temp->prev;
		}cout << endl;

	}

	void addEnd(const T& data) {
		auto newTrain = new Node<T>(data);
		if (head == NULL)
		{
			head = newTrain;
			tail = newTrain;
			return;
		}

		tail->next = newTrain;
		newTrain->next = nullptr;
		newTrain->prev = tail;
		tail = newTrain;
	}
};



class Train {
public:
	string name;
	DoubleLinkedList<Wagon> wagons;

	Train(const string& name) : name(name) {}

	void Print() {
		wagons.forwardTravers();
	}
};



int main() {
	// Product
	//        id 
	//             Ad 

	Product p1(1, "Samsung");
	Product p2(2, "BMW");
	Product p3(3, "HyperX-Cloud");
	Product p4(4, "Coca-Cola");
	Product p5(5, "Nvidia");
	Product p6(6, "Intel");
	Product p7(7, "Xiaomi");
	Product p8(8, "Bloody");
	Product p9(9, "Genius");


	Stack<Product> s1;
	s1.push(p1);
	s1.push(p2);
	s1.push(p3);

	Stack<Product> s2;
	s2.push(p4);
	s2.push(p5);
	s2.push(p6);

	Stack<Product> s3;
	s3.push(p7);

	Stack<Product> s4;
	s4.push(p8);
	s4.push(p9);


	Wagon w1(1, s1);
	Wagon w2(2, s2);
	Wagon w3(3, s3);
	Wagon w4(4, s4);


	Train train("Hakuna Train");
	train.wagons.addEnd(w1);
	train.wagons.addEnd(w2);
	train.wagons.addEnd(w3);
	train.wagons.addEnd(w4);

	train.Print();


	return 0;
}