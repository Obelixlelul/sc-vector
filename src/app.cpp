#include <iostream> //std::cout std::endlw
#include <cassert>
#include <string>
#include "../include/array.h"

using std::cout;
using std::endl;

//!< OPERATOR TO PRINT ARRAY OBJECT
template <typename T, size_t SIZE>
std::ostream &operator << (std::ostream &os, const sc::vector<T, SIZE> &a)
{
  os << "[ ";
  for (auto i{0}; i < a.INTERNAL_SIZE; ++i)
  {
    os << a.data[i] << " ";
  }
  os << "]";

  return os;
}

//!< MAIN FUNCTION
int main(void)
{
  sc::vector<int, 10> A{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //init list constructor
  sc::vector<int, 10> B;                                    //default constructor
  sc::vector<int, 10> C(A);                                 //copy constructor
  sc::vector <int, 10> D(10);

  B = {1,2,3,4,5,6,7,8,9,10}; // operador de atribuicao;


  cout << "VECTORS CREATED:\n";
  std::cout << ">>> Vetor A: " << A << std::endl;
  std::cout << ">>> Vetor B: " << B << std::endl;
  std::cout << ">>> Vetor C: " << C << std::endl;
  std::cout << ">>> Vetor D: " << D << std::endl;
  cout << "\n";
  
  cout << "TESTING Begin() and End()..\n";
  auto myIterator = A.begin();
  auto myConstIterator = A.cbegin();
  cout << "A.begin() adress = " << myIterator << endl;
  cout << "A.begin() value = " << *myIterator << endl;
  cout << "A.end() adress = " << A.end() << endl;
  cout << "A.end()-1 value = " << *(A.end()-1)  << endl;
  cout << "\n";
  
  std::cout << "STARTING PUSHS AND POPS...\n";
  A.push_back(16);
  std::cout << ">>> A.pushback(16): " << A << std::endl;
  
  A.pop_back();
  std::cout << ">>> A.popback(): " << A << std::endl;
 
  A.push_front(16);
  std::cout << ">>> A.push_front(16): " << A << std::endl;

  A.pop_front();
  std::cout << ">>> A.pop_front(16): " << A << std::endl;
  cout << "\n";

  std::cout << "Is empty? A.empty() = " << A.empty() <<endl;
  std::cout << "What size? A.size() = " << A.size() <<endl;
  
  std::cout << "A.capacity = " << A.capacity() << endl;
  std::cout << "reserving 15 with A.reserve(15)"<< endl;
  A.reserve(15);
  cout << "A.capacity = " << A.capacity() << endl;
  
  cout << "A.shrink_to_fit()\n";
  A.shrink_to_fit();
  cout << "A.capacity after shrink = " << A.capacity() << endl;
  cout << endl;
  
  auto tempIteratorL = A.data + 2; //point to 3

  std::cout << "TESTING INSERT\n";
  std::cout << ">>> Vetor A: " << A << std::endl;
  std::cout << "[step 1] Iterator poiting to 3\n";
  std::cout << "[step 2] INSERT(iterator, {99, 100, 101, 102, 103})\n";
  A.insert(tempIteratorL, {99, 100, 101, 102, 103});
  std::cout << ">>> Vetor A: " << A << std::endl;
  cout << endl;

  cout << "TESTING RESERVE\n";
  cout << "A.capacity() = " << A.capacity() << endl;
  cout << "A.size() = " << A.size() << endl;
  cout << "A.reserve(50)" << endl;
  A.reserve(50);
  cout << "A.capacity() = " << A.capacity() << endl;
  cout << "A.size() = " << A.size() << endl;
  cout << "A.shrink_to_fit()" << endl;
  A.shrink_to_fit();
  cout << "A.capacity() = " << A.capacity() << endl;
  cout << "A.size() = " << A.size() << endl;
  cout << endl;


  auto left = A.begin()+3;
  auto right = left + 6;

  cout << "TESTING ERASE 2 ARGS\n";
  cout << "erase [" << *left << "..."<<*right << "]"<< endl;
  std::cout << ">>> Vetor A: " << A << std::endl;
  cout << "A.erase(left, right)\n";
  A.erase(left, right);
  std::cout << ">>> Vetor A: " << A << std::endl;
  cout << endl; 

  cout << "TESTING ERASE 1 ARG\n";
  std::cout << ">>> Vetor A: " << A << std::endl;
  left = A.begin() + 5;
  std::cout << "left pointing to" << *left << std::endl;
  std::cout << "removing left from list A\n";
  cout << "A.erase(left)\n";
  A.erase(left);
  std::cout << ">>> Vetor A: " << A << std::endl;
  std::cout << std::endl;

  std::cout << "TESTING FRONT AND BACK\n";
  std::cout << ">>> A.front(): " << *A.front() << std::endl;
  std::cout << ">>> A.back(): " << *A.back() << std::endl;
  std::cout << std::endl;

  std::cout << "TESTING CLEAR\n";
  std::cout << "A.clear()\n";
  A.clear();
  std::cout << "Is empty? A.empty() = " << A.empty() <<endl;
  A.push_back(16);
  std::cout << "A.pushback(16)"<< std::endl;
  std::cout << ">>> Vetor A: " << A << std::endl;


  

  
  return 0;
}