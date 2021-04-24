#include<iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 5

//-----------------------------

class Engine
{
public:
	Engine() : volume() {}
	Engine(const string eng_no, const string comp, const double volume)
		: Engine()
	{
		SetEngineNo(eng_no);
		SetCompany(comp);
		SetVolume(volume);
	}
	Engine(const Engine& other)
	{
		SetEngineNo(other.engine_no);
		SetCompany(other.company);
		SetVolume(other.volume);
	}
	Engine(Engine&& other) noexcept
	{
		engine_no = other.engine_no;
		company = other.company;
		volume = other.volume;

		other.engine_no = "";
		other.company = "";
		other.volume = NULL;
	}
	Engine& operator = (const Engine& other)
	{
		SetEngineNo(other.engine_no);
		SetCompany(other.company);
		SetVolume(other.volume);
		return *this;
	}
	Engine& operator = (Engine&& other) noexcept
	{
		engine_no = other.engine_no;
		company = other.company;
		volume = other.volume;

		other.engine_no = "";
		other.company = "";
		other.volume = NULL;
		return *this;
	}
	~Engine()
	{
		/*.!.*/
	}
	void SetEngineNo(const string eng_no) { engine_no = eng_no; }
	void SetCompany(const string comp) { company = comp; }
	void SetVolume(const double vol) { volume = vol; }

	string GetEngineNo() const { return engine_no; }
	string GetCompany() const { return company; }
	double GetVolume() const { return volume; }

	string engine_no;
	string company;
	double volume;
};


template<typename T>
class Stack {
private:
	T items[MAX];
	int top;
	T tmp[1];
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
			return tmp[0];
		}
		else return items[top--];
	}

	T peek() {
		if (top < 0) {
			cout << "Stack is Empty!" << endl;
			return tmp[0];
		}
		else {
			return items[top];
		}
	}

	bool isEmpty() const { return top < 0; }
	bool isFull() const { return top == (MAX - 1); }
};

class Transports ///// Nəqliyyat Vasitələri /////
{
public:
protected:
	Transports() : id() {}
	size_t id;
	string name;
	string model;
	string vendor;

	size_t GetID() const { return id; }
	string GetName() const { return name; }
	string GetModel() const { return model; }
	string GetVendor() const { return vendor; }

	void SetID(const size_t id) { this->id = id; }
	void SetName(const string name) { this->name = name; }
	void SetModel(const string model) { this->model = model; }
	void SetVendor(const string vendor) { this->vendor = vendor; }

	virtual void EngineFoo() {}

	friend ostream& operator<<(ostream& out, Transports& spec);
};

ostream& operator<<(ostream& out, Transports& spec)
{
	out << "Transport name: " << spec.name << endl;
	out << "ID: " << spec.id << endl;
	out << "Model: " << spec.model << endl;
	out << "Vendor: " << spec.vendor << endl;
	spec.EngineFoo();
	return out;
}


//-----------------------------
class AirTransport : public Transports ///// Hava nəqliyyat vasitələri /////
{
protected:
	AirTransport() { name = "AirTransport"; }
};
//-----------------------------
class RoadTransport : public Transports ///// Avtomobil nəqliyyat vasitələri /////
{
protected:
	RoadTransport() { name = "RoadTransport"; }
};
//-----------------------------
class RailTransport : public Transports ///// Dəmiryol nəqliyyat vasitələri /////
{
protected:
	RailTransport() { name = "RailTransport"; }
};
//-----------------------------
class SeaTransport : public Transports ///// Dəniz nəqliyyat vasitələri /////
{
protected:
	SeaTransport() { name = "SeaTransport"; }
};

//-----------------------------
class Motorbike : public RoadTransport
{
public:
	Motorbike() : nitro(false) {};
	Motorbike(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Motorbike()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Motorbike(const Motorbike& other) : Motorbike()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Motorbike(Motorbike&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Motorbike& operator = (const Motorbike& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Motorbike& operator = (Motorbike&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Motorbike()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << nitro << endl;
	}
protected:
private:
	bool nitro;
	Engine engine;
};

class Car : public RoadTransport
{
public:
	Car() : hasSpoiler(true) {};
	Car(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Car()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Car(const Car& other) : Car()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Car(Car&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Car& operator = (const Car& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Car& operator = (Car&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Car()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << hasSpoiler << endl;
	}
protected:
private:
	bool hasSpoiler;
	Engine engine;
};

class Bus : public RoadTransport
{
public:
	Bus() : vinyl(true) {};
	Bus(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Bus()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Bus(const Bus& other) : Bus()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Bus(Bus&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Bus& operator = (const Bus& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Bus& operator = (Bus&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Bus()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << vinyl << endl;
	}
protected:
private:
	bool vinyl;
	Engine engine;
};
//-----------------------------

class PassengerTrain : public RailTransport
{
public:
	PassengerTrain() : vinyl(true) {};
	PassengerTrain(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : PassengerTrain()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	PassengerTrain(const PassengerTrain& other) : PassengerTrain()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	PassengerTrain(PassengerTrain&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	PassengerTrain& operator = (const PassengerTrain& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	PassengerTrain& operator = (PassengerTrain&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~PassengerTrain()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << vinyl << endl;
	}
protected:
private:
	bool vinyl;
	Engine engine;
};

class Tram : public RailTransport
{
public:
	Tram() : vinyl(true) {};
	Tram(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Tram()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Tram(const Tram& other) : Tram()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Tram(Tram&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Tram& operator = (const Tram& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Tram& operator = (Tram&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Tram()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << vinyl << endl;
	}
protected:
private:
	bool vinyl;
	Engine engine;
};

class Underground : public RailTransport
{
public:
	Underground() : vinyl(true) {};
	Underground(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Underground()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Underground(const Underground& other) : Underground()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Underground(Underground&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Underground& operator = (const Underground& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Underground& operator = (Underground&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Underground()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << vinyl << endl;
	}
protected:
private:
	bool vinyl;
	Engine engine;
};

//-----------------------------

class Ship : public SeaTransport
{
public:
	Ship() : navy(true) {};
	Ship(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Ship()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Ship(const Ship& other) : Ship()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Ship(Ship&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Ship& operator = (const Ship& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Ship& operator = (Ship&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Ship()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << navy << endl;
	}
protected:
private:
	bool navy;
	Engine engine;
};

class Yacht : public SeaTransport
{
public:
	Yacht() : passenger(true) {};
	Yacht(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Yacht()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Yacht(const Yacht& other) : Yacht()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Yacht(Yacht&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Yacht& operator = (const Yacht& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Yacht& operator = (Yacht&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Yacht()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << passenger << endl;
	}
protected:
private:
	bool passenger;
	Engine engine;
};

class JetSki : public SeaTransport
{
public:
	JetSki() : fast(true) {};
	JetSki(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : JetSki()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	JetSki(const JetSki& other) : JetSki()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	JetSki(JetSki&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	JetSki& operator = (const JetSki& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	JetSki& operator = (JetSki&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~JetSki()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << fast << endl;
	}
protected:
private:
	bool fast;
	Engine engine;
};
//-----------------------------
class Aeroplane : public AirTransport
{
public:
	Aeroplane() : passenger(true) {};
	Aeroplane(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Aeroplane()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Aeroplane(const Aeroplane& other) : Aeroplane()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Aeroplane(Aeroplane&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Aeroplane& operator = (const Aeroplane& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Aeroplane& operator = (Aeroplane&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Aeroplane()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << passenger << endl;
	}
protected:
private:
	bool passenger;
	Engine engine;
};

class Helicopter : public AirTransport
{
public:
	Helicopter() : passenger(true) {};
	Helicopter(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Helicopter()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Helicopter(const Helicopter& other) : Helicopter()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Helicopter(Helicopter&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Helicopter& operator = (const Helicopter& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Helicopter& operator = (Helicopter&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Helicopter()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << passenger << endl;
	}
protected:
private:
	bool passenger;
	Engine engine;
};

class Jet : public AirTransport
{
public:
	Jet() : war(true) {};
	Jet(const size_t id, const string model, const string vendor,
		const string comp, const string eng_no, const double volume) : Jet()
	{
		SetID(id);
		SetModel(model);
		SetVendor(vendor);
		engine.SetCompany(comp);
		engine.SetEngineNo(eng_no);
		engine.SetVolume(volume);
	}
	Jet(const Jet& other) : Jet()
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
	}
	Jet(Jet&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
	}
	Jet& operator = (const Jet& other)
	{
		SetID(other.id);
		SetModel(other.model);
		SetVendor(other.vendor);
		engine.SetCompany(other.engine.company);
		engine.SetEngineNo(other.engine.engine_no);
		engine.SetVolume(other.engine.volume);
		return *this;
	}
	Jet& operator = (Jet&& other) noexcept
	{
		id = other.id;
		model = other.model;
		vendor = other.vendor;
		engine.company = other.engine.company;
		engine.engine_no = other.engine.engine_no;
		engine.volume = other.engine.volume;

		other.id = NULL;
		other.model = "";
		other.vendor = "";
		other.engine.company = "";
		other.engine.engine_no = "";
		other.engine.volume = NULL;
		return *this;
	}
	~Jet()
	{
		/*.!.*/
	}
	void EngineFoo() override
	{
		cout << "Engine company: " << engine.company << endl;
		cout << "Engine number: " << engine.engine_no << endl;
		cout << "Engine value: " << engine.volume << endl;
		cout << "Nitro: " << boolalpha << war << endl;
	}
protected:
private:
	bool war;
	Engine engine;
};


class TransportsDepo
{
public:
	Stack<Car> cars;

	Stack<Motorbike> motorbikes;
	Stack<Bus> buses;

	Stack<PassengerTrain> traines;
	Stack<Tram> trams;
	Stack<Underground> undergrounds;

	Stack<Ship> ships;
	Stack<Yacht> yachts;
	Stack<JetSki> jetSkies;

	Stack<Aeroplane> aeroplanes;
	Stack<Helicopter> helicopters;
	Stack<Jet> jets;

	void ShowAllTransports()
	{
		while (!jets.isEmpty())
		{
			auto list = jets.peek();
			cout << list << endl;
			jets.pop();
		}

		while (!helicopters.isEmpty())
		{
			auto list = helicopters.peek();
			cout << list << endl;
			helicopters.pop();
		}

		while (!aeroplanes.isEmpty())
		{
			auto list = aeroplanes.peek();
			cout << list << endl;
			aeroplanes.pop();
		}

		while (!jetSkies.isEmpty())
		{
			auto list = jetSkies.peek();
			cout << list << endl;
			jetSkies.pop();
		}

		while (!yachts.isEmpty())
		{
			auto list = yachts.peek();
			cout << list << endl;
			yachts.pop();
		}

		while (!ships.isEmpty())
		{
			auto list = ships.peek();
			cout << list << endl;
			ships.pop();
		}

		while (!undergrounds.isEmpty())
		{
			auto list = undergrounds.peek();
			cout << list << endl;
			undergrounds.pop();
		}

		while (!trams.isEmpty())
		{
			auto list = trams.peek();
			cout << list << endl;
			trams.pop();
		}

		while (!traines.isEmpty())
		{
			auto list = traines.peek();
			cout << list << endl;
			traines.pop();
		}

		while (!buses.isEmpty())
		{
			auto list = buses.peek();
			cout << list << endl;
			buses.pop();
		}

		while (!motorbikes.isEmpty())
		{
			auto list = motorbikes.peek();
			cout << list << endl;
			motorbikes.pop();
		}

		while (!cars.isEmpty())
		{
			auto list = cars.peek();
			cout << list << endl;
			cars.pop();
		}
	}
};


int main()
{
	Car car1(1, "BMW", "Germany", "Alphina", "TRF128765", 4.4); 
	Car car2(2, "Mercedes", "Germany", "AMG", "Tr3a4y5k6a8cDD", 6.3);

	Motorbike moto1(3, "SUZUKI", "Japan", "Jatunsi", "JKR12345678", 2.3);
	Motorbike moto2(4, "Ducati", "Korean", "Suansiac", "TRAYS8D45G", 1.6);

	Bus bus1(5, "MAN", "Germany", "Zeprus", "JKR12345678", 3.0);
	Bus bus2(6, "ISUZU", "Korean", "", "Tr3a4y5k6a8cDD", 3.2);

	PassengerTrain train1(7, "Flash", "Japan", "Festival", "TRF128765", 3.0);
	PassengerTrain train2(8, "Medium", "Turkey", "Kashalot", "TRAYS8D45G", 3.0);

	Tram tram1(9, "Trius", "Czech", "Andragon", "Tr3a4y5k6a8cDD", 3.0);
	Tram tram2(10, "Archangelsk", "Russian", "Afrestintiy", "TRF128765", 3.0);

	Underground metro1(11, "Sahil", "Azerbaijan", "GedOppan", "JKR12345678", 3.0);
	Underground metro2(12, "Metro2033", "Russian", "Alfabrit", "TRAYS8D45G", 3.0);

	Ship ship1(13, "Zamil FT", "Arabian", "Ye koglan", "Tr3a4y5k6a8cDD", 3.0);
	Ship ship2(14, "Gilavar", "Azerbaijan", "Eclaf", "TRF128765", 3.0);

	Yacht yacht1(15, "Miami", "USA", "Gic beser", "JKR12345678", 3.0);
	Yacht yacht2(16, "Star", "Canada", "Gic vijdansiz", "Tr3a4y5k6a8cDD", 3.0);

	JetSki scooter1(17, "JumpTrax", "Cina", "Elcekakiwi", "Tr3a4y5k6a8cDD", 3.0);
	JetSki scooter2(18, "TraxStar", "USA", "Gedi sinle mesgulol", "TRAYS8D45G", 3.0);

	Aeroplane aeroplane1(19, "Hogan", "USA", "Ne sirtiq adamsan", "JKR12345678", 3.0);
	Aeroplane aeroplane2(20, "Gemini", "Canada", "Sifet vare sende", "TRF128765", 3.0);

	Helicopter helicopter1(21, "Revvel", "Japan", "Eclaf MMC", "JKR12345678", 3.0);
	Helicopter helicopter2(22, "Kits", "Russian", "Etaga yoruldum", "TRAYS8D45G", 3.0);

	Jet jet1(23, "SU21", "Russian", "Uje", "Tr3a4y5k6a8cDD", 3.0);
	Jet jet2(24, "Gigantic", "USA", "Qaqa canii", "JKR12345678", 3.0);


	TransportsDepo obj;

	obj.cars.push(car1);
	obj.cars.push(car2);

	obj.motorbikes.push(moto1);
	obj.motorbikes.push(moto2);

	obj.buses.push(bus1);
	obj.buses.push(bus2);

	obj.traines.push(train1);
	obj.traines.push(train2);

	obj.trams.push(tram1);
	obj.trams.push(tram2);

	obj.undergrounds.push(metro1);
	obj.undergrounds.push(metro2);

	obj.ships.push(ship1);
	obj.ships.push(ship2);

	obj.yachts.push(yacht1);
	obj.yachts.push(yacht2);

	obj.jetSkies.push(scooter1);
	obj.jetSkies.push(scooter2);

	obj.aeroplanes.push(aeroplane1);
	obj.aeroplanes.push(aeroplane2);

	obj.helicopters.push(helicopter1);
	obj.helicopters.push(helicopter2);

	obj.jets.push(jet1);
	obj.jets.push(jet2);


	obj.ShowAllTransports();
}