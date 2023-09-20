#ifndef _MATRIX_H__
#define _MATRIX_H__


namespace advcpp{
template <typename T>
class Matrix {
public:

    explicit Matrix(unsigned int a_rows, unsigned int a_columns);
    Matrix(const Matrix& a_other);
    Matrix& operator=(const Matrix& a_other);
    ~Matrix();

    T& operator()(unsigned int a_row, unsigned int a_column) noexcept;
    T const& operator()(unsigned int a_row, unsigned int a_column) const noexcept;
    unsigned int Rows()const;
    unsigned int Columns()const;
    //void PrintImage();
    T at(unsigned int a_row, unsigned int a_column) const;
    void Member(unsigned int a_row, unsigned int a_column, T& a_member) const;
private:
    unsigned int m_rows;
    unsigned int m_columns;
    T* m_matrix;
};

}
#include "inl/matrix.hxx"
#endif/*_MATRIX_H__*/