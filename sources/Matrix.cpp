#include <vector>
#include <string>
#include <iostream>
#include "Matrix.hpp"

using namespace std;

namespace zich
{
    Matrix::Matrix(vector<double> vec, int row, int col)
    {
        if (vec.size() != (row * col))
        {
            throw invalid_argument("cannot create this matrix");
        }
        _row = row;
        _col = col;
        size_t uns_row = (size_t)row;
        size_t uns_col = (size_t)col;
        _mat.resize(uns_row);
        for (size_t i = 0; i < row; i++)
        {
            _mat.at(i).resize(uns_col);
        }
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                _mat.at(i).at(j) = vec.at((uns_col * i) + j);
            }
        }
    }
    Matrix::Matrix(const Matrix &other)
    {
        _row = other._row;
        _col = other._col;
        _mat = other._mat;
    }
    Matrix::Matrix(int row, int col)
    {
        size_t uns_row = (size_t)row;
        size_t uns_col = (size_t)col;
        vector<vector<double>> mat(uns_row, vector<double>(uns_col, 0));
        _row = row;
        _col = col;
        _mat = mat;
    }

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    Matrix Matrix::operator+(Matrix const &other)
    {
        if (!(other._row == this->_row && other._col == this->_col))
        {
            throw invalid_argument("matrix size should be the same");
        }
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        Matrix ans(*this);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                ans._mat.at(i).at(j) += other._mat.at(i).at(j);
            }
        }
        return ans;
    }

    Matrix Matrix::operator+(double num)
    {
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        Matrix ans(*this);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                ans._mat.at(i).at(j) += num;
            }
        }
        return ans;
    }

    Matrix Matrix::operator+()
    {
        return *this;
    }

    Matrix Matrix::operator+=(Matrix const &other)
    {
        return (*this = *this + other);
    }
    Matrix Matrix::operator+=(double num)
    {
        return (*this = *this + num);
    }
    Matrix Matrix::operator++()
    {
        return (*this = *this + 1);
    }

    Matrix Matrix::operator++(int)
    {
        Matrix temp(*this);
        ++(*this);
        return temp;
    }

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //----------------------------------------------------------------
    //----------------------------------------------------------------
    //----------------------------------------------------------------

    Matrix Matrix::operator-(Matrix const &other)
    {
        if (!(other._row == this->_row && other._col == this->_col))
        {
            throw invalid_argument("matrix size should be the same");
        }
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        Matrix ans(*this);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                ans._mat.at(i).at(j) -= other._mat.at(i).at(j);
            }
        }
        return ans;
    }
    Matrix Matrix::operator-(double num)
    {
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        Matrix ans(*this);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                ans._mat.at(i).at(j) -= num;
            }
        }
        return ans;
    }
    Matrix Matrix::operator-()
    {
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        Matrix ans(*this);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                ans._mat.at(i).at(j) = 0 - ans._mat.at(i).at(j);
            }
        }
        return ans;
    }
    Matrix Matrix::operator-=(Matrix const &other)
    {
        return (*this = *this - other);
    }
    Matrix Matrix::operator-=(double num)
    {
        return (*this = *this - num);
    }
    Matrix Matrix::operator--()
    {
        return (*this = *this - 1);
    }
    Matrix Matrix::operator--(int)
    {
        Matrix temp(*this);
        --(*this);
        return temp;
    }

    //----------------------------------------------------------------
    //----------------------------------------------------------------
    //----------------------------------------------------------------

    //****************************************************************
    //****************************************************************
    //****************************************************************
    Matrix Matrix::operator*(Matrix const &other)
    {
        if (this->_col != other._row)
        {
            throw invalid_argument("matrix multiplication is undefined!");
        }
        Matrix ans(this->_row, other._col);
        unsigned int rows = (unsigned int)this->_row;
        unsigned int cols = (unsigned int)other._col;
        unsigned int common = (unsigned int)this->_col;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                double sum = 0;
                for (size_t k = 0; k < common; k++)
                {
                    sum += this->_mat.at(i).at(k) * other._mat.at(k).at(j);
                }
                ans._mat.at(i).at(j) = sum;
            }
        }
        return ans;
    }

    Matrix Matrix::operator*(double num) const
    {
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        Matrix ans(*this);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                ans._mat.at(i).at(j) *= num;
            }
        }
        return ans;
    }
    Matrix Matrix::operator*=(Matrix const &other)
    {
        return (*this = *this * other);
    }
    Matrix Matrix::operator*=(double num)
    {
        return (*this = *this * num);
    }
    //****************************************************************
    //****************************************************************
    //****************************************************************

    //================================================================
    //================================================================
    //================================================================
    bool Matrix::operator==(Matrix const &other) const
    {
        if (!(other._row == this->_row && other._col == this->_col))
        {
            throw invalid_argument("matrix size should be the same");
        }
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (this->_mat.at(i).at(j) != other._mat.at(i).at(j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool Matrix::operator!=(Matrix const &other) const
    {
        return !(*this == other);
    }
    bool Matrix::operator>(Matrix const &other) const
    {
        if (!(other._row == this->_row && other._col == this->_col))
        {
            throw invalid_argument("matrix size should be the same");
        }
        unsigned int row = (unsigned int)this->_row;
        unsigned int col = (unsigned int)this->_col;
        double sum1 = 0;
        double sum2 = 0;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                sum1 += this->_mat.at(i).at(j);
                sum2 += other._mat.at(i).at(j);
            }
        }
        return (sum1 > sum2);
    }

    bool Matrix::operator>=(Matrix const &other) const
    {
        bool ans = *this > other || *this == other;
        return ans;
    }

    bool Matrix::operator<(Matrix const &other) const
    {
        bool ans = !(*this >= other);
        return ans;
    }
    bool Matrix::operator<=(Matrix const &other) const
    {
        bool ans = *this < other || *this == other;
        return ans;
    }

    //================================================================
    //================================================================
    //================================================================

    Matrix operator*(double num, const Matrix &mat)
    {
        Matrix ans = mat * num;
        return ans;
    }

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    ostream &operator<<(ostream &out, Matrix &mat)
    {
        string ans;
        unsigned int row = mat.get_row();
        unsigned int col = mat.get_col();
        for (size_t i = 0; i < row; i++)
        {
            out << "[";
            for (size_t j = 0; j < col; j++)
            {
                out << mat._mat.at(i).at(j);
                if (j != col - 1)
                {
                    out << " ";
                }
            }
            if (i == row - 1)
            {
                out << "]";
            }
            else
            {
                out << "]\n";
            }
        }

        out << ans;
        return out;
    }
    
    bool is_numeric(char ch)
    {
        return (ch >= '0' && '9' >= ch);
    }

    istream &operator>>(istream &in, Matrix &mat)
    {
        string str;
        getline(in >> ws, str);

        if (str.empty())
        {
            throw invalid_argument("string should contain information");
        }
        for (size_t i = 0; i < str.size(); i++)
        {
            if (!is_numeric(str.at(i)) && str.at(i) != ',' && str.at(i) != ' ' && str.at(i) != '[' && str.at(i) != ']' && str.at(i) != '\n' && str.at(i) != '.' && str.at(i) != '-')
            {
                throw invalid_argument("string contains irrelevant chars");
            }
        }
        if (str.at(0) != '[' || str.at(str.size() - 1) != ']')
        {
            throw invalid_argument("string format is wrong");
        }

        string s_value;
        int rows = 0;
        int cols = 1;
        bool first = true;
        vector<double> vec;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str.at(i) == ']' && i == str.size() - 1)
            {
                double value = stod(s_value);
                vec.push_back(value);
                s_value = "";
                rows++;
                break;
            }
            if (str.at(i) == '[')
            {
                if (i + 1 == str.size() || (!is_numeric(str.at(i + 1)) && str.at(i + 1) != '-'))
                {
                    throw invalid_argument("after [ should come number or -");
                }
            }
            else if (str.at(i) == '-')
            {
                if (i + 1 == str.size() || !is_numeric(str.at(i + 1)))
                {
                    throw invalid_argument("after - should come number");
                }
                s_value += str.at(i);                
            }
            else if (str.at(i) == '.')
            {
                if (i + 1 == str.size() || !is_numeric(str.at(i + 1)))
                {
                    throw invalid_argument("after . should come number");
                }
                s_value += str.at(i);
            }
            else if (is_numeric(str.at(i)))
            {
                s_value += str.at(i);
                if (i + 1 == str.size() || str.at(i + 1) == ',' || str.at(i + 1)=='-')
                {
                    throw invalid_argument("after number should not come , or -");
                }
            }
            else if (str.at(i) == ',')
            {
                if (i + 1 == str.size() || str.at(i + 1) != ' ')
                {
                    throw invalid_argument("after , should come space");
                }
                i++;
                continue;
            }
            else if (str.at(i) == ' ' || str.at(i) == ']')
            {
                double value = stod(s_value);
                vec.push_back(value);
                s_value = "";
                if (first && str.at(i) == ' ')
                {
                    cols++;
                }
                if (str.at(i) == ']')
                {
                    rows++;
                    first = false;
                }
                if (str.at(i) == ' ')
                {
                    if (i + 1 == str.size() || (str.at(i + 1) != '[' && !is_numeric(str.at(i + 1)) && str.at(i + 1) != '-'))
                    {
                        throw invalid_argument("after space should come [ or number");
                    }
                }
                if (str.at(i) == ']')
                {
                    if (i + 1 == str.size() || (str.at(i + 1) != ','))
                    {
                        throw invalid_argument("after ] should come , or end");
                    }
                }
            }
        }
        if(rows * cols != vec.size())
        {
            throw invalid_argument("format of string is wrong");
        }

        mat.set_col(cols);
        mat.set_row(rows);
        mat.set_mat(vec);
        return in;
    }

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}