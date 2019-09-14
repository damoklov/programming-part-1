#include <iostream>
#include <string>
using namespace std;


class ADT
{
public:
    virtual int getCapacity();
    virtual int getPowerConsumption();
    virtual int getChannels();
    virtual string getFavSong();
    virtual double getFrequency();
    virtual int getSpeakers();
    virtual void setCapacity(int);
    virtual void setPowerConsumption(int);
    virtual void setChannels(int);
    virtual void setFavSong(string);
    virtual void setFrequency(double);
    virtual void setSpeakers(int);
};

class HouseholdAppliance: public ADT
{
protected:
    string name;
    string location;
    double price = 0.0;
public:
    virtual void special();
    void setName(string);
    void setLocation(string);
    void setPrice(double);
    string getName();
    string getLocation();
    double getPrice();
};
class WashingMachine: public HouseholdAppliance
{
public:
    int capacity = 0;
    void special();
    void setCapacity(int);
    int getCapacity();
};
class VacuumCleaner: public HouseholdAppliance
{
public:
    int powerConsumption = 0;
    void special();
    void setPowerConsumption(int);
    int getPowerConsumption();
};
class TV: public HouseholdAppliance
{
public:
    int channels = 0;
    void special();
    void setChannels(int);
    int getChannels();
};
class Audio: public HouseholdAppliance
{
public:
    string favSong;
    void special();
    void setFavSong(string);
    string getFavSong();
};
class Radio: public HouseholdAppliance
{
public:
    double frequency = 0.0;
    void special();
    void setFrequency(double);
    double getFrequency();
};
class MusicCenter: public HouseholdAppliance
{
public:
    int speakers = 0;
    void special();
    void setSpeakers(int);
    int getSpeakers();
};
