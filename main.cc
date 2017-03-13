#include "singlelist.h"
using namespace  hu_test;

int main() {
  SingleList<int>* slist = new SingleList<int>();
  slist->push_back_node(1);
  slist->push_back_node(2);
  slist->push_back_node(3);
  std::cout << slist->GetSize() << std::endl;
  std::cout << "val: " << std::string(*slist) << std::endl;
  
  slist->push_head_node(4);
  slist->push_head_node(5);
  slist->push_head_node(6);

  std::cout << "val: " << std::string(*slist) << std::endl;

  SingleList<int>::Iterator it = slist->Begin();
  for (; it != slist->End(); ++it) {
    std::cout << "data: " << *it << std::endl;
  }
  SingleList<int>::Iterator it_find = slist->Find(3);
  if (it_find != slist->End()) {
    std::cout << "find node in slist, value: " << *it_find << std::endl;
  }
  int insert_val = 100;
  std::cout << "insert 100 at 3 node" << std::endl;
  SingleList<int>::Iterator insert_it = slist->Insert(it_find, 100);
  std::cout << "insert iter val: " << *insert_it << std::endl;
  for (auto iter_search = slist->Begin(); 
      iter_search != slist->End(); ++iter_search) {
    std::cout << "val: " << *iter_search << std::endl;
  }
  //
  std::cout << "erase 100 node" << std::endl;
  SingleList<int>::Iterator erase_it = slist->Erase(insert_it);
  std::cout << "now next 100 node value: " << *erase_it << std::endl;
  for (auto iter_search = slist->Begin(); 
      iter_search != slist->End(); ++iter_search) {
    std::cout << "val: " << *iter_search << std::endl;
  }

  delete slist ;
  return 0;
}

