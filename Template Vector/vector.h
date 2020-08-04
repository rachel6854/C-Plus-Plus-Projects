#include <cstddef>/*for size_t*/
#include <stdexcept>/*for out_of_range*/

template <typename T> 
class Vector
{
public:
	typedef T * iterator;
	typedef const T* const_iterator;
	
	/*empty*/explicit Vector();
	/*fill*/explicit Vector(size_t n, const T& val);
	/*copy*/Vector (const Vector& other);
	~Vector();
	Vector& operator=(const Vector& other);
	size_t size() const;
	size_t max_size() const;
	void resize (size_t n, const T& val = T());
	size_t capacity() const;
	bool empty() const;
	void reserve (size_t n);
	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	T& at (size_t n);
	const T& at (size_t n) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	T* data() /*noexcept*/ throw();
	const T* data() const /*noexcept*/ throw();
	void assign (size_t n, const T& val);
	void push_back (const T& val);
	void pop_back();
	iterator insert (iterator position, const T& val);	
	void insert (iterator position, size_t n, const T& val);
	iterator erase (iterator first, size_t count=1);
	void swap (Vector<T>& x);
	void clear();
	Vector& operator+(const Vector& other);
	Vector& operator+=(const Vector& other);
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	bool operator==(const Vector<T>& other) const;

private:
	T *m_arr;
	size_t m_size;
	size_t m_capacity;

};


template <typename T>
inline Vector<T>::Vector():
	m_arr(NULL) ,
	m_size(0),
	m_capacity(0)
{}

template <typename T>
inline Vector<T>::Vector (size_t n, const T& val /*=T()*/):
	m_arr(NULL),
	m_size(n),
	m_capacity(m_size)
{
	m_arr = new T [size()];
	
	for(size_t i=0;i<size();++i)
	{
		m_arr[i]=val;
	}
}

template <typename T>
inline Vector<T>::Vector (const Vector& other):
	m_arr(NULL),
	m_size(other.size()),
	m_capacity(other.capacity())
{
	m_arr = new T [other.size()];
	
	for(size_t i=0;i<m_size;++i)
	{
		m_arr[i]=other[i];
	}
}

template <typename T>
inline Vector<T>::~Vector()
{
	if(m_arr)
		delete[] m_arr;
	m_arr=NULL;
}

template <typename T>
inline Vector<T>& Vector<T>::operator=(const Vector& other)
{
	size_t size=other.size();
	T *tmp=new T[size]; 
	
	for(size_t i=0;i<size;++i)
	{
		tmp[i]=other[i];
	}
	if(m_arr)
		delete [] m_arr;
	m_arr=tmp;

	m_size=size;
	m_capacity=other.capacity();
	
	return *this;
}

template <typename T>
inline size_t Vector<T>::size() const
{
	return m_size;
}

template <typename T>
inline size_t Vector<T>::max_size() const
{
	return 0;
}


template <typename T>
inline void Vector<T>::resize (size_t n, const T& val /*= value_type()*/)
{

	reserve(n);
	for(size_t i=size();i<n;++i)
	{
		m_arr[i]=val;
	}
	
	m_size=n;
	m_capacity=n;

}

template <typename T>
inline size_t Vector<T>::capacity() const
{
	return m_capacity;
}

template <typename T>
inline bool Vector<T>::empty() const
{
	return m_size==0;
}

template <typename T>
inline void Vector<T>::reserve (size_t n)
{
	if (n>capacity())
	{
	
		T *tmp=new T[n];	
		for(size_t i=0;i<m_size;++i)
		{
			tmp[i]=m_arr[i];
		}
			
		if(m_arr)
			delete[] m_arr;
		m_arr=tmp;
		m_capacity=n;
	}
}

template <typename T>
inline T& Vector<T>::operator[] (size_t n)
{

	return m_arr[n];
}

template <typename T>
inline const T& Vector<T>::operator[] (size_t n) const
{

	return m_arr[n];
}

template <typename T>
inline T& Vector<T>::at(size_t n)
{
	if(n>=m_size||n<0)
		throw std::out_of_range("index out of range");
	return (*this)[n];
}

template <typename T>
inline const T& Vector<T>::at(size_t n) const
{
	if(n>=m_size||n<0)
		throw std::out_of_range("index out of range");
	return *this[n];
}

template <typename T>
inline T& Vector<T>::front()
{
	return *this[0];
}

template <typename T>
inline const T& Vector<T>::front() const
{
	return *this[0];
}

template <typename T>
inline T& Vector<T>::back()
{
	return *this[size()-1];
}

template <typename T>
inline const T& Vector<T>::back() const
{
	return *this[size()-1];
}

template <typename T>
inline T* Vector<T>::data() throw()
{
	return m_arr;
}

template <typename T>
inline const T* Vector<T>::data() const throw()
{
	return m_arr;
}

template <typename T>
inline void Vector<T>::assign (size_t n, const T& val)
{
	*this=Vector<T>(n,val);
}


template <typename T>
inline void Vector<T>::push_back (const T& val)
{
	resize(size()+1,val);
}

template <typename T>
inline void Vector<T>::pop_back()
{
	resize(size()-1);
}

template <typename T>
inline typename Vector<T>::iterator Vector<T>::insert (iterator position, const T& val)
{
	insert(position,1,val);
	return m_arr[position];
}

template <typename T>	
inline void Vector<T>::insert(iterator position, size_t n, const T& val)
{

	size_t p=position-begin();
	reserve(size()+n);
	
	for(size_t index=size()-1+n;index>p+n;--index)
		m_arr[index]=m_arr[index-n];
		
	for(size_t index=p;index<p+n;++index)
		m_arr[index]=val;
		
	m_size+=n;
}

template <typename T>	
inline typename Vector<T>::iterator Vector<T>::erase (iterator first,size_t count)
{
	size_t p=first-m_arr;
	for(size_t index=p;index<p+count&&index<size();++index)
		m_arr[index]=m_arr[index+count];

	resize(size()-count);
	
	return first;
}

template <typename T>
inline void Vector<T>::swap (Vector<T>& x)
{
	Vector<T> tmp=*this;
	*this=x;
	x=tmp;
}

template <typename T>
inline void Vector<T>::clear()
{
	if(m_arr)
	{
		delete[] m_arr;
		m_arr=NULL;
	}
	m_size=0;
	m_capacity=0;
}

template <typename T>
inline Vector<T>& Vector<T>::operator+(const Vector& other)
{
	T* tmp=new T[size()+other.size()];
	size_t i;
	
	for(i=0;i<size;++i)
	{
		tmp[i]=m_arr[i];
	}
	
	for(;i<other.size();++i)
	{
		tmp[i]=other.data()[i];
	}
	
	delete[] m_arr;
	m_arr=tmp;
	
	m_size+=other.size();
	m_capacity=m_size;
	
	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::operator+=(const Vector& other)
{
	return *this=*this+other;

}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, Vector<T> const &vector) 
{ 
	return os << vector.data();
}


template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return m_arr;
}

template <typename T>
inline typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return m_arr;
}

template<typename T>
inline typename Vector<T>::iterator Vector<T>::end()
{
	return m_arr + size();
}

template <typename T>
inline typename Vector<T>::const_iterator Vector<T>::end() const
{
    return m_arr+size();
}

template <typename T>
inline bool Vector<T>::operator==(const Vector<T>& other) const
{
	bool flag=true;
	
	for(size_t i=0;i<size();++i)
		if(m_arr[i]!=other[i])
		{
			flag=false;
			break;
		}
		
	return size()==other.size()&&capacity()==other.capacity()&&flag;
}

