//
//  ShoppingCart.hpp
//  Online Shopping Cart
//
//  Created by paige on 11/23/22.
//

#ifndef ShoppingCart_hpp
#define ShoppingCart_hpp

#include <stdio.h>
#include <string>
#include "ItemToPurchase.hpp"
using namespace std;

class ShoppingCart {
   
public:
   ShoppingCart();
   ShoppingCart(string name, string date);
   string GetCustomerName();
   string GetDate();
   void AddItem(ItemToPurchase item);
   void RemoveItem(string item);
   void ModifyItem(ItemToPurchase item);
   int GetNumItemsInCart();
   int GetCostOfCart();
   void PrintTotal();
   void PrintDescriptions();

private:
   string customerName;
   string currentDate;
   vector < ItemToPurchase > cartItems;
   
};

#endif /* ShoppingCart_hpp */
