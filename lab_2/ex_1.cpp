#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;


// Тип элемента матрицы
using value_type = double;
// Тип матрицы
using matrix_type = vector<vector<value_type>>;

// Создать матрицу matrix_size на matrix_size, заполненную случайными числами
matrix_type make_random_matrix(size_t matrix_size) {
    matrix_type matrix(matrix_size);
    for (auto &row: matrix) {
        row.resize(matrix_size);
        for (auto &elem: row) {
            elem = rand() / 10;
        }
    }
    return matrix;
}

// Вывести матрицу в поток
void print_matrix(const matrix_type &matrix) {
    for (auto &row: matrix) {
        for (auto &elem: row) {
            cout << setw(8) << setprecision(5) << elem << " ";
        }
        cout << endl;
    }
}


// Вычислить максимальный элемент
value_type max(const vector<value_type> &values) {
    double max{values[0]};
    for (auto &val: values) {
        if (val > max) {
            max = val;
        }
    }
    return max;
}


// Вычислить минимальный элемент
value_type min(const vector<value_type> &values) {
    double min{values[0]};
    for (auto &val: values) {
        if (val < min) {
            min = val;
        }
    }
    return min;
}


// Вычислить сумму элементов
value_type sum(const vector<value_type> &values) {
    value_type sum{};
    for (auto &val: values) {
        sum += val;
    }
    return sum;
}


// Вычислить среднее значение
value_type inline average(const vector<value_type> &values) {
    return sum(values) / static_cast<value_type>(values.size());
}



// Вычислить абсолютную разницу между a и b
value_type inline distance(value_type a, value_type b) {
    return abs(a - b);
}



// Вычислить элемент в минимальным отклонением от среднего значения
value_type min_distance_elem(const vector<value_type> &values) {
    auto average_elem{average(values)};
    size_t index{0};
    value_type min_distance{distance(values[0], average_elem)};
    for (size_t i = 1; i < values.size(); i++) {
        auto curr_distance{distance(values[i], average_elem)};
        if (curr_distance < min_distance) {
            min_distance = curr_distance;
            index = i;
        }
    }
    return values[index];
}


// Извлечь элементы верхеугольной матрицы
vector<value_type> get_up_corner(const matrix_type &matrix) {
    vector<value_type> res{};
    res.reserve(matrix.size() * matrix.size() / 2);
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i; j < matrix[i].size(); j++) {
            res.push_back(matrix[i][j]);
        }
    }
    return res;
}


// Извлечь элементы нижнеугольной матрицы
vector<value_type> get_down_corner(const matrix_type &matrix) {
    vector<value_type> res{};
    res.reserve(matrix.size() * matrix.size() / 2);
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j <= i; j++) {
            res.push_back(matrix[i][j]);
        }
    }
    return res;
}


// Извлечь элементы главной диагонали
vector<value_type> get_main_diagonal(const matrix_type &matrix) {
    vector<value_type> res{};
    res.reserve(matrix.size());
    for (size_t i = 0; i < matrix.size(); i++) {
        res.push_back(matrix[i][i]);
    }
    return res;
}


// Извлечь элементы побочной диагонали
vector<value_type> get_side_diagonal(const matrix_type &matrix) {
    vector<value_type> res{};
    res.reserve(matrix.size());
    for (size_t i = 0; i < matrix.size(); i++) {
        auto col_index{matrix[i].size() - i - 1};
        res.push_back(matrix[i][col_index]);
    }
    return res;
}


// Преобразовать матрицу в вектор
vector<value_type> expand(const matrix_type &matrix) {
    vector<value_type> res{};
    res.reserve(matrix.size() * matrix.size() / 2);
    for (auto &row: matrix) {
        for (auto &elem: row) {
            res.push_back(elem);
        }
    }
    return res;
}


// Извлечь элементы строки index
vector<value_type> get_row(const matrix_type &matrix, size_t index) {
    return matrix[index];
}


// Извлечь элементы колонки index
vector<value_type> get_column(const matrix_type &matrix, size_t index) {
    vector<value_type> res{};
    res.reserve(matrix.size());
    for (auto &row: matrix) {
        res.push_back(row[index]);
    }
    return res;
}


int main() {
    const size_t matrix_size{5};
    auto matrix{make_random_matrix(matrix_size)};
    cout << "Random matrix " << matrix_size << "x" << matrix_size << ": " << endl;
    print_matrix(matrix);

    cout << "Matrix min: " << min(expand(matrix)) << endl;
    cout << "Matrix max: " << max(expand(matrix)) << endl;
    cout << "Down corner max: " << max(get_down_corner(matrix)) << endl;
    cout << "Up corner max: " << max(get_up_corner(matrix)) << endl;
    cout << "Down corner min: " << min(get_down_corner(matrix)) << endl;
    cout << "Up corner min: " << min(get_up_corner(matrix)) << endl;
    cout << "Down corner sum: " << sum(get_down_corner(matrix)) << endl;
    cout << "Up corner sum: " << sum(get_up_corner(matrix)) << endl;
    cout << "Main diagonal min: " << min(get_main_diagonal(matrix)) << endl;
    cout << "Main diagonal max: " << max(get_main_diagonal(matrix)) << endl;
    cout << "Side diagonal min: " << min(get_side_diagonal(matrix)) << endl;
    cout << "Side diagonal max: " << max(get_side_diagonal(matrix)) << endl;
    cout << "Matrix average: " << average(expand(matrix)) << endl;
    cout << "Down corner average: " << average(get_down_corner(matrix)) << endl;
    cout << "Up corner average: " << average(get_up_corner(matrix)) << endl;
    cout << "Min distance to average: " << min_distance_elem(expand(matrix)) << endl;
    for (int i = 0; i < matrix_size; i++) {
        cout << "Row " << i << ": ";
        auto row{get_row(matrix, i)};
        cout << "Sum " << sum(row) << " ";
        cout << "Min " << min(row) << " ";
        cout << "Max " << max(row) << " ";
        cout << "Average " << average(row) << endl;
    }
    for (int i = 0; i < matrix_size; i++) {
        cout << "Column " << i << ": ";
        auto column{get_column(matrix, i)};
        cout << "Sum " << sum(column) << " ";
        cout << "Min " << min(column) << " ";
        cout << "Max " << max(column) << " ";
        cout << "Average " << average(column) << endl;
    }
}