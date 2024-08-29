#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <vector>

struct query {
	std::vector<std::string> column;
	std::vector<std::string> where;
	std::string table;
};

class SqlSelectQueryBuilder
{
public:

	SqlSelectQueryBuilder() {
		try {

			std::string connString =
				"host=localhost "
				"port=5432 "
				"dbname=Book_shop "
				"user=postgres "
				"password=Asdfghjkl_123 ";

			auto connection = std::make_unique<Wt::Dbo::backend::Postgres>(connString);

			s.setConnection(move(connection));

		}

		catch (const std::exception& e) {
			(std::cout << "Error: " << e.what());
		}
	}

	SqlSelectQueryBuilder& AddColumn(std::string name) {
		Query.column.push_back(name);
		return *this;
	}

	SqlSelectQueryBuilder& AddFrom(std::string name) {
		Query.table = name;
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(std::string name, std::string value) {
		Query.where.push_back(name);
		Query.where.push_back(value);
		return *this;
	}

	void BuildQuery() {
		Wt::Dbo::Transaction tran{ s };
		if (Query.column.empty()) {
		//	auto an = s.find<Query.table>().where( Query.where.pop_back() + " = ? ").bind(Query.where.pop_back());
		}
		else {
			//	auto an = s.find<Query.table>().where( Query.where.pop_back() + " = ? ").bind(Query.where.pop_back());
		}

		tran.commit();
	}
private:
	Wt::Dbo::Session s;
	query Query;
};

	
int main()
{
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");

	static_assert(query_builder.BuildQuery(),
		"SELECT name, phone FROM students WHERE id=42 AND name=John;");
}
