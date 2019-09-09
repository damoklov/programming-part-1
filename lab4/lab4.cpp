#include "lab4.h"
#include <string>
using namespace std;


string convert(bool);

Camera::Camera(string iManufacturer, int iStorage, int iPrice, string iModel, double iZoom, int iWarranty, bool iFlash)
{
    zoom = iZoom;
    manufacturer = iManufacturer;
    storage = iStorage;
    price = iPrice;
    model = iModel;
    warranty = iWarranty; // warranty service (in years)
    flash = iFlash;
};
int Camera::getWarranty()
{
  return warranty;
};
bool Camera::getFlash()
{
    return flash;
}
double Camera::getZoom()
{
    return zoom;
};
string Camera::getManufacturer()
{
    return manufacturer;
};
int Camera::getStorage()
{
    return storage;
};

