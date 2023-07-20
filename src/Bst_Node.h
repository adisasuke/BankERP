#include<string>


class Bst_Node
{
 public:   
    Bst_Node *left;
    Bst_Node *right;
    int accno;
    std::string name;
    int amount;
    int password;
    Bst_Node();
    Bst_Node(int accno,std::string name,int amount,int password);
};