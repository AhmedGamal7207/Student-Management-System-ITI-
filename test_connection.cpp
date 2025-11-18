#include <iostream>
#include <mysql/mysql.h>

#define host "127.0.0.1"
#define user "python_user"
#define password "Ahmedgamal619"
#define database "albums"
#define port 3306


using namespace std;

int main() {

    MYSQL* conn = mysql_init(nullptr);
    if (conn == nullptr) {
        cerr << "mysql_init() failed\n";
        return 1;
    }

    if (mysql_real_connect(conn, host, user, password, database,
                           port, nullptr, 0) == nullptr) {
        cerr << "mysql_real_connect() failed: "
                  << mysql_error(conn) << "\n";
        mysql_close(conn);
        return 1;
    }

    cout << "Connected to MySQL successfully!\n";

    const char* query = "SELECT artist_id, artist_first_name FROM artists";
    if (mysql_query(conn, query)) {
        cerr << "SELECT failed: " << mysql_error(conn) << "\n";
        mysql_close(conn);
        return 1;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (result == nullptr) {
        cerr << "mysql_store_result() failed: "
                  << mysql_error(conn) << "\n";
        mysql_close(conn);
        return 1;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    cout << "Query result:\n";
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; ++i) {
            cout << (row[i] ? row[i] : "NULL") << " ";
        }
        cout << "\n";
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}