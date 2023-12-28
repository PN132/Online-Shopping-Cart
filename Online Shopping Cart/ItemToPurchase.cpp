//
//  ItemToPurchase.cpp
//  Online Shopping Cart
//
//  Created by paige on 11/23/22.
//

#include <iostream>
using namespace std;

#include "ItemToPurchase.hpp"

ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemDescription = "none";
   itemPrice = 0;
   itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
   itemName = name;
   itemDescription = description;
   itemPrice = price;
   itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name) {
   itemName = name;
}

void ItemToPurchase::SetDescription(string description) {
   itemDescription = description;
}

void ItemToPurchase::SetPrice(int price) {
   itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
   itemQuantity = quantity;
}

string ItemToPurchase::GetName() {
   return itemName;
}

string ItemToPurchase::GetDescription() {
   return itemDescription;
}

int ItemToPurchase::GetPrice() {
   return itemPrice;
}

int ItemToPurchase::GetQuantity() {
   return itemQuantity;
}

void ItemToPurchase::PrintItemCost() {
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() {
   cout << itemName << ": " << itemDescription << endl;
}
