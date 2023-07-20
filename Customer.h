// #include "Bst_Tree.h"
#include <iostream>

#include "admin.h"





class Customer : public Bst_Tree
{

public:
void withdraw(int accno,int amount);
void deposit(int accno,int amount);
void checkbalance(int accno);
Bst_Node* helper(Bst_Node* root,int accno);

};