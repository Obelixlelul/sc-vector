# sc::vector

sc::vector is a c++ library create by Rafael Fortunato to BASIC DATA STRUCTURE I at FEDERAL UNIVERSITY OF RIO GRANDE DO NORTE. 

Description:
  - The sc::vector library created works like std::vector.

Requisites:
  - C++ vesion +14
  - Cmake
 
  How to compile (follow the steps):
 - on terminal
```sh
$ cmake -S . -Bbuild
$ cd build
$ make
$ ./app
```

### Iterator Methods:
|  |  |
| ------ | ------ |
| void begin() | return iterator pointing to begin. |
| void end() | return iterator pointing to end. |
| void cbegin() | return a const iterator pointing to begin. |
| void cend() | return a const iterator pointing to end. |

### Capacity Methods:
|  |  |
| ------ | ------ |
| bool empty() | returns true if the container contains no elements, and false otherwise. |
| <size_type> size() | return size_type list size. |
| <size_type>capacity() | return size_type list capacity. |

### Modifiers methods:
|  |  |
| ------ | ------ |
| void clear() | remove (either logically or physically) all elements from the container. |
| void push_front (const T & value) | adds value to the top of the list. |
| void push_back(const T & value) | adds value at the end of the list. |
| void pop_front() | removes the object at the top of the list. |
| void pop_back() | removes the object at the end of the list. |
| iterator insert( iterator pos, const T & value ) | adds value into the list before the position given by the iterator pos . The method returns an iterator to theposition of the inserted item. |
| iterator insert( const_iterator pos, std::initializer_list<T> ilist ) | inserts elements from the initializer list ilist before pos . Initializer list supports the user of insert as in myList.insert( pos, {1, 2, 3, 4} ) , which would insert the ele-ments 1, 2, 3, and 4 in the list before pos , assuming that myList is a list of int . |
| void reserve( size_type new_cap ) | increase the storage capacity of the array to a value that’s is greater or equal to new_cap |
| void shrink_to_fit() | Requests the removal of unused capacity. |
| void assign( size_type count, const T& value ) | Replaces the contents with count copies of value value. |
| iterator erase( iterator pos )| removes the object at position pos. |
| iterator erase( iterator first, iterator last )| removes elements in the range [first; last]. |

### Element access methods:
|  |  |
| ------ | ------ |
| iterator front() | return iterator pointing to begin. |
| back() | return iterator pointing to end. |
| iterator at() | Returns a reference to the element at position n in the vector. |
| operator[] | possibility use list in format LIST[INDEX]. |

Want to contribute? Great!
 - Write MORE methods

License
----
**Free Software**

[rafael]: <https://github.com/Obelixlelul>
   
