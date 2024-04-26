#include <iostream>
class Matrix
{
public : 
    Matrix(){}

    Matrix(int row, int col)
    {
        rows = row;
        cols = col;
        matrix = new int *[rows];
        for(int i = 0; i < rows; i++){
            matrix[i] = new int[cols];
        }
    }

    Matrix(int row, int col, int** pmatrix)
    {
        rows = row;
        cols = col;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = pmatrix[i][j];
            }
        }
    }

    Matrix(const Matrix& other)
    {
        rows = other.rows;
        cols = other.cols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    Matrix(Matrix &&other)
    {
        rows = other.rows;
        cols = other.cols;
        this->matrix = std::move(other.matrix);
        other.matrix = nullptr;
    }

    ~Matrix()
    {
        for(int i = 0; i < rows; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }


    Matrix operator*(Matrix &other)
    {
        Matrix result(rows, rows);
        int res;
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    res = matrix[i][k]*other.matrix[k][j];
                    sum += res;
                }
                result.matrix[i][j] = sum;
                sum = 0;
            }
        }
        return result;
    }

    Matrix operator+(const Matrix& other)
    {
        Matrix result(rows, cols);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                result.matrix[i][j] = other.matrix[i][j] + matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    // Matrix operator/(const Matrix &other)
    // {
    //     if (rows != cols || other.rows != other.cols || rows != other.rows)
    //         return Matrix();
    //     Matrix result(rows, cols);
    //     
    //     return result;
    // }

    bool operator==(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
            return false;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] != other.matrix[i][j])
                    return false;
            }
        }
        return true;
    }

    friend std::istream &operator>>(std::istream &in, Matrix &matrix);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

private : 
    int rows;
    int cols;
    int **matrix;
};

std::istream &operator>>(std::istream &in, Matrix &matrix){
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            in >> *(*(matrix.matrix + i) + j);
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    std::cout << "以下为输出:" << std::endl;
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            os << *(*(matrix.matrix + i) + j) << ' ';
        }
        os << '\n';
    }
    return os;
}