#include <iostream>
#include <sstream>
namespace hu_test {

template<class T>
SingleNode<T>::SingleNode():_next_node(nullptr) {
  //
}

template<class T>
SingleNode<T>::SingleNode(const T& data, SingleNode<T>* _pnext) {
  _data = data;
  _next_node = _pnext;
}
//

template<class T>
SingleNode<T>::~SingleNode() {
  _next_node = nullptr;
}
//
//
template<class T>
SingleList<T>::SingleList(): _head(new SingleNode<T>()) {
  
}

template<class T>
SingleList<T>::~SingleList() {
  SingleNode<T> *node = _head;
  while(node != nullptr) {
    SingleNode<T> *now_node = node;
    node = now_node->_next_node;
    delete now_node;
  }
  _head = nullptr;
 std::cout << "deconstruct for single list done" << std::endl;
}

template<class T>
int SingleList<T>::GetSize()const {
  SingleNode<T>* pnext = _head->_next_node;
  int i = 0;
  while(pnext != nullptr) {
   ++i; 
   pnext  = pnext->_next_node;
  }
  return i;
}


template<class T>
bool SingleList<T>::push_back_node(const T& _data) {
  SingleNode<T>* new_node  = new SingleNode<T>(_data,nullptr); 
  SingleNode<T>* phead = _head; 
  while(phead->_next_node != nullptr) {
    phead = phead->_next_node;
  }
  phead->_next_node = new_node;
  return true;
}

template<class T>
bool SingleList<T>::push_head_node(const T& _data) {
  SingleNode<T>* new_node  = new SingleNode<T>(_data,nullptr);
  SingleNode<T>* next_data = _head->_next_node;

  _head->_next_node = new_node;
  if (next_data != nullptr) {
    new_node->_next_node = next_data;
  } 
  return true;
}

template<class T>
SingleList<T>::operator std::string() const {
  std::ostringstream ss;
  SingleNode<T> *node = _head->_next_node; 
  while (node != nullptr) {
    ss << ", " << node->GetNodeData();
    node  = node->_next_node;
  }
  return ss.str();
}

template<class T>
typename SingleList<T>::Iterator SingleList<T>::Find(
    const T& dat) const {
  SingleNode<T>* tmp_node = _head;
  while(tmp_node) {
    if (tmp_node->GetNodeData() == dat) {
      return tmp_node;
    }
    tmp_node = tmp_node->GetNext();
  }
  return NULL;
}

template<class T>
typename SingleList<T>::Iterator SingleList<T>::Insert(
    SingleList<T>::Iterator iter,
    const T& dat) {
  SingleNode<T>* cur_node = iter._cur;
  if (cur_node == NULL) {
    return NULL;
  }
  T data = cur_node->GetNodeData();
 
  SingleNode<T>* tmp_node = _head;
  SingleNode<T> *pre_node = _head;
  while(tmp_node) {
    if (tmp_node->GetNodeData() == data) {
      SingleNode<T>* new_node = new SingleNode<T>(dat);
      if (tmp_node == _head) {
        new_node->SetNext(_head);
        _head =  new_node;
        return _head;
      }

      new_node->SetNext(tmp_node);
      pre_node->SetNext(new_node);
      return new_node;
    }
    pre_node  = tmp_node;
    tmp_node = tmp_node->GetNext();
  }
  if (tmp_node == NULL) {
    return NULL;
  }
}

template<class T>
typename SingleList<T>::Iterator SingleList<T>::Erase(
    SingleList<T>::Iterator iter) {
  SingleNode<T>* cur_node = iter._cur;
  if (cur_node == NULL) {
    return NULL;
  }
  T data = cur_node->GetNodeData();

  SingleNode<T>* tmp_node = _head;
  SingleNode<T> *pre_node = _head;
  while(tmp_node) {
    if (tmp_node->GetNodeData() == data) {
      if (tmp_node == _head) {
        _head = _head->GetNext();
        delete tmp_node;
        return _head;
      }
      pre_node->SetNext(tmp_node->GetNext());
      delete tmp_node;
      return pre_node->GetNext();
    }
    pre_node = tmp_node;
    tmp_node = tmp_node->GetNext();
  }
  return NULL;
}

template<class T>
typename SingleList<T>::Iterator SingleList<T>::Begin() {
  return _head; 
}

template<class T>
typename SingleList<T>::Iterator SingleList<T>::End() {
  return  NULL;
}


//////////////////////////////
template<class T>
SingleList<T>::Iterator::Iterator():_cur(NULL) {
 // 
}

template<class T>
SingleList<T>::Iterator::Iterator(SingleNode<T>* node):
_cur(node) {

}

template<class T>
SingleList<T>::Iterator::~Iterator() {
  _cur = NULL;
}

template<class T>
bool SingleList<T>::Iterator::operator == (
    const Iterator& iter) {
  return _cur == iter._cur;
}

template<class T>
bool SingleList<T>::Iterator::operator != (
    const Iterator& iter) {
  return !(*this == iter);
}

template<class T>
typename SingleList<T>::Iterator& SingleList<T>::Iterator::operator= (
    const Iterator& iter) {
  _cur = iter._cur;
  return *this;
}

template<class T>
const T& SingleList<T>::Iterator::operator *() const {
  if (_cur) {
    return _cur->GetNodeData();
  }
  throw std::string("iter not been init");
}

template<class T>
typename SingleList<T>::Iterator SingleList<T>::Iterator::operator ++() {
  if (_cur == NULL) {
    return NULL;
  }
  if (_cur->GetNext() == NULL) {
    _cur = NULL;
    return NULL;
  }else {
  _cur = _cur->GetNext();
  }
  return *this;
}
//
}
