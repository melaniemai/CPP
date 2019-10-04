#ifndef CS2028_LAB02_TASK03_H
#define CS2028_LAB02_TASK03_H
#include <string>

using namespace std;

class Products{
private:
    int product_ID;
    int product_units;
    double product_prices;
    double product_sales;
    string description;
    bool TaxExempt;
public:
    Products(){}
    Products(int product_ID_in);
    Products(int product_ID_in, int product_units_in, double product_prices_in, string desc, bool tax);

    int getID();
    void setID(int product_ID_in);

    int getUnits();
    void setUnits(int product_units_in);

    double getPrices();
    void setPrices(double product_prices_in);

    double getSales();
    void setSales(double s);

    string getDesc();
    void setDesc(string desc);

    bool getTax();
    string getTaxStr();
    void setTax(bool tax);
    void setTaxStr(string tax);

};




#endif // CS2028_LAB02_TASK03_H
