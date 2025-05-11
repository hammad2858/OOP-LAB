#include<iostream>
#include<exception>
#include<string>
using namespace std;

class DatabaseException:public exception{
    public:
    char* what() noexcept {
        return "A database error occured";
    }
};

class ConnectionFailedException : public DatabaseException{};
class QuerytimeoutException : public DatabaseException{};

template<typename T>
class DatabaseConnector{
    private:
    T dbname;
    public:
    DatabaseConnector(T name):dbname(name){}
    void connect(){
        if(dbname=="Invaild _ DB"){
            throw ConnectionFailedException();
        }
        cout<<"Connected to "<<dbname<<"Succesfully"<<endl;
    }
void query(string sql){
    if(dbname == "slow_db"){
    throw QuerytimeoutException();
}
cout <<"Executed Query"<<sql<<endl;
}

};

int main(){
    try {
        cout<<"Attempting to connect to invalid db";
        DatabaseConnector<string>db1("Invalid DB");
        db1.connect();

    }
    catch(ConnectionFailedException e){
        cout<<"Caught connection failed exception"<<endl;
        cout<<"What () : "<<e.what()<<endl;
    }
    try {
        cout<<"Attempt to connect to slow DB"<<endl;
        DatabaseConnector<string>db2("slow DB");
        db2.connect();
        db2.query("Select * from FROm users");

    }

    catch (QuerytimeoutException e){
        cout<<"Caiught a database execption"<<endl;
        cout<<"What () :"<<e.what()<<endl;
    }
}


