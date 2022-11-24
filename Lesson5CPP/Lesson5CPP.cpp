// Lesson5CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Sudoku Project

#include <iostream>
using namespace std;
class Sudoku
{
private:
    int** area;
    int size;

    void moveRow(int row)
    {
        for (int c{ 0 }; c < row; c++) {
            int buf = area[row][0];
            for (int i{ 0 }; i < size; i++)
            {

                if (i + 1 == size)
                {
                    area[row][i] = buf;
                }
                else
                {
                    area[row][i] = area[row][i + 1];
                }

            }
        }
    }
    void moveColumn(int col)
    {
        for (int c{ 0 }; c < col; c++) {
            int buf = area[0][col];
            for (int i{ 0 }; i < size; i++)
            {

                if (i + 1 == size)
                {
                    area[i][col] = buf;
                }
                else
                {
                    area[i][col] = area[i + 1][col];
                }

            }
        }
    }
public:
    Sudoku(int count = 3) : size{count}, area { new int* [count] }
    {            
        for (int y{ 0 }; y < count; ++y)
        {
            area[y] = new int[count];
        }       
    }

    void setValues()
    {
        for (int i{ 0 }; i < size; i++)
        {
            for (int j{ 0 }; j < size; j++)
            {
                area[i][j] = j+1;
            }
        }
    }
    

    void moveRows()
    {
        for (int j{ 0 }; j < (rand() % 54 + 1); j++) {
            for (int i{ 0 }; i < size; i++) {
                moveRow(i);
            }
        }
    }
    void moveColumns()
    {
        for (int j{ 0 }; j < (rand() % 50 + 1); j++) {
            for (int i{ 0 }; i < size; i++) {
                moveColumn(i);
            }
        }
    }
    void print() 
    {
        for (int i{ 0 }; i < size; i++)
        {
            for (int j{ 0 }; j < size; j++)
            {
                cout << area[i][j] << " ";
            }
            cout << "\n";
        }
    }

};

int main()
{
    Sudoku sud(9);
    int swapRow = rand() % 9 + 1, swapCol = rand() % 9 + 1;
    sud.setValues();
    sud.print();
    cout << "\n";
    sud.moveRows();
    sud.moveColumns();

    sud.print();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
