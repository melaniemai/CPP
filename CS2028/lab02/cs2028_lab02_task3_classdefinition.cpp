#include <iostream>
#include "cs2028_lab02_task03._class.h"
#include <string>

using namespace std;

// int product_ID;
// int product_units;
// double product_prices;
// double product_sales;
// string description = "";
// bool TaxExempt;

Products::Products(int product_ID_in, int product_units_in, double product_prices_in, string desc, bool tax){
    product_ID = product_ID_in;
    product_units = product_units_in;
    product_prices = product_prices_in;
    description = desc;
    TaxExempt = tax;
    product_sales = product_units * product_prices;
}

int Products::getID(){
    return product_ID;
}

void Products::setID(int product_ID_in){
    product_ID = product_ID_in;
}

int Products::getUnits(){
    return product_units;
}

void Products::setUnits(int product_units_in){
    product_units = product_units_in;
}


double Products::getPrices(){
    return product_prices;
}

void Products::setPrices(double product_prices_in){
    product_prices = product_prices_in;
    product_sales = product_units * product_prices;
}


double Products::getSales(){
    return product_sales;
}

void Products::setSales(double s){
    product_sales = s;
}

string Products::getDesc(){
    return description;
}

void Products::setDesc(string desc){
    description = desc;
}

bool Products::getTax(){
    return TaxExempt;
}

void Products::setTax(bool tax){
    TaxExempt = tax;
}

string Products::getTaxStr(){
    string t = "True";
    string f = "False";
    if(TaxExempt == true){
        return t;
    } else{
        return f;
    }
}

void Products::setTaxStr(string tax){
    if(tax == " True"){
        TaxExempt = true;
    } else{
        TaxExempt = false;
    }
}
