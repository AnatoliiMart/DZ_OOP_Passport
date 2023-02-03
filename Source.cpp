#include<iostream>
using namespace std;

class Passport
{
public:
	Passport() :name("No name"), homeAdress("No adress"), age(0) {}
	Passport(string Name, string HomeAdress, int Age) : name(Name), homeAdress(HomeAdress), age(Age)
	{
		name       = Name;
		homeAdress = HomeAdress;
		age        = Age;
	}
	~Passport() { cout << "Destruct Passport" << endl; }

protected:
	string name;
	int age;
	string homeAdress;
};
class ForeignPassport : public Passport
{
public:
	ForeignPassport() :visas(nullptr), passportNumber("No number"), VisaAmount(0), Passport() 
	{
		if (visas == nullptr)
		{
			cout << "No visas" << endl;
		}
	}
	ForeignPassport(string Name, string HomeAdress, size_t visaAmount, int Age, string PassportNumber) :Passport(Name, HomeAdress, Age)
	{
		passportNumber = PassportNumber;
		visas = new string[visaAmount];
		for (size_t i = 0; i < visaAmount; i++)
		{
			cout << "Enter what country visa you have: ";
			cin  >> visas[i];
		}
		VisaAmount = visaAmount;

	}
	void Output()
	{
		cout << "Name: "            << name       << endl;
		cout << "Home adress: "     << homeAdress << endl;
		cout << "Age: "             << age        << endl;
        cout << "Passport number: " << passportNumber << endl;

		for (size_t i = 0; i < VisaAmount; i++)
		{
			cout << "Visa " << i + 1 << ": " << visas[i] << endl;;
		}

	}

	~ForeignPassport() { delete[] visas; cout << "Destruct ForeignPassport" << endl; }

private:
	string* visas;
	string passportNumber;
	size_t VisaAmount;
};

int main()
{

	ForeignPassport obj("Anatolii", "Odesa", 2, 25, "111222333");
	obj.Output();
	cout << endl;
	cout << endl;
	ForeignPassport obj1;
	obj1.Output();
	cout << endl;
	cout << endl;
	return 0;
}


