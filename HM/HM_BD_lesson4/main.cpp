#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>

class ClientDB {
public:
	ClientDB() {
		pqxx::transaction tran{conn};
		tran.exec("CREATE TABLE IF NOT EXISTS client( "
			"id serial NOT NULL PRIMARY KEY, "
			"Name text NOT NULL, "
			"Second_name text NOT NULL, "
			"Email text NOT NULL "
			");");

		tran.exec("CREATE TABLE IF NOT EXISTS Phone_number( "
			"id serial NOT NULL , "
			"id_Client INTEGER REFERENCES client(id) , "
			"Phone INTEGER UNIQUE "
			");");
		tran.commit();
		std::cout << "Create OK\n";
	};

	void add_client(std::string name, std::string second_name, std::string email) {
		pqxx::transaction tran{ conn };
		tran.exec("INSERT INTO client "
			"(Name, Second_name, Email)"
			"VALUES('" + tran.esc(name) + "', '" + tran.esc(second_name) + "', '" + tran.esc(email) + "'); ");
		tran.commit();
		std::cout << "ADD client OK\n";
	};

	void update_client(int id, std::string email) {
		pqxx::transaction tran{ conn };
		tran.exec("UPDATE client "
			"SET email = '" + tran.esc(email)  + 
			"' WHERE id = " + std::to_string(id) );
			
		tran.commit();
		std::cout << "UPDATE client OK\n";
	};

	void delete_client(int id) {
		pqxx::transaction tran{ conn };
		tran.exec("DELETE FROM client "
			"WHERE id = " + std::to_string(id) );
		tran.commit();
		std::cout << "DELETE client OK\n";
	};
		
	void add_phone(int id_Client, int phone) {
		pqxx::transaction tran{ conn };
		tran.exec("INSERT INTO Phone_number "
			"(id_Client, Phone)"
			"VALUES(" + tran.esc(std::to_string(id_Client)) + ", " + tran.esc(std::to_string(phone)) + "); ");
		tran.commit();
		std::cout << "ADD Phone OK\n";
	};

	void delete_phone(int id) {
		pqxx::transaction tran{ conn };
		tran.exec("DELETE FROM Phone_number "
			"WHERE id = " + std::to_string(id));
		tran.commit();
		std::cout << "DELETE phone OK\n";
	};

	void find() {
		pqxx::transaction tran{ conn };
		auto result = tran.exec("SELECT  c.Name, c.Second_name, p.Phone  FROM client c "
			"LEFT JOIN Phone_number p ON c.id = p.id_client "
			"WHERE p.id_client = c.id "
			"GROUP BY c.Name, c.Second_name, p.Phone");
		
		for (auto [Name, Second_name, Phone] : tran.query<std::string, std::string, int>(
			"SELECT  c.Name, c.Second_name, p.Phone  FROM client c "
			"LEFT JOIN Phone_number p ON c.id = p.id_client "
			"WHERE p.id_client = c.id "
			"GROUP BY c.Name, c.Second_name, p.Phone"))
		{
			std::cout << Name << " " << Second_name << " " << Phone << ".\n";
		}

	};

private:
	pqxx::connection conn{ "host=localhost " //обязательно пробел
		"port=5432 " //стандартный порт psql
		"dbname=Client " //своё имя базы
		"user=postgres " //своё имя пользователя
		"password=Asdfghjkl_123 " };    //свой пароль
	
};




int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setlocale(LC_ALL, "Rus");
	try
	{
		std::cout << "HW" << std::endl;
		ClientDB client;
		client.add_client("Ivan","Ivanov", "Ivan@mail.ru"); 
		client.add_client("Petr", "Petrov", "Petr@mail.ru"); 
		client.add_client("Alex", "Alexandrov", "Alex@mail.ru"); 
		client.add_phone(1, 34563456);
		client.add_phone(1, 65786578);
		client.add_phone(3, 5687098);
		client.add_phone(3, 847908);
		client.update_client(1, "Ivan123@mail.ru");
		client.delete_phone(3);
		client.delete_client(2);
		client.find();

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		int fd;
		std::cin >> fd;

}