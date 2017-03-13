
#pragma once
#include <iostream>

namespace hu_test { 
template<class T>
struct SingleNode {
    SingleNode();
    SingleNode(const T& data):_data(data),_next_node(NULL) {
    }
    SingleNode(const T& data,SingleNode<T>* _pnext);
    ~SingleNode();
    //
    const T& GetNodeData()const { return _data; }
    SingleNode<T>* GetNext()const { return _next_node; }
    void SetNext(SingleNode<T>* next) {
        _next_node = next;
    }
    T _data;
    SingleNode<T>* _next_node;
};

template <class T>
class SingleList {
  public:
    class Iterator {
      public:
        friend class SingleList<T>;
        
        Iterator();
        Iterator(SingleNode<T>* node);
        virtual ~Iterator();
        //
        bool operator == (const Iterator& iter);
        bool operator != (const Iterator& iter);
        Iterator& operator= (const Iterator& iter);
        const T& operator *() const;
        Iterator operator ++();
      protected:
        SingleNode<T>* _cur;   
    };
  public:
    virtual Iterator Find(const T& dat) const;
    virtual Iterator Insert(Iterator iter,const T& dat);
    virtual Iterator Erase(Iterator iter);
    virtual Iterator Begin();
    virtual Iterator End();
  public:
    SingleList();
    virtual ~SingleList();
    bool push_back_node(const T& _data);
    bool push_head_node(const T& _data);
    int GetSize()const;
    //
    bool pop_head_node(SingleNode<T>* _node) {return true;}
    bool pop_back_node(SingleNode<T>* _node) {return true;}
    operator std::string() const;
  private:
    SingleNode<T>* _head; 
};

}

#include "singlelist.inl"

