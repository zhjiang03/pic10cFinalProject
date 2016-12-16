#include "Map.h"
#include <iostream>
#include <string>
#include <cstdlib>


//default constructor 
Map::Map()
{
  head = nullptr;
  m_size =0;
   
}

//copy constructor
Map::Map(const Map&other)
{
  m_size=0;
  head = nullptr;
  if(other.head==nullptr)
    {
      return;
    }
  K_Type k;
  V_Type v;
 
  for (int i=other.size()-1; i>=0; i--)
    {
      other.get(i,k ,v);
      insert(k,v);
    }
}

Map& Map::operator= (const Map&other)
{
  if (this != &other)
    {
      Map temp = other;
      swap(temp);
    }
  return *this;
}

Map::~Map()
{
  Node* p = head;
  while (p!= nullptr)
    {
      Node* temp = p->Next;
      delete p;
      p = temp;
    }
  head = nullptr;
}

bool Map::empty() const
{
  return (Size==0);
}

int Map::size() const
{
  return Size;
}

bool Map::contains (const K_Type& key)const
{
  return find(key)!=nullptr;
}

bool Map::get(const K_Type& key, V_Type& value)const
{
  Node* p = find(key);
  if (p == nullptr){
    return false;
  else 
    value = p->Value;
    return true;
  }
}

bool Map::get(int i, K_Type& key, V_Type& value)const
{
  if (i<0 || i>=Size) return false;

  int count = 0;
  Node* p = head;
  while(p!=nullptr && count<i)
    {
      p = p->Next;
      count++;
    }
  key = p->Key;
  value = p->Value;
  return true;
}

bool Map::insert(const K_Type& key, const V_Type& value)
{
  if(find(key) != nullptr) return false;
    
  Node* N = new Node;
  add->Key = key;
  add->Value = value;
  add->Next = head;
  add->Prev = nullptr;
    
  if(head!=nullptr)
    head->Prev = add;
  head = add;
    
  //update size
  Size++;
  return true;
    
}

bool Map::update(const K_Type& key, const V_Type& value)
{
  //check node
  Node* n = find(key);
  if (n == nullptr) return false;
    
  //update node
  n->Value = value;
    
  return true;
}

bool Map::insertORupdate(const K_Type& key, const V_Type& value)
{
  //check if key exists to be updated, if not then insert
  if (update(key,value))return true;
  else return insert(key,value);
}

bool Map::erase(const K_Type& key)
{
  //check if there is a key to rm
  Node* p = find(key);
  if (p == nullptr) return false;
    
  //update surrounding nodes
  Node* before = p->Prev;
  Node* after = p->Next;
  //check first element 
  if (before!=nullptr)
    before->Next = after;
  else
    head = after;
  //check last element
  if (after!= nullptr)
    after->Prev = before;
    
  delete p;
    
  Size--;
  return true;
}

void Map::swap(Map& b)
{
  int tempSize = size();
  Node* tempPrev = head;
    
  Size = b.Size;
  head = b.head;
  b.Size = tempSize;
  b.head = tempPrev;
    
}


bool combine (const Map& M1, const Map& M2, Map& Result)
{
  //check if empty
  if (M1.empty())
    {
      result = M2;
      return true;
    }else if (M2.empty())
    {
      result = M1;
      return true;
    }else
    {
      bool diff=false;
      Map temp = M1;
      for (int i = 0 ;i<M2.Size() ; i++)
        {
	  K_Type key;
	  V_Type value;
	  M2.get(i,key,value);
	  if (!temp.check_key(key))
            {
	      //add key to temp
	      temp.insert(key,value);
            }
	  else
            {
	      V_Type v;
	      M1.get(key,v);
	      //if same diff, remove key
	      if (v!=value)
                {
		  temp.rm(key);
		  diff=true;
                }
            }
        }
      //update result 
      result.swap(temp);
      return !diff;
    }
}

void subtract(const Map&M1, const Map& M2, Map& Result)
{
  if (M1.empty() || M2.empty())
    {
      result=M1;
      return;
    }
    
  Map temp = M1;
    
  for(int i =0; i<m1.size(); i++)
    {
      K_Type key;
      V_Type value;
      M1.get(i,key,value);
        
      if (M2.check_key(key)) temp.rm(key);
    }
  //update result
  result.swap(temp);
}
