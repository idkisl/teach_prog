#include <algorithm>
#include <iostream>
#include <array>
using namespace std;

class TestSorting
{
private:
    static const unsigned int N = 29;
    static const unsigned int M = 11;
    std::array<int, N> array_1_d;
    std::array<int, N> coppy_array_1_d;
    std::array<std::array<int, M>, N> array_2_d;
    std::array<std::array<int, M>, N> coppy_array_2_d;
    
    void make_coppy_of_array_1_d()
    {
        for (int i = 0; i < N; ++i)
        {
            coppy_array_1_d[i] = array_1_d[i];
        }
    }
    
    void make_coppy_of_array_2_d()
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                coppy_array_2_d[i][j] = array_2_d[i][j];
            }
        }
    }
    
    void test_sort_1_d()
    {
        sort(coppy_array_1_d.begin(), coppy_array_1_d.end());
    }
    
    void test_sort_2_d()
    {
        for (int i = 0; i < N; ++i)
        {
            sort(coppy_array_2_d[i].begin(), coppy_array_2_d[i].end());
        }
    }
    
    bool compare_1_d()
    {
        for (int i = 0; i < N; ++i)
        {
            if (array_1_d[i] != coppy_array_1_d[i])
            {
                return false;
            }
        }
        return true;
    }
    bool compare_2_d()
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (array_2_d[i][j] != coppy_array_2_d[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool compare_all_sorts()
    {
        if (!compare_1_d())
        {
            cout << "Неверная сортировка (одномерного) массива!";
            cout << endl << endl;
            cout << "Должно было получиться:" << endl;
            print_1_d_array(coppy_array_1_d);
            cout << "Ваш ответ:" << endl;
            print_1_d_array(array_1_d);
            cout << endl << endl;
            cout << "Тест для сортировки матрицы (двумерного массива) не запустится до тех пор, пока не будет сделана верная сортировка одномерного массива.";
            cout << endl << endl;
            
            return false;
        }
        else
        {
            cout << "Сортировка одномерного массива выполнена верно!";
            cout << endl << "Перехожу к тестированию двумерного массива..." << endl;
            cout << endl << endl;
        }
        

        if (!compare_2_d())
        {
            cout << "Неверная сортировка (двумерного) массива - матрицы!";
            cout << endl << endl;
            cout << "Должно было получиться:" << endl;
            print_2_d_array(coppy_array_2_d);
            cout << "Ваш ответ:" << endl;
            print_2_d_array(array_2_d);
            return false;
        }
        cout << "Сортировка двумерного массива выполнена верно!" << endl;
        return true;
    }
    
    bool result_of_task()
    {
        test_sort_1_d();
        test_sort_2_d();
        cout << "Выполняю сортировку одномерного массива..." << endl;
        your_sort_1_d();
        cout << "Успешно" << endl;
        cout << "Выполняю сортировку двумерного массива..." << endl;
        your_sort_2_d();
        cout << "Успешно" << endl;
        cout << endl << "Запускаю проверку решения:" << endl;
        bool flag = compare_all_sorts();
        if (flag)
        {
            cout << endl << "Поздравляю с успешной сдачей задания!" << endl;
            cout << endl << endl;
        }
        else
        {
            cout << endl << "Задание не выполнено, попробуйте еще раз." << endl;
            cout << endl << endl;
        }
        return flag;
    }
    
    void print_1_d_array(const array<int, N>& arr) const
    {
        cout << "array_1_d = [" << endl;
        for (int i = 0; i < N; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
    
    void print_2_d_array(const array<array<int, M>, N>& arr) const
    {
        cout << "array_2_d = [" << endl;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "]" << endl;
    }
    void initialization()
    {
        for (int i = 0; i < N; ++i)
        {
            array_1_d[i] = rand() % (M * N * 10);
        }
        make_coppy_of_array_1_d();
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                array_2_d[i][j] = rand() % (M) * (-i * i + j * j);
            }
        }
        make_coppy_of_array_2_d();
    }
public:
    TestSorting()
    {
        initialization();
    }

    void make_tests_sort()
    {
        // Вызываю функцию проверки
        bool flag = result_of_task();
        
        if (flag)
        {
            cout << endl << endl << endl;
            cout << "Do the same test second time!" << endl << "Повторяю тест еще раз на других числах для точности." << endl << endl << endl << endl;
            initialization();
            // Вызываю функцию проверки
            result_of_task();
        }

    }
    
    
    
    // your code goes in this function
    void your_sort_1_d()
    {
        // this is your try to sort array
        // the name of array must be array_1_d
        // it is already initialized - you DO NOT need to create an array!!!
        // The lenght of the array_1_d is N
        // You need to sort the array in ascending order (по возрастанию)
        
    }
    
    // your code goes in this function
    void your_sort_2_d()
    {
        // this is your try to sort 2D array - matrix
        // the name of array must be array_2_d
        // it is already initialized - you DO NOT need to create an array!!!
        // The lenght of the array_2_d is N x M
        // You need to sort the array in ascending order (по возрастанию) of each line (каждая строка по отдельности)
        // Если проще - выполнить сортировку для одномерного массива для каждого из N строк
        
    }

};

int main()
{
    setlocale(LC_ALL, "RUS");
    TestSorting test_sorting;
    test_sorting.make_tests_sort();

    cout << endl;
    return 0;
}
