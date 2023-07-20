#include "Bst_Tree.h"

#include<iostream>


void admin()
{

   Bst_Tree t;
   t.load();
   while(true)
   {
        std::cout<<"Please select an option\n";
        std::cout<<"1.) Add account\n";
        std::cout<<"2.) Delete account\n";
        std::cout<<"3.) Display all account information\n";
        std::cout<<"4.) Exit\n";
        // add_account(int accno,string name,int amount,int password)
        int n;
        std::cin>>n;
        if(n==1)//add account
        {
            int accno;
            std::string name;
            int amount;
            int password;
            std::cout<<"Welcome to account opening \n\n"<<std::endl;
            
            
            std::cout<<"please Enter your accountno"<<std::endl;
            std::cin>>accno;

            std::cout<<"Please Enter your name \n";
            //  std::cin>>name;
            std::cin.ignore();
            std::getline(std::cin,name);

            std::cout<<"Please Enter your amount\n";
            std::cin>>amount;
            std::cout<<"Please Enter your password\n";
            std::cin>>password;
            t.add_to_tree(accno,name,amount,password);

        }
        else if(n==2)
        {
            std::cout<<"\n Please enter accno : \n";
            int accno;
            std::cin>>accno;
            t.del(accno);
            std::cout<<"Account is deleted \n";

        }
        else if(n==3)
        {
            t.checkall();
        }
        else if(n==4)
        {
            std::cout<<"Bye \n";
            break;
        }
        else 
        {
            continue;
        }

   }
}