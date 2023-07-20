#include "Customer.h"

#include <iostream>

void init_customer()
{
  std::cout<<"Please select option : \n";
  std::cout<<"1.) withdraw \n";
  std::cout<<"2.) Deposit\n";
  std::cout<<"3.) check balance \n";
  std::cout<<"4.) Exit \n";
  int n;
  std::cin>>n;
  Customer c;
  c.load();
  switch (n)
  {
    case 1:
    {

      std::cout<<"\n ********************************************************";
      std::cout<<"\n Please Enter the accno and amount";
      int accno,amt;
      std::cin>>accno>>amt;
      c.withdraw(accno,amt);

        break;
    }
    case 2:
    {
      std::cout<<"\n ********************************************************";
      std::cout<<"\n Please Enter the accno and amount";
      int accno,amt;
      std::cin>>accno>>amt;
      c.deposit(accno,amt);      
      break;
    }
        
    case 3:
    {
      std::cout<<"\n ********************************************************";
      std::cout<<"\n Please Enter the accno : ";
      int accno;
      std::cin>>accno;
      c.checkbalance(accno);
        break;
    }
    case 4:
    {
      return;
    }
    default:
    {
        std::cout<<"Please select a correct option";
      break;
    }
        
  }

}


void Customer::withdraw(int accno,int amount)
{
  Bst_Node* node = root;

  while(node)
  {
   
   if(accno == node->accno)
   {
         int total = node->amount;
         if(total<amount)
         {
          std::cout<<"\n sorry buddy not enough money \n";
          return;
         }
         else if(amount<0)
         {
          std::cout<<"\n Please Enter a valid amount";
         }
         else
         {
            int new_amount = total - amount;
            std::cout<<"\nYour balance was : \n"<<total;
            std::cout<<"\nYour new balance is : \n"<<new_amount<<std::endl;
            node->amount = new_amount;

         }
     

     return;

   }
   else if(accno < node->accno)
   {
    node = node->left;
   }
   else
   {
    node = node->right;
   } 

  }//return from while only.
  

 std::cout<<"account no is invalid\n";
 return;

}


void Customer::deposit(int accno,int amount)
{

    Bst_Node* node = root;

    while(node)
    {
    
    if(accno == node->accno)
    {
          int total = node->amount;
          if(amount<0)
          {
            std::cout<<"\n Please Enter a valid Positive amount";
          }
          else
          {
              int new_amount = total + amount;
              std::cout<<"\nYour balance was : \n"<<total;
              std::cout<<"\nYour new balance is : \n"<<new_amount<<std::endl;
              node->amount = new_amount;

          }
      

      return;

    }
    else if(accno < node->accno)
    {
      node = node->left;
    }
    else
    {
      node = node->right;
    } 

    }//return from while only.
    

  std::cout<<"account no is invalid\n";
  return;

}



void Customer::checkbalance(int accno)
{
    Bst_Node* node = root;

      while(node)
      {
      
          if(accno == node->accno)
          {
           std::cout<<"\n\n";
           std::cout<<"*********************************************************************";
           std::cout<<"Your balance is : ";
           std::cout<<node->amount;
           std::cout<<"*********************************************************************";
           std::cout<<"\n\n";
           return;
          }
          else if(accno < node->accno)
          {
            node = node->left;
          }
          else
          {
            node = node->right;
          } 

      }//return from while only.
      

    std::cout<<"account no is invalid\n";
    return;

}