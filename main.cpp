#include "Map.h"
#include <iostream>
#include <stdio.h>
#include <cassert>
using namespace std;

int main()
{
  K_Type k;
  V_Type v;
  Map M1;
    
  assert(M1.empty());             //check empty function
  M1.insert("a",1);
  assert(!M1.empty());
    
  assert((M1.size())==1);         //check size function
    
  assert(!(M1.insert("a",1)));    //check insert function
  assert((M1.size())==1);        
  M1.insert("b",2);               //check insert function
  assert((M1.size())==2);
    
  M1.insert("c",2);               //check erase function
  M1.erase("c");
  assert((M1.size())==2 && !(M1.contains("c")));
    
  assert(M1.contains("b"));       //check contains function
    
  M1.insertOrUpdate("a",3);       //check insertOrUpdate function
  M1.get("a",v);                  //check get function
  assert(v==3);
  M1.insertOrUpdate("c",2);
  assert((M1.size())==3);
  M1.get(0,k,v);                  //check get function with i
  assert(k=="c" && v==2);
    
    
  assert(!(m1.get(4,k,v)));
  Map M2;
  M2.insert("d", 1);
  M2.insert("e", 2);
  M2.insert("f", 3);
  M2.insert("a", 3);
    
  Map M3=M2;                      //check copy constructor
  assert(M1.get(0,k,v)==M2.get(0,k,v));
    
  M3=M1;                          //check assignment operator
  assert(M1.get(0,k,v)==M3.get(0,k,v));
    
  combine(M1, M2, M3);            //check combine function
  for (int i=0; i<m1.size(); i++)
    {
      M1.get(i,k,v);
      cout<<k<<"  "<<v<<endl;
    }
  cout<<endl;
  for (int i=0; i<M2.size(); i++)
    {
      M2.get(i,k,v);
      cout<<k<<"  "<<v<<endl;
    }
  cout<<endl;
  for (int i=0; i<M3.size(); i++)
    {
      M3.get(i,k,v);
      cout<<k<<"  "<<v<<endl;
    }
    
  M2.insertOrUpdate("a", 2);
  combine(M1, M2, M3);            //checks differing value keys 
    
  cout<<endl;
  for (int i=0; i<M3.size(); i++)
    {
      M3.get(i,k,v);
      cout<<k<<"  "<<v<<endl;
    }
    
  subtract(M1,M2,M3);             //check subtract function
  cout<<endl;
  for (int i=0; i<M3.size(); i++)
    {
      M3.get(i,k,v);
      cout<<k<<"  "<<v<<endl;
    }
}
