#include<iostream>
#include<fstream>
using namespace std;



int main()
{
 ifstream read;
 read.open("file.data");
 string line;
 int count=0;
 while(getline(read,line))
 {
  if(count==0)
  {
    cout<<"account number is : "<<line<<"\n";
    count=1;
  }
  else if(count==1)
  {
    cout<<"Name is : "<<line<<"\n";
    count=2;
  }
  else if(count==2)
  {
    cout<<"amount is : "<<line<<"\n";
    count=3;
  }
  else
  {
    cout<<"password is : "<<line<<"\n";
    count=0;
  }
  

 }
    
    return 0;
}