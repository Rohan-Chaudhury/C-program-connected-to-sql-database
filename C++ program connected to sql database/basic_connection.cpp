
#include <iostream>
#include <string>
#include <mysql/mysql.h>
using namespace std;

int main () {
	string username, password, dbname,device_name,owner,device_type,time,query,device_price;
	MYSQL *connection (mysql_init (NULL));

	cout << "Enter mysql username: ";
	cin >> username;
	cout << "Enter mysql password: ";
	cin >> password;
	cout << "Enter Database Name: ";
	cin >> dbname;
cout << "Enter Device Name: ";
	cin >> device_name;
cout << "Enter owner Name: ";
	cin >> owner;
cout << "Enter device type: ";
	cin >> device_type;
cout << "Enter time: ";
	cin >> time;
cout << "Enter price: ";
	cin >> device_price;


	if (!connection) {
		cout << "Connection to the API failed" << endl;
		return (0);
	}

	connection = mysql_real_connect (connection, "localhost", username.c_str (), password.c_str (), dbname.c_str (), 0, NULL, 0);
	if (connection) { cout << "Connection successful" << endl; }
	else { cout << "Connection to Database Failed because your provided wrong Username/Password/Database Name." << endl; return (1); }

	
	mysql_query (connection, "CREATE TABLE IF NOT EXISTS DEVICE6000(device_no INT not null AUTO_INCREMENT,device_name VARCHAR(20),owner VARCHAR(15),device_type VARCHAR(10),time TIME(3),device_price FLOAT(8,5),PRIMARY KEY(device_no)); " );
	mysql_query (connection, "insert into DEVICE6000(device_name,owner,device_type,time,device_price) values ('asd','asdsa','asdsad','11:45:34',27.54);");
	query="insert into DEVICE6000(device_name,owner,device_type,time,device_price) values ('"+device_name+"','"+owner+"','"+device_type+"','"+time+"',"+device_price+");";
	mysql_query (connection, query.c_str());

	mysql_close (connection);
	return (0);
}
