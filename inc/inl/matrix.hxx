#include <memory>
#include <iostream>
#include <iostream>
#include <algorithm>
#include "matrix.hpp"
namespace advcpp{
template<typename T>
Matrix<T>::Matrix(unsigned int a_rows, unsigned int a_columns)
: m_rows(a_rows)
, m_columns(a_columns)
, m_matrix(new T[m_rows * m_columns])
{}

template<typename T>
Matrix<T>::Matrix(const Matrix& a_other)
: m_rows(a_other.m_rows)
, m_columns(a_other.m_columns)
, m_matrix(new T[m_rows * m_columns])
{
    T* first = a_other.m_matrix ;
    T* last = a_other.m_matrix + m_rows*m_columns;
    std::copy(first, last, m_matrix);
}

template <typename T>
Matrix<T>::~Matrix(){
    delete[] m_matrix;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& a_other)
{
    if (this != &a_other) {
        T* temp = new T[a_other.m_rows * a_other.m_columns];
        T* first = a_other.m_matrix ;
        T* last = a_other.m_matrix + m_rows*m_columns;
        std::copy(first, last, temp);
        delete[] m_matrix;
        m_rows = a_other.m_rows;
        m_columns = a_other.m_columns;
        m_matrix = temp; 
    }
    return *this;
}


template<typename T>
unsigned int Matrix<T>::Rows()const{
    return m_rows;
}

template<typename T>
unsigned int Matrix<T>::Columns()const{
    return m_columns;
}


template<typename T>
T Matrix<T>::at(unsigned int a_row, unsigned int a_column) const{
    if(a_row > m_rows || a_column > m_columns) {
        throw(std::invalid_argument("the index out of the range"));
    }
    return m_matrix[a_row * m_columns + a_column];
}

template<typename T>
void Matrix<T>::Member(unsigned int a_row, unsigned int a_column, T& a_member) const{
    if(a_row > m_rows || a_column > m_columns) {
        throw(std::invalid_argument("the index out of the range"));
    }
    m_matrix[a_row * m_columns + a_column] = a_member;
}

template <typename T>
T& Matrix<T>::operator()(unsigned int a_row, unsigned int a_column) noexcept{
    return m_matrix[a_row * m_columns + a_column];
}

template <typename T>
T const& Matrix<T>::operator()(unsigned int a_row, unsigned int a_column) const noexcept{
    return m_matrix[a_row * m_columns + a_column];
}

/*
template<typename T>
void Matrix<T>::reset(){
    for (unsigned int r = 0; r < m_rows * m_columns; ++r){
            m_matrix[r * m_columns + c] = Color{255, 255, 255};
        }
}
*/
}/*advcpp*/