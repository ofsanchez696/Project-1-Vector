#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

template <typename T> class Item 
{
public:
    T name;
    T expiration;
    T category;
    int quantity;
    Item(T n, T e, T c, int q) 
    {
        name = n;
        expiration = e;
        category = c;
        quantity = q;
    }
};

template<typename T, size_t nSize = 4> class Inventory 
{
public:
    std::vector<Item<T>> items;
    typename std::vector<Item<T>>::iterator it; 
    // Write Your code 
     void displayItems()
    {
        std::cout << "-------Inventory-------" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Expiration" << std::setw(15) << "Quantity" << std::setw(10) << "Category" << std::endl;
        for (size_t i = 0; i < items.size(); i++) 
        {
            std::cout << std::left << std::setw(20) << items[i].name << std::setw(15) << items[i].expiration << std::setw(15) << items[i].quantity << std::setw(15) << items[i].category << std::endl;
        }
    }
    void addNewItem(Item<T> NewItem)
    {
        for (auto& item : items)
        {
            if (item.name == NewItem.name)
            {
                std::cout << "Item is already present in inventory" << std::endl; return;
            }
        }
        items.push_back(NewItem);
    }
    void updateItem(T itemname, T expiration, T category, int quantity)
    {
        for (auto &item : items) 
        {
            if (item.name == itemname)
            {
                item.expiration = expiration;
                item.category = category;
                item.quantity = quantity;
                std::cout << "Item " << itemname << " updated" << std::endl;
                return;
            }
        }
        throw "Item not found";
    }
    void increaseQuantity(T itemname,int quantity)
    {
        for (auto &item : items) 
        {
            if (item.name == itemname) 
            {
                item.quantity += quantity;
                std::cout << "Quantity has increased: " << item.quantity << std::endl;
                return;
            }
        }
    }
    void removeItem(T itemname)
    {
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if (it -> name == itemname)
            {
                items.erase(it);
                std::cout << "Items " << itemname << " removed from inventory" << std::endl;
                return;
            }
        }
        throw "Item not found";
    }
    void Total()
    {
        int totalQuantity = 0;
        for (auto &item : items)
        {
            totalQuantity += item.quantity;
            std::cout << "Total number of items in inventory = " << items.size() << std::endl;
            return;
        }
    }
    void searchItem(T itemname)
    {
        for (auto &item : items)
        {
            if (item.name == itemname)
            {
                std::cout << "Query for Cereals" << std::endl;
                std::cout << "Item: " << item.name << std::endl;
                std::cout << "Expiration Date: " << item.expiration << std::endl;
                std::cout << "Category: " << item.category << std::endl;
                std::cout << "Quantity: " << item.quantity << std::endl;
                return;
            }
        }
        throw "Item not found";
    }
};
template<typename T>class Appointment
{
public:
    T c_name;
    T ap_date;
    T ap_time;
    T CWID;
    Appointment(T n, T d, T t, T cw) 
    {
        c_name = n;
        ap_date = d;
        ap_time = t;
        CWID = cw;
    }
};
template<typename T>class AppointmentSystem 
{
public:
    // Write Your code 
    std::vector<Appointment<T>> Appointments;
    typename std::vector<Appointment<T>>::iterator it; 
    void display() {
        std::cout << "-------Appointments-------" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Date" << std::setw(15) << "Time" << std::setw(15) << "CWID" << std::endl;
        for (int i = 0; i < Appointments.size(); i++) {
            std::cout << std::left << std::setw(20) << Appointments[i].c_name << std::setw(15) << Appointments[i].ap_date << std::setw(15) << Appointments[i].ap_time << std::setw(15) << Appointments[i].CWID << std::endl;
        }
    }
    void schedule(Appointment<T> newAppointment)
    {
        for (auto &appt : Appointments)
        {
            if (appt.CWID == newAppointment.CWID)
            {
                std::cout << "You already scheduled an appointment!!!" << std::endl;
                return;
            }
        }
        Appointments.push_back(newAppointment);
    }
    void Total_appointments(T date, T time)
    {
        int count = 0;
        for (const auto &appt :Appointments)
        {
            if (appt.ap_date == date && appt.ap_time == time)
            {
                count++;
                
            }
        }
        std::cout<< "Total Appointments: " << count << std::endl;
    }
    void removeRecent()
    {
        if (!Appointments.empty())
        {
            Appointments.pop_back();
        }
    }
};

int main() 
{
    //Remove comments and run following test cases
    Inventory<std::string> items;

    Item<std::string> Items("Protein Bar", "05/09/2023", "Snacks", 4);

    items.addNewItem(Items);

    Item<std::string> Items2("Milk","05/12/2023","Regular",2);

    items.addNewItem(Items2);

    Item<std::string> Items3("Cereal","09/12/2023","Snacks",5);

    items.addNewItem(Items3);

    items.displayItems();
    
    items.updateItem("Milk","09/24/2023","Regular",3);

    items.displayItems();

    items.increaseQuantity("Cereal",10);

    items.displayItems();
    try{
        items.updateItem("bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    items.displayItems();
    
    items.updateItem("Cereal","09/27/2023","Regular",4);

    items.displayItems();

    items.Total();
    try{
        items.removeItem("Bread");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        items.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    items.displayItems();
    try{
        items.searchItem("Cereal");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
    system("pause");
}