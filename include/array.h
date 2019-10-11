#ifndef ARRAY_H
#define ARRAY_H

#include <cstdlib>
#include <initializer_list> //std::initializer_list
#include <algorithm>        //std::copy

namespace sc
{
	template <typename T, size_t SIZE>
	class vector
	{
		private:
		//
		public:
		T* data = new T[SIZE]; //!< Area de armazenamento
		size_t CAPACITY = SIZE;
		size_t INTERNAL_SIZE = SIZE;

		T* it;

		//!< 1 - Default constructor that creates empty list
		vector()
		{
			for (int i{0}; i < SIZE; i++)
			{
			data[i] = T(); //chamou construtor padrao
			}
			it = data+SIZE;
		};
		
		//<! 2 - Constructs the list whith count default0inserted instances of T
		vector(size_t count){
			for (int i{0}; i < SIZE; i++)
			{
			data[i] = count; //chamou construtor padrao
			}
			it = data+SIZE;
		}

		//<! 3 -Constructs the list with the contents of the range (first, last)
		template <typename InputIt>
		vector(const InputIt &first, const InputIt &last){
			while (first != last){
				*data = *first;
				++first;
				++data;
			}
			it = data+SIZE;
		}

		//<! 4 - Constructs the list with the deep copy of the contents of other.
		vector(const vector& other){
			for(int i = 0; i < SIZE; i++){
				data[i] = other[i];
			}
			it = data+SIZE;
		}

		//<! 5 - Constructs list with the contents of the inicializater list init+
		vector(const std::initializer_list<T> &il)
		{ //constructor com lista inicializadora
			std::copy(il.begin(), il.begin() + std::min(SIZE, il.size()), data);
			it = data+SIZE;
		}

		//!< Destructs the list
		~vector(){
			delete[] data;
		}

		/**
		 * Replaces the contents with a copy of the contents of other.
		*/
		vector& operator = (const vector& other)
		{
			for(int i = 0; i < SIZE; i++){
				data[i] = other[i];
			}
			return other;
		}

		/**
		 * Replaces the contents with those identified by initializer list ilist.
		*/
		vector& operator = (std::initializer_list<T> il)
		{
			std::copy(il.begin(), il.begin() + std::min(SIZE, il.size()), data);
		}

		//>>>ITERATOR METHODS

		/**
		 * return iterator pointing to begin.
		*/
		T* begin(){
			return data;	
		}

		/**
		 * return iterator pointing to end.
		*/
		T* end(){
			return data+SIZE;
		}

		/**
		 * return a const iterator pointing to begin.
		*/
		const T* cbegin(){
			return data;
		}

		/**
		 * return a const iterator pointing to end.
		*/
		const T* cend(){
			return data+SIZE;
		}

		//>>>CAPACITY METHODS

		/**
		 * returns true if the container contains no elements, and false otherwise.
		*/
		bool empty(){
			return(INTERNAL_SIZE == 0 );
		}

		/**
		 * return size_t list size.
		*/
		size_t size()
		{
			return INTERNAL_SIZE;
		}

		/**
		 * return size_type list capacity.
		*/
		size_t capacity()
		{
			return CAPACITY;
		}

		//>>>MODIFIER METHODS
		
		/**
		* remove (either logically or physically) all elements from the container.
		*/
		void clear()
		{
			it = data;
			INTERNAL_SIZE = 0;
		}

		/**
		* adds value to the top of the list.
		*/
		void push_front(const T& value)
		{
			T* temp = new T[INTERNAL_SIZE+1];
			temp[0] = value;
			auto leftTemp = temp;
			leftTemp++;

			for(int i = 0; i < INTERNAL_SIZE; i++){
				*leftTemp = data[i];
				leftTemp++;
			}

			++INTERNAL_SIZE;
			data = new T[INTERNAL_SIZE];
			
			for(int i = 0; i < INTERNAL_SIZE; i++){
				data[i] = temp[i];
			}
			
			delete[] temp;
			it = data+INTERNAL_SIZE;
			++CAPACITY;
		}

		/**
		* adds value at the end of the list.
		*/
		void push_back(const T& value){
			T* temp = new T[INTERNAL_SIZE+1];
			auto tempIterator = temp+INTERNAL_SIZE;
			*tempIterator = value;
			tempIterator = temp;
	
			for(int i = 0; i < INTERNAL_SIZE; i++){
				*tempIterator = data[i];
				tempIterator++;
			}

			++INTERNAL_SIZE;
			data = new T[INTERNAL_SIZE];
			
			for(int i = 0; i < INTERNAL_SIZE; i++){
				data[i] = temp[i];
			}
			
			delete[] temp;
			it = data+INTERNAL_SIZE;
			++CAPACITY;
		}

		/**
		* removes the object at the top of the list.
		*/
		void pop_front(){
			T* temp = new T[INTERNAL_SIZE-1];
			auto tempIterator = temp;
			

			for(int i = 1; i < INTERNAL_SIZE; i++){
				*tempIterator = data[i];
				++tempIterator;
			}

			--INTERNAL_SIZE;
			data = new T[INTERNAL_SIZE];
			
			for(int i = 0; i < INTERNAL_SIZE; i++){
				data[i] = temp[i];
			}
			
			delete[] temp;
			--it;
		}

		/**
		* removes the object at the end of the list.
		*/
		void pop_back(){
			it--;
			INTERNAL_SIZE--;
		}
		
		/**
		* adds value into the list before the position given 
		* by the iterator pos . The method returns an iterator 
		* to theposition of the inserted item.
		*/
		template <typename R>
		void insert(R pos, const std::initializer_list<T> &il){
			
			auto qtd_list_il = il.end() - il.begin();
			auto qtd_data = it - data;
			auto qtd_total = qtd_data + qtd_list_il;

			T* temp = new T[qtd_total];
			auto tempIterator = temp;
			auto dataIterator = data;
			
			auto ilBeginIterator = il.begin();
			auto ilEndIterator = il.end();

			while(dataIterator != pos){
				*tempIterator = *dataIterator;
				++tempIterator;
				++dataIterator;
				
			}

			while(ilBeginIterator != ilEndIterator){
				*tempIterator = *ilBeginIterator;
				++tempIterator;
				++ilBeginIterator;
			}

			while(dataIterator != it){
				*tempIterator = *dataIterator;
				++tempIterator;
				++dataIterator;
			}
		
						
			data = new T[qtd_total];
			INTERNAL_SIZE = qtd_total;
			CAPACITY = INTERNAL_SIZE;
			
			for(int i = 0; i < qtd_total; i++){
				data[i] = temp[i];
			}

			delete[] temp;
			it = data + qtd_total;
		}
		
		
		/**
		* increase the storage capacity of the 
		* array to a value that’s is greater or equal to new_cap
		*/
		void reserve(size_t value){
			if (value < CAPACITY){
				return;
			}

			T* temp = new T[value];

			for(int i = 0; i < INTERNAL_SIZE; i++){
				temp[i] = data[i];
			}

			data = new T[value];
			CAPACITY = value;
			
			for(int i = 0; i < INTERNAL_SIZE; i++){
				data[i] = temp[i];
			}

			delete[] temp;
			it = data+INTERNAL_SIZE;
		}

		/**
		* Requests the removal of unused capacity.
		*/
		void shrink_to_fit(){
			T* temp = new T[INTERNAL_SIZE];

			for(int i = 0; i < INTERNAL_SIZE; i++){
				temp[i] = data[i];
			}

			data = new T[INTERNAL_SIZE];

			for(int i = 0; i < INTERNAL_SIZE; i++){
				data[i] = temp[i];
			}

			CAPACITY = INTERNAL_SIZE;
			it = data + INTERNAL_SIZE;

		}
		
		/**
		* Replaces the contents with count copies of value value.
		*/
		void assign(size_t n, const T& value)
		{
			data = new T[n];
			for(int i = 0; i < n; i++){
				data[i] = value;
			}
			it = data+n;
		}

		/**
		* removes the object at position pos.
		*/
		template <typename R>
		void erase(R& value)
		{
			while(value != it){
				auto temp = value+1;
				*value = *temp;
				++value;
			}
			--it;
			--INTERNAL_SIZE;
		}

		/**
		* removes elements in the range [first; last].
		*/
		template <typename R>
		void erase(R& value, R& value2)
		{
			auto TiT = value2 + 1;
			int qtd = it - value2 - 1;
			
			for(int i = 0; i < qtd; i++){
				*value = *TiT;
				++value;
				++TiT;
			}

			it = value + 2;
			INTERNAL_SIZE -= qtd;
		}

		//>>>ELEMENT ACCESS METHODS
		/**
		* return iterator pointing to begin.
		*/
		T* front(){
			return data;
		}

		/**
		* return iterator pointing to end.
		*/
		T* back(){
			return (it-1);
		}

		/**
		* Returns a reference to the element at position n in the vector.
		*/
		T* at(size_t n){
			return data + n;
		}

		/**
		* possibility use list in format LIST[INDEX].
		*/
		const T& operator [] (size_t idx) const
		{
			return data[idx];
		}

	}; // END_vector
} // namespace sc

// OPERATORS
	
	/**
	 * Compare if two lists match.
	*/
	template <typename T>
	bool operator == (T a, T b){
		if(a.size() != b.size()){
			return false;
		}

		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i]){
				return false;
			}
		}
		return true;
	}
	
	/**
	 * Compare if two lists don't match.
	*/
	template <typename T>
	bool operator != (T a, T b){
		if(a.size() != b.size()){
			return true;
		}

		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i]){
				return true;
			}
		}
		return false;
	}
	
#endif


