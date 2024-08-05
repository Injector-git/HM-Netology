#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <string>
#include <Windows.h>

class Publisher;
class Book;
class Stock;
class Shop;
class Sale;

class Publisher {
public:
	std::string name;
	Wt::Dbo::collection< Wt::Dbo::ptr <Book> > book;

	template<typename T>
	void persist(T& pub) {

		Wt::Dbo::hasMany(pub, book, Wt::Dbo::ManyToOne, "Publisher");
		Wt::Dbo::field(pub, name, "name");

	}
};

class Book {public:
	std::string title;
	Wt::Dbo::ptr<Publisher> pub;
	Wt::Dbo::collection< Wt::Dbo::ptr <Stock> > stock;


	template<typename T>
	void persist(T& book) {

		Wt::Dbo::belongsTo(book, pub, "Publisher");
		Wt::Dbo::hasMany(book, stock, Wt::Dbo::ManyToOne, "Book");
		Wt::Dbo::field(book, title, "title");

	}
};

class Stock {
public:
	int count;
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;
	Wt::Dbo::collection< Wt::Dbo::ptr <Sale> > sale;


	template<typename T>
	void persist(T& stock) {

		Wt::Dbo::belongsTo(stock, book, "Book");
		Wt::Dbo::belongsTo(stock, shop, "Shop");
		Wt::Dbo::hasMany(stock, sale, Wt::Dbo::ManyToOne, "Stock");
		Wt::Dbo::field(stock, count, "count");
	}
};

class Shop {
public:
	std::string name;
	Wt::Dbo::collection< Wt::Dbo::ptr <Stock> > stock;

	template<typename T>
	void persist(T& shop) {

		Wt::Dbo::hasMany(shop, stock, Wt::Dbo::ManyToOne, "Shop");
		Wt::Dbo::field(shop, name, "name");
	}
};

class Sale {
public:
	int price;
	std::string date_sale;
	int count;
	Wt::Dbo::ptr<Stock> stock;

	template<typename T>
	void persist(T& sale) {

		Wt::Dbo::belongsTo(sale, stock, "Stock");
		Wt::Dbo::field(sale, price, "price");
		Wt::Dbo::field(sale, date_sale, "date_sale");
		Wt::Dbo::field(sale, count, "count");
	}
};

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setlocale(LC_ALL, "Rus");

	std::cout << "HW" << std::endl;
	try {
		std::string connString =
			"host=localhost " //обязательно пробел
			"port=5432 " //стандартный порт psql
			"dbname=Book_shop " //своё имя базы
			"user=postgres " //своё имя пользователя
			"password=Asdfghjkl_123 ";  //свой пароль  
		
		auto connection = std::make_unique<Wt::Dbo::backend::Postgres>(connString);

		Wt::Dbo::Session s;

		s.setConnection(move(connection));



		s.mapClass<Publisher>("Publisher");
		s.mapClass<Book>("Book");
		s.mapClass<Stock>("Stock");
		s.mapClass<Shop>("Shop");
		s.mapClass<Sale>("Sale");

		//s.dropTables();
		s.createTables();

		Wt::Dbo::Transaction tran{ s };

		tran.commit();
		
	}
	catch (const std::exception& e) {
		(std::cout << "Error: " << e.what());
	}
}