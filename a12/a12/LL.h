
#ifndef LL_hpp
#define LL_hpp


namespace cs11_linkedlist
{
	template<class T>
	class LL
	{
	public:
		typedef size_t size_type;
		typedef T value_type;

		LL();
		LL( const LL& listToCopy );
		LL operator=( const LL & listToAssign );
		~LL();
		bool empty() const;
		size_type size() const;
		void clear();
		void pop_front();
		void push_front( const value_type & x );
		value_type & front();
		const value_type & front() const;

	private:
		struct node
		{
			value_type data;
			node* next;
		};
		node* list;

		void copyList( const LL & listToCopy );
		node * last();
		const node * last() const;


	public:
		class iterator
		{
		public:
			iterator( node* initial = nullptr )
			{
				current = initial;
			}

			node& operator*() const
			{
				return *current;
			}

			node * operator->() const
			{
				return current;
			}

			iterator& operator++()
			{
				current = current -> next;
				return *this;
			}

			iterator operator++( int )
			{
				iterator original( current );
				current = current->next;
				return original;
			}

			bool operator==( iterator other ) const
			{
				return current == other.current;
			}

			bool operator !=( iterator other ) const
			{
				return current != other.current;
			}
		private:
			node* current;
		};

		class const_iterator
		{
		public:
			const_iterator( const node* initial = NULL )
			{
				current = initial;
			}

			const node& operator*() const
			{
				return *current;
			}

			const node * operator->() const
			{
				return current;
			}

			const_iterator& operator++()
			{
				current = current->next;
				return *this;
			}

			const_iterator operator++( int )
			{
				const_iterator original( current );
				current = current->next;
				return original;
			}

			bool operator==( const const_iterator other ) const
			{
				return current == other.current;
			}

			bool operator!=( const const_iterator other ) const
			{
				return current != other.current;
			}
		private:
			const node* current;
		};

		iterator begin()
		{
			return iterator( list );
		}

		iterator end()
		{
			return iterator( last() + 1 );
		}

		const_iterator begin() const
		{
			return const_iterator( list );
		}

		const_iterator end() const
		{
			return const_iterator( last() + 1 );
		}
	};		
}


#include "LL.cpp"

#endif /* LL_hpp */