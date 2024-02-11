#include <iostream>
#include <fstream>
#include <cstring>
#include <typeinfo>
#include <list>
#include <algorithm>
using namespace std;
const int MAX_PROPERTIES = 5;
list<string> propertyList;

class Person {
protected:
    std::string name;
    std::string egn;
    std::string address;

public:
    Person(const std::string &name, const std::string &egn, const std::string &address)
        : name(name), egn(egn), address(address) {}

    virtual ~Person() {}

    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Egn: " << egn << std::endl;
        std::cout << "Address: " << address << std::endl;
    }
    //ostream& operator<<(ostream& os,const Person& p) 
//{
//	std::cout << "Name: " << p->getName() << std::endl;
//    std::cout << "Egn: " << p->getEgn() << std::endl;
//	std::cout << "Address: " << p->getAddress() << std::endl;
//	}	
	
	const std::string& getName() const {
        return name;
    }
	const std::string& getEgn() const {
        return egn;
    }
    const std::string& getAddress() const {
        return address;
    }
};

class PropertyOwner : public Person {
private:
    char* properties[MAX_PROPERTIES];

public:
    PropertyOwner(const std::string &name, const std::string &egn, const std::string &address)
        : Person(name, egn, address) {
        // Initialize properties array
        for (int i = 0; i < MAX_PROPERTIES; ++i) {
            properties[i] = "";
        }
    }

    ~PropertyOwner() override {
        // Free memory for properties
        for (int i = 0; i < MAX_PROPERTIES; ++i) {
            delete[] properties[i];
        }
    }

    void addProperty(int index, const char* propertyAddress) {
        if (index >= 0 && index < MAX_PROPERTIES) {
            properties[index] = new char[strlen(propertyAddress) + 1];
            strcpy(properties[index], propertyAddress);
            //cout<< propertyAddress<<endl;
            propertyList.push_front(propertyAddress);
        }
    }

    void display() const override {
        Person::display();
        std::cout << "Properties: " << std::endl;
        for (int i = 0; i < MAX_PROPERTIES; ++i) {
            if (properties[i] != "") {
                std::cout << "- " << properties[i] << std::endl;
            }
        }
    }

    const char* getProperty(int index) const {
        if (index >= 0 && index < MAX_PROPERTIES) {
            return properties[index];
        }
        return "";
    }
};
void findTennants(string addresss,Person* persons[] )
{
	
	int flag = 0;
//	bool flag = (std::find(propertyList.begin(), propertyList.end(), address) != propertyList.end());
//			
//	if(flag == false)
//	{
//		cout << "Addresa ne e v spisuka s Imoti"<<endl;
//		return;
//	}
	for(int i=0;i<10;i++)
	{
	
		//cout<< addresss<<" predi trans"<<endl;
		const char * a = addresss.c_str();
		const char * b = persons[i]->getAddress().c_str();
		
		if(strcmp(a,b)==0)
		{
			persons[i]->display();
			flag =1;
		}
		
	}
	if(flag==0)
	{cout<<"Nqma naemateli na tozi adress"<<endl;
	return;
	}
}

void findProperties(string egn,PropertyOwner* owners[])
{
	int flag = 0;
	for(int i=0;i<10;i++)
	{
		const char * a = egn.c_str();
		const char * b = owners[i]->getEgn().c_str();
		//cout<<a<<"=?"<< b;
		if(strcmp(a,b)==0)
		{
			owners[i]->display();
			flag =1;
		}
		 
		}
	
	if(flag==0)cout<<"Tozi chovek nqma imoti"<<endl;
};

// Function to output data to file
void saveDataToFile(const Person *person, const std::string &filename) {
    ofstream outfile;
    outfile.open("owner_info.txt", std::ios_base::app);
    if (outfile.is_open()) {
        //person->display();
        outfile <<endl<<"Name: " <<person->getName() << std::endl;
        outfile <<"Egn: "<< person->getEgn() << std::endl;
        outfile <<"Adress: "<< person->getAddress() << std::endl;
        
        outfile.close();
        std::cout << "Data saved to file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void saveDataToFile(const PropertyOwner *owner, const std::string &filename) {
    ofstream outfile;
    outfile.open("owner_info.txt", std::ios_base::app);
    if (outfile.is_open()) {
        //owner->display();
        outfile <<endl<<"Name: " <<owner->getName() <<" (Owner)" << std::endl;
        outfile <<"Egn: "<< owner->getEgn() << std::endl;
        outfile <<"Adress: "<< owner->getAddress() << std::endl;
        outfile <<"Properties: "<< std::endl;
        for (int i = 0; i < MAX_PROPERTIES; ++i) {
            if (owner->getProperty(i) != "") {
                outfile << "- " << owner->getProperty(i) << std::endl;
            }
        }
        outfile.close();
        std::cout << "Data saved to file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

int main() {
	Person* per[10];
    PropertyOwner* own[10];
     
	per[0]= new Person("Bozhidar Uzunov", "0244245656", "3 Blok Stud gr.");
	per[1]= new Person("Radul Ivanov", "674241246", "789 Elm St");
	per[2]= new Person("Bozhidar Uzunov", "0244245656", "654 Pine St");
	per[3]= new Person("Radul Ivanov", "674241246", "654 Pine St");
	per[4]= new Person("Bozhidar Uzunov", "0244245656", "222 Walnut St");
	per[5]= new Person("Radul Ivanov", "674241246", "888 Cedar St");
	
	own[0]= new PropertyOwner("John Doe", "12345", "123 Main St");
    own[0]->addProperty(0, "456 Oak St");
    own[0]->addProperty(1, "789 Elm St");
    own[0]->addProperty(2, "78 Elm St");
    own[0]->addProperty(3, "79 Elm St");
    own[0]->addProperty(4, "89 Elm St");
    
// owner2
    own[1] = new PropertyOwner("Alice Johnson", "67890", "456 Center St");
    own[1]->addProperty(0, "876 Park Ave");
    own[1]->addProperty(1, "543 Hill Rd");
    // Add more properties for owner2 if needed...

    // owner3
    own[2] = new PropertyOwner("Bob Smith", "54321", "987 Elm St");
    own[2]->addProperty(0, "321 Maple St");
    own[2]->addProperty(1, "654 Pine St");
    // Add more properties for owner3 if needed...

    // owner4
    own[3] = new PropertyOwner("Emma Brown", "13579", "222 Oak St");
    own[3]->addProperty(0, "888 Cedar St");
    own[3]->addProperty(1, "999 Birch St");
    // Add more properties for owner4 if needed...

    // owner5
    own[4] = new PropertyOwner("Michael Davis", "24680", "333 Pine St");
    own[4]->addProperty(0, "111 Cherry St");
    own[4]->addProperty(1, "222 Walnut St");
   

    // Save data to a file
    saveDataToFile(own[0], "owner_info.txt");
    saveDataToFile(own[1], "owner_info.txt");
    saveDataToFile(own[2], "owner_info.txt");
    saveDataToFile(own[3], "owner_info.txt");
    saveDataToFile(own[4], "owner_info.txt");
    saveDataToFile(per[0], "owner_info.txt");
    saveDataToFile(per[1], "owner_info.txt");
    saveDataToFile(per[2], "owner_info.txt");
    saveDataToFile(per[3], "owner_info.txt");
    saveDataToFile(per[4], "owner_info.txt");
    saveDataToFile(per[5], "owner_info.txt");
    
    cout << "Komandi: x - stop, t - izvadi naematelite na opredelen address"<<endl;
    cout << "n - chrez egn na naemodatelq izvedete imotite mu"<<endl;
    for(;;)
    {
    	char command = ' ';
    	cout << "Vuvedete comanda: ";
    	std::cin >> command;
    	if(command=='x')return 0;
    	else if(command =='t'){
    		string addresss;
    		cout<<endl << "Vuvedete adress: ";
    		cin.ignore();
    		getline (cin,addresss);
    		findTennants(addresss, per);
		}
		else if(command == 'n'){
			string egn;
    		cout << "Vuvedete egn: " <<endl;
    		cin>> egn;
    		findProperties(egn, own);
		}
		else cerr << "Greshna komanda" <<endl;
	}
    //if(person1->getAddress()==)

    return 0;
}

