#include "Bst_Tree.h"
#include<iostream>

void Bst_Tree::findmax(Bst_Node* root)
{
  if(root==NULL)
   return;
 findmax(root->left);
 v.push_back(root);
 findmax(root->right);

}

Bst_Node* Bst_Tree::helper(int accno,Bst_Node* &root)
{

    if(root==nullptr)
    {
        std::cout<<"Invalid account can't delete this";
        return root;
    } 
    else if(accno < root->accno)
    {
        root->left = helper(accno,root->left);
        return root;
    }
    else if(accno > root->accno)
    {
        root->right = helper(accno,root->right);
        return root;
    }
    else
    {

      if(root->right && root->left)
      {
         findmax(root->right);
         Bst_Node* temp = v.back();
         root->accno = temp->accno;
         root->name = temp->name;
         root->amount = temp->amount;
         root->password = temp->password;
         root->left = helper(root->accno,root->left);
         return root;
         //transfer

      }

      else
      {
          if(root->left==NULL)
          {
            Bst_Node* temp = root->right;
            delete root;
            return temp;
          }
          else
          {
            Bst_Node* temp = root->left;
            delete root;
            return temp;            
          }


      }


    }



}


void Bst_Tree::del(int accno)
{
 
this->root = helper(accno,root);

}

Bst_Tree::Bst_Tree()
{
root = nullptr;
}


void Bst_Tree::store(Bst_Node* node,std::ofstream &write)
{
 if(node==NULL)
   return;

write<<std::to_string(node->accno)<<std::endl;
write<<node->name<<std::endl;
write<<std::to_string(node->amount)<<std::endl;
write<<std::to_string(node->password)<<std::endl;


//  std::cout<<std::endl;
//  std::cout<<"account no is : "<<node->accno<<std::endl;
//  std::cout<<"Holder's name : "<<node->name<<std::endl;
//  std::cout<<"Balance is : "<<node->amount<<std::endl;
//  std::cout<<"Password is "<<node->password<<std::endl;
 store(node->left,write);
 store(node->right,write);

}

Bst_Tree::~Bst_Tree()
{
 std::cout<<"Storing the contents before closing the file \n\n";
 std::ofstream write;

 try
 {
   write.open("file.data",std::ios::out);
 }
 catch(const std::exception& e)
 {
    std::cerr << e.what() << '\n';
 }
 
 
 Bst_Node* node = root;
 store(node,write);
 write.close();


}



void Bst_Tree::add_to_tree(int accno,std::string name,int amount,int password)
{

  Bst_Node* node = root;
    Bst_Node* temp = new Bst_Node(accno,name,amount,password);
    if(root==NULL)
    {
            root = temp;
            
    }

    else
    {

        while(true)
        {
            if(accno < node->accno)
            {
                if(node->left==nullptr)
                {
                    node->left = temp;
                    return;
                }
                node = node->left;
            }
            else if(accno > node->accno)
            {
                if(node->right==nullptr)
                {
                    node->right = temp;
                    return;
                }
                node = node->right;
            }
            else 
            {
                std::cout<<"same account already exits dude"<<std::endl;
                return;
            }
        }


    }
    

}



void Bst_Tree::load()
{
   std::ifstream read;
   


  try
  {
    read.open("file.data");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  



   

   std::string line;
   int count=0;
   std::string name;
   int accno,amount,password;
   int gl_count=0;
    while(getline(read,line))
    {
        if(count==0)
        {
            accno = std::stoi(line);
            count=1;
        }
        else if(count==1)
        { 
            name = line;
            //std::cout<<"Name is : "<<line<<"\n";
            count=2;
        }
        else if(count==2)
        {
            amount = std::stoi(line);
            //std::cout<<"amount is : "<<line<<"\n";
            count=3;
        }
        else
        {
            password = std::stoi(line);
            //std::cout<<"password is : "<<line<<"\n";
            count=0;
            add_to_tree(accno,name,amount,password);
        }
        // std::cout<<gl_count;
        // gl_count++;

    }

  read.close();
  return;
}


void Bst_Tree::add_account(int accno,std::string name,int amount,int password)
{

    Bst_Node* node = root;
    Bst_Node* temp = new Bst_Node(accno,name,amount,password);
    if(root==NULL)
    {
            root = temp;
    }

    else
    {

        while(true)
        {
            if(accno < node->accno)
            {
                if(node->left==nullptr)
                {
                    node->left = temp;
                    return;
                }
                node = node->left;
            }
            else if(accno > node->accno)
            {
                if(node->right==nullptr)
                {
                    node->right = temp;
                    return;
                }
                node = node->right;
            }



        }


    }
    
 
}


void Bst_Tree::print(Bst_Node* node)
{
 if(node==nullptr)
   return;
 std::cout<<std::endl;

 std::cout<<"account no is : "<<node->accno<<std::endl;
 std::cout<<"Holder's name : "<<node->name<<std::endl;
 std::cout<<"Balance is : "<<node->amount<<std::endl;
 std::cout<<"Password is "<<node->password<<std::endl;

 print(node->left);

 print(node->right);

}

void Bst_Tree::checkall()
{

   Bst_Node* node = root;
   print(node);
   std::cout<<"\n\n\n";

}



