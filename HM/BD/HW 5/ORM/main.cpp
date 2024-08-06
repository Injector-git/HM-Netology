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

		s.dropTables();
		s.createTables();



		Wt::Dbo::Transaction tran{ s };

		//PUBLISHER
		std::unique_ptr<Publisher> Joe = std::make_unique<Publisher>();
		Joe->name = "Joe";

		std::unique_ptr<Publisher> Roggan{ new Publisher() };
		Roggan->name = "Roggan";

		std::unique_ptr<Publisher> Itan{ new Publisher() };
		Itan->name = "Itan";

		Wt::Dbo::ptr<Publisher> Joe_Ptr = s.add<Publisher>(std::move(Joe));
		Wt::Dbo::ptr<Publisher> Roggan_Ptr = s.add(std::move(Roggan));
		Wt::Dbo::ptr<Publisher> Itan_Ptr = s.add(std::move(Itan));


		//BOOK
		Wt::Dbo::ptr<Book> book1_ptr = s.add(std::unique_ptr<Book>{new Book{ "Alphabet" }, });
		Joe_Ptr.modify()->book.insert(book1_ptr); // or book_ptr.modify()->pub = Joe_Ptr;
		
		Wt::Dbo::ptr<Book> book2_ptr = s.add(std::unique_ptr<Book>{new Book{ "Knives" }, });
		Joe_Ptr.modify()->book.insert(book2_ptr);

		Wt::Dbo::ptr<Book> book3_ptr = s.add(std::unique_ptr<Book>{new Book{ "Thumbelina" }, });
		Roggan_Ptr.modify()->book.insert(book3_ptr);

		Wt::Dbo::ptr<Book> book4_ptr = s.add(std::unique_ptr<Book>{new Book{ "1984" }, });
		Itan_Ptr.modify()->book.insert(book4_ptr);


		//SHOP
		std::unique_ptr<Shop> shop1 = std::make_unique<Shop>();
		shop1->name = "shop1";

		std::unique_ptr<Shop> shop2 = std::make_unique<Shop>();
		shop2->name = "shop2";

		std::unique_ptr<Shop> shop3 = std::make_unique<Shop>();
		shop3->name = "shop3";

		Wt::Dbo::ptr<Shop> shop1_Ptr = s.add(std::move(shop1));
		Wt::Dbo::ptr<Shop> shop2_Ptr = s.add(std::move(shop2));
		Wt::Dbo::ptr<Shop> shop3_Ptr = s.add(std::move(shop3));


		//STOCK
		Wt::Dbo::ptr<Stock> stock1_ptr = s.add(std::unique_ptr<Stock>{new Stock{ 3 }, });
		book1_ptr.modify()->stock.insert(stock1_ptr);
		shop1_Ptr.modify()->stock.insert(stock1_ptr);

		Wt::Dbo::ptr<Stock> stock2_ptr = s.add(std::unique_ptr<Stock>{new Stock{ 6 }, });
		book1_ptr.modify()->stock.insert(stock2_ptr);
		shop2_Ptr.modify()->stock.insert(stock2_ptr);

		Wt::Dbo::ptr<Stock> stock3_ptr = s.add(std::unique_ptr<Stock>{new Stock{ 1 }, });
		book2_ptr.modify()->stock.insert(stock3_ptr);
		shop2_Ptr.modify()->stock.insert(stock3_ptr);

		Wt::Dbo::ptr<Stock> stock4_ptr = s.add(std::unique_ptr<Stock>{new Stock{ 6 }, });
		book3_ptr.modify()->stock.insert(stock4_ptr);
		shop3_Ptr.modify()->stock.insert(stock4_ptr);

		Wt::Dbo::ptr<Stock> stock5_ptr = s.add(std::unique_ptr<Stock>{new Stock{ 2 }, });
		book4_ptr.modify()->stock.insert(stock5_ptr);
		shop3_Ptr.modify()->stock.insert(stock5_ptr);

		//Запрос
		std::string autor;
		std::cout << "Введите издателя: ";
		std::cin >> autor;
		std::cout << std::endl;


		tran.commit();

		Wt::Dbo::Transaction tran2{ s };

		Wt::Dbo::ptr<Publisher> deal_publisher = s.find<Publisher>().where("name = ?").bind(autor);

		Wt::Dbo::ptr<Book> id_book = s.find<Book>().where("Publisher_id = " + std::to_string(deal_publisher.id()));

		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> request = s.find<Stock>().where("Book_id = " + std::to_string(id_book.id()));

		for (Wt::Dbo::ptr<Stock> r : request) {
			std::cout << r->shop << " ";
		}

		tran2.commit();

	}

	catch (const std::exception& e) {
		(std::cout << "Error: " << e.what());
	}
}