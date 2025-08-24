#include <iostream>
using namespace std;

class Passport {
public:
    string surname;
    string name;
    string date_of_birth;
    string date_of_expiry;
    string sex;
    string nationality;
    int document_num;
    int record_num;

    Passport(string surname = "AlexAlex", string name = "Alex", string date_of_birth = "01.01.1974", string date_of_expiry = "01.01.2001", string sex = "M", 
        string nationality = "UKR", int document_num = 000000, int record_num = 000000) : surname(surname), name(name), date_of_birth(date_of_birth), date_of_expiry(date_of_expiry),
        sex(sex), nationality(nationality), document_num(document_num), record_num(record_num) {}

    void ShowPas() const {
        cout << surname << " " << name << " " << date_of_birth << " " << date_of_expiry << " " << sex << " " << nationality << " " << document_num << " " << record_num;
    }
};

class Visa{
public:
    string type;
    int visa_num;

    Visa(string type = "B1", int visa_num = 000000) : type(type), visa_num(visa_num) {}

    void Show() const {
        cout << type << " " << visa_num;
    }
};

class ForeignPassport : public Passport {
private:
    Visa visa;

public:
    ForeignPassport(string surname = "AlexAlex", string name = "Alex", string date_of_birth = "01.01.1974",
        string date_of_expiry = "01.01.2001", string sex = "M", string nationality = "UKR",
        int document_num = 0, int record_num = 0, Visa visa = Visa()) : Passport(surname, name, date_of_birth, date_of_expiry, sex, nationality, document_num, record_num), visa(visa) {}

    void Print() const {
        ShowPas();
        visa.Show();
    }
};

int main()
{
    Visa vis("B2", 000001);

    ForeignPassport pas;
    pas.Print();
}
