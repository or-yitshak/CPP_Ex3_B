#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        int _row;
        int _col;
        vector<vector<double>> _mat;

    public:
        Matrix(vector<double> vec, int row, int col);
        Matrix(const Matrix &other);
        Matrix(int row, int col);
        
        unsigned int get_row() { return (unsigned int)_row; }
        unsigned int get_col() { return (unsigned int)_col; }

        void set_row(int r) { _row = r;}
        void set_col(int c) { _col = c;}
        void set_mat(vector<double> v) { 
            size_t uns_row = (size_t)_row;
            size_t uns_col = (size_t)_col;
            _mat.resize(uns_row);
            for (size_t i = 0; i < uns_row; i++)
            {
                _mat.at(i).resize(uns_col);
            }
            for (size_t i = 0; i < uns_row; i++)
            {
                for (size_t j = 0; j < uns_col; j++)
                {
                    _mat.at(i).at(j) = v.at((uns_col * i) + j);
                }
            }
        }
        
        // friend operators

        Matrix operator+(const Matrix &other);
        Matrix operator+(double num);
        Matrix operator+();
        Matrix operator+=(const Matrix &other);
        Matrix operator+=(double num);
        Matrix operator++();
        Matrix operator++(int);

        Matrix operator-(Matrix const &other);
        Matrix operator-(double num);
        Matrix operator-();
        Matrix operator-=(Matrix const &other);
        Matrix operator-=(double num);
        Matrix operator--();
        Matrix operator--(int);

        Matrix operator*(Matrix const &other);
        Matrix operator*(double num)const;
        Matrix operator*=(Matrix const &other);
        Matrix operator*=(double num);

        bool operator==(Matrix const &other)const;
        bool operator!=(Matrix const &other)const;

        bool operator<=(Matrix const &other)const;
        bool operator<(Matrix const &other)const;

        bool operator>=(Matrix const &other)const;
        bool operator>(Matrix const &other)const;

        friend Matrix operator*(double num, const Matrix &mat);
        friend std::ostream &operator<<(std::ostream &out, Matrix &mat);
        friend std::istream &operator>>(std::istream &in, Matrix &mat);
    };
};