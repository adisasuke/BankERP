#include "Bst_Node.h"

#include <string>
#include <fstream>
#include <vector>


class Bst_Tree
{
protected:
    Bst_Node *root;

public:
    std::vector<Bst_Node*> v;
    Bst_Tree();
    ~Bst_Tree();
    void add_account(int,std::string,int,int);
    void print(Bst_Node*);
    void checkall();
    void load();
    void add_to_tree(int accno,std::string name,int amount,int password);
    void store(Bst_Node* node,std::ofstream &write);
    void del(int);
    Bst_Node* helper(int accno,Bst_Node* &root);
    void findmax(Bst_Node*);
};