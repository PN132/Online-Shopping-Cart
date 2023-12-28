//
//  main.cpp
//  Online Shopping Cart
//
//  Created by paige on 11/23/22.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "ShoppingCart.hpp"
#include "ItemToPurchase.hpp"

void PrintMenu() {
   
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl << endl;
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   
   if(option == 'o') {
      theCart.PrintTotal();
   }
   if(option == 'i') {
      theCart.PrintDescriptions();
   }
   if(option == 'a') {
      cout << "ADD ITEM TO CART" << endl;
      
      ItemToPurchase item;
      string name;
      string description;
      int price;
      int quantity;
      
      cout << "Enter the item name:" << endl;
      cin.ignore();
      getline(cin, name);
      item.SetName(name);
      
      cout << "Enter the item description:" << endl;
      getline(cin, description);
      item.SetDescription(description);
      
      cout << "Enter the item price:" << endl;
      cin >> price;
      item.SetPrice(price);
      
      cout << "Enter the item quantity:" << endl;
      cin >> quantity;
      item.SetQuantity(quantity);
      
      cout << endl;
      theCart.AddItem(item);
   }
   if(option == 'd') {
      string userItem;
      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      cin.ignore();
      getline(cin, userItem);
      
      theCart.RemoveItem(userItem);
   }
   if(option == 'c') {
      cout << "CHANGE ITEM QUANTITY" << endl;
      
      string itemName;
      int quantity;
      ItemToPurchase modify;
      cout << "Enter the item name:" << endl;
      cin.ignore();
      getline(cin, itemName);
      modify.SetName(itemName);
      cout << "Enter the new quantity:" << endl;
      cin >> quantity;
      modify.SetQuantity(quantity);
      
      theCart.ModifyItem(modify);
   }
   
}

int main() {
   
   string userName;
   string currDate;
   char choice;
   
   cout << "Enter customer's name:" << endl;
   getline(cin, userName);
   cout << "Enter today's date:" << endl;
   getline(cin, currDate);
   cout << endl;
   
   ShoppingCart userCart(userName, currDate);
   
   cout << "Customer name: " << userName << endl;
   cout << "Today's date: " << currDate << endl << endl;
   
   PrintMenu();
   cout << "Choose an option:";
   cin >> choice;
   cout << endl;
   
   while(choice != 'q') {
      while(choice != 'a' && choice != 'd' && choice != 'c' && choice != 'i' && choice != 'o') {
         cout << "Choose an option:";
         cin >> choice;
         cout << endl;
         if(choice == 'q') {break;}
      }
      if(choice == 'q') {break;}
      ExecuteMenu(choice, userCart);
      PrintMenu();
      cout << "Choose an option:";
      cin >> choice;
      cout << endl;
      if(choice == 'q') {break;}
   }
   
   return 0;
}
