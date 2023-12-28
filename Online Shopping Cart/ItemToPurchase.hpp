//
//  ItemToPurchase.hpp
//  Online Shopping Cart
//
//  Created by paige on 11/23/22.
//

#ifndef ItemToPurchase_hpp
#define ItemToPurchase_hpp

#include <stdio.h>

#include <string>
using namespace std;

class ItemToPurchase {
   
public:
   ItemToPurchase();
   ItemToPurchase(string name, string description, int price, int quantity);
   void SetName(string name);
   string GetName();
   void SetDescription(string description);
   string GetDescription();
   void SetPrice(int price);
   int GetPrice();
   void SetQuantity(int quantity);
   int GetQuantity();
   
   void PrintItemCost();
   void PrintItemDescription();

private:
   string itemName;
   string itemDescription;
   int itemPrice;
   int itemQuantity;
};

#endif /* ItemToPurchase_hpp */
