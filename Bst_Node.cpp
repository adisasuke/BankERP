#include "Bst_Node.h"
Bst_Node::Bst_Node()
{
    
}
Bst_Node::Bst_Node(int accno,std::string name,int amount,int password)
{

this->left = nullptr;
this->right = nullptr;
this->accno = accno;
this->name = name;
this->amount = amount;
this->password = password;

}

