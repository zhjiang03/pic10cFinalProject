ifndef Map_H
#define Map_H

#include <string>

typedef std::string K_Type;
typedef double V_Type;
class Map
{ 
 private:

  struct Node
  {
    K_Type Key;
    V_Type Value;
    Node * Prev;
    Node* Next;
  };
  Node* head;
  int Size;


Node* find(const K_Type& key)const
{
  Node* p1 = head;
  while (p1!= nullptr)
    {
      if(p1->Key==key)return p1;
      p1= p1->Next;

    }
  return nullptr;
}

};

bool combine(const Map& M1, const Map& M2, Map& Result);

void subtract(const Map& M1, const Map& M2, Map& Result);

 public:
  Map();
  Map(const Map&other);
  Map& operator= (const Map&other);
  ~Map();
  bool empty() const;
  int  size() const;
  bool insert(const K_Type& key) const;
  bool get(const K_Type& key, V_Type& value) const;
  bool get(int i, K_Type& key, V_Type& value) const;
  bool insert(const K_Type& key, const V_Type& value);
  bool update(const K_Type& key, const V_Type& value);
  bool insertOrUpdate(const K_Type& key, const V_Type& value);
  bool erase(const K_Type& key);
  void swap(Map& b);

#endif
