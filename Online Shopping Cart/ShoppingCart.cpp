//
//  ShoppingCart.cpp
//  Online Shopping Cart
//
//  Created by paige on 11/23/22.
//

#include <iostream>
#include <vector>
using namespace std;

#include "ShoppingCart.hpp"

ShoppingCart::ShoppingCart() {
   customerName = "none";
   currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
   customerName = name;
   currentDate = date;
}

string ShoppingCart::GetCustomerName() {
   return customerName;
}

string ShoppingCart::GetDate() {
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string item) {
   int size = cartItems.size();
   bool yes = false;
   for(int i = 0; i < size; ++i) {
      if(cartItems.at(i).GetName() == item) {
         cartItems.erase(cartItems.begin() + i);
         size = cartItems.size();
         yes = true;
      }
   }
   
   if(!yes) {
      cout << "Item not found in cart. Nothing removed." << endl;
   }
   cout << endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
   int size = cartItems.size();
   bool yes = false;
   if(item.GetDescription() != "none") {
      for(int i = 0; i < size; ++i) {
         if(cartItems.at(i).GetName() == item.GetName()) {
            cartItems.at(i).SetDescription(item.GetDescription());
            yes = true;
         }
      }
      
      if(!yes) {
         cout << "Item not found in cart. Nothing modified." << endl << endl;
      }
   }
   
   if(item.GetPrice() != 0) {
      for(int i = 0; i < size; ++i) {
         if(cartItems.at(i).GetName() == item.GetName()) {
            cartItems.at(i).SetPrice(item.GetPrice());
            yes = true;
         }
      }
      
      if(!yes) {
         cout << "Item not found in cart. Nothing modified." << endl << endl;
      }
   }
   
   if(item.GetQuantity() != 0) {
      for(int i = 0; i < size; ++i) {
         if(cartItems.at(i).GetName() == item.GetName()) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
            yes = true;
         }
      }
      
      if(!yes) {
         cout << "Item not found in cart. Nothing modified." << endl << endl;
      }
   }
}

int ShoppingCart::GetNumItemsInCart() {
   int count = 0;
   int size = cartItems.size();
   
   for(int i = 0; i < size; ++i) {
      count = count + cartItems.at(i).GetQuantity();
   }
   
   return count;
}

int ShoppingCart::GetCostOfCart() {
   int cost = 0;
   int size = cartItems.size();
   
   for(int i = 0; i < size; ++i) {
      cost = cost + (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
   }
   
   return cost;
}

void ShoppingCart::PrintTotal() {
   cout << "OUTPUT SHOPPING CART" << endl;
   cout << ShoppingCart::GetCustomerName() << "'s Shopping Cart - " << ShoppingCart::GetDate() << endl;
   cout << "Number of Items: " << ShoppingCart::GetNumItemsInCart() << endl;
   int size = cartItems.size();
   cout << endl;
   for(int i = 0; i < size; ++i) {
      cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice();
      cout << " = $" << cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice() << endl;
   }
   
   int cost = 0;
   if(size != 0) {
      for(int i = 0; i < size; ++i) {
         cost = cost + (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
      }
   } else {
      cout << "SHOPPING CART IS EMPTY" << endl;
   }
   cout << endl << "Total: $" << cost << endl << endl;
}

void ShoppingCart::PrintDescriptions() {
   cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
   cout << ShoppingCart::GetCustomerName() << "'s Shopping Cart - " << ShoppingCart::GetDate() << endl << endl;
   
   int size = cartItems.size();
   cout << "Item Descriptions" << endl;
   for(int i = 0; i < size; ++i) {
      cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
   }
   cout << endl;
}
