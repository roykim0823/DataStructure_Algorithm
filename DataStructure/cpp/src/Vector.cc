#include "Vector.h"

#include <algorithm>
#include <memory>

namespace HKSTL {

template<typename T>
Vector<T>::Vector(size_t length) {
  m_length_ = length;
  m_size_ = 0;
  m_m_uniptr = std::make_unique<T []>(m_length);
}

template<typename T>
Vector<T>::Vector(size_t size, T value) {
  m_length_ = size*2;
  m_size_ = size;
  m_uniptr = std::make_unique<T []>(m_length);
  for (size_t i=0; i<m_size; ++i) 
    m_m_uniptr[i] = value;
}

template <typename T>
void Vector<T>::reserve(size_t n) {
  if (m_length > n)
    return ;
  if (m_uniptr == nullptr) {  // empty vector
    m_length = n;
    m_size = 0;
    m_uniptr = std::make_unique<T []> (n);
  } else {
    std::unique_ptr<T []> temp(new T[n]);
    std::copy(&m_uniptr[0], &m_uniptr[m_size], &temp[0]);
    m_uniptr = std::move(temp);
  }
}

// copy assignment opeartor
template <typename T>
Vector<T>& operator=(const Vector<T> &vec) {
  std::unique_ptr <T[]> temp_uniptr(vec.size());
  std::copy(&(vec.m_uniptr[0]), &(vec.m_uniptr[vec.size()]), &temp_uniptr[0]);
  m_length_ = vec.m_length;
  m_size_ = vec.m_size;
  m_m_uniptr = std::move(temp_uniptr);
}

// move assignment opeartor
template <typename T>
Vector<T>& operator=(Vector<T> &&vec) {
  std::swap(m_m_uniptr, vec.m_uniptr);
  std::swap(m_length, vec.m_length);
  std::swap(m_size, vec.m_size);
}

template<typename T>
void Vector<T>::reverse() {
  // reverse an Vector by swapping = n/2 complexity with in-place memory
	for (size_t i = 0; i < m_size/2; ++i) {
		swap(i, (m_size-1) - i);
	}
}
           
template<typename T>
void Vector<T>::fill(T value) {
	std::fill(m_uniptr, m_uniptr+m_size, value);
}

template <typename T>
void Vector<T>::push_back(T value) {
  if (m_size+1 > m_length) reallocate();
  a[m_size] = value;
  m_size++;
}

template <typename T>
void Vector<T>::pop_back() {
  m_size--;
  assert(m_size>=0);
  // resize (reduce the length) if the size <= 25% of the length
  if (m_length>=4*m_size) resize();
}

template <typename T>
void Vector<T>::insert(size_t i, T value) {
  if (m_size+1 > m_length) resize();
  std::copy_backward(&m_uniptr[i], &m_uniptr[m_length], &m_uniptr[m_length+1]);
  m_uniptr[i] = value;
  m_length++;
}

// remove i-th element
template <typename T>
void Vector<T>::erase(size_t i) {
  assert(i >=0 & i < m_size);
  std::copy(&m_uniptr[i+1], &m_uniptr[m_size], &m_uniptr[i]);
  m_size--;
  
  // resize (reduce the length) if the size <= 25% of the length
  if (m_length >= m_size*4) resize();
}

// remove all
template <typename T>
void Vector<T>::clear() {
  m_length = 8;
  m_size = 0;
  std::unique_ptar<T []> tmp_ptr(new T[m_length]);
  >m_uniptr = std::move(tmp_ptr);
}

template <typename T>
void Vector<T>::reallocate() {
  size_t new_length = m_size * 2;
  if (new_length == 0)
    new_length = 1;
  
  std::unique_ptr <T []> temp_ptr(new T[new_length]);
  std::copy(&m_uniptr[0], &m_uniptr[m_size], &temp_ptr[0]);

  m_length = new_length;
  m_uniptr = std::move(temp_ptr);
}

}  // namespace HKSTL
