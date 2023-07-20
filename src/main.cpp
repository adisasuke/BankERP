#include "Customer.cpp"


#include <iostream>


int main()
{
    std::cout<<"Welcome \n";

    
    while(true)
    {
        
        std::cout<<"\n\n";
        std::cout<<"Please select your role : \n";
        std::cout<<"1. admin\n";
        std::cout<<"2. customer\n";
        std::cout<<"3. Exit\n";

        int n;
        std::cin>>n;
        if(n==1)
        {
            admin();
        }
        else if(n==2)
        {
           init_customer();          
        }
        else if(n==3)
        {
            std::cout<<"Bye \n";
            break;
        }
        else 
        {
            continue;
        }

    }

        
    return 0;
}


