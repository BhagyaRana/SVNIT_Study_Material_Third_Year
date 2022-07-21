// Question Link - https://www.hackerrank.com/challenges/hotel-prices/problem

#include <iostream>
#include <vector>

using namespace std;

// HotelRoom Class 
class HotelRoom
{
private:
    int no_of_bedrooms;
    int no_of_bathrooms;

public:
    // HotelRoom Constructor
    HotelRoom(int bedrooms, int bathrooms)
    {
        no_of_bedrooms = bedrooms;
        no_of_bathrooms = bathrooms;
    }

    //  virtual int get_profit() ---(Instead Of)---> int get_profit()
    virtual int get_profit()
    {
        return ((50 * no_of_bedrooms) + (100 * no_of_bathrooms));
    }
};

// HotelApartment Class
class HotelApartment : public HotelRoom
{
public:
    // HotelApartment Constructor
    HotelApartment(int bedrooms, int bathrooms) : HotelRoom(bedrooms, bathrooms) {}

    // We want the Derived Class get_profit() to be Executed/ Overridden on Base Class get_profit()
    int get_profit()
    {
        return ((HotelRoom::get_profit()) + 100);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<HotelRoom *> rooms;

    string room_type;
    int bedrooms, bathrooms;

    for (int i = 0; i < n; ++i)
    {
        cin >> room_type >> bedrooms >> bathrooms;

        if (room_type == "standard")
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        else
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
    }

    int total_profit = 0;

    // The Real Problem in this Code Sample [get_profit()]
    for (auto room : rooms)
        total_profit += room->get_profit();

    cout << "Total Profits : " << total_profit << endl;

    // Free Up Memory by Deallocating the Objects
    for (auto room : rooms)
    {
        delete room;
    }
    rooms.clear();

    return 0;
}