#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void Output(T* ptr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << *(ptr+i) << " ";
    }
    cout << endl;
}

template<typename T, size_t N>
T* Rand()
{
    T *ptr = new T[N];

    for (int i = 0; i < N; i++)
    {
        ptr[i] = 10.0 * rand() / (T) RAND_MAX;
    }
    return ptr;
}

template<typename T, size_t N>
T* NoRand()
{
    T *ptr = new T[N];

    for (int i = 0; i < N ;i++)
    {
        T a;
        cout << i + 1 << "-ый элемент: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Введите нормальное число\n";
            cin.clear();
            cin.ignore(32767, '\n');
            cout << i + 1 << "-ый элемент: ";
            cin >> a;
        }
        ptr[i] = a;
    }
    return ptr;
}

template<typename T, size_t N>
int Element() {
    T *ptr;
    T Max = *ptr;
    int k = 0;

    for (int i = 0; i < N; i++)
    {
        if (*(ptr + i) > Max)
        {
            Max = *(ptr + i);
            k = i;
        }
    }
    cout << endl;
    cout << "Максимальный элемент: " << Max << endl;
    cout << "Индекс максимального элемента: " << k + 1 << endl;
    cout << "Адрес максимального элемента: " << &k << endl;
    return k;
}

template<typename T>
void Arr_After_Max(T *ptr, int N, int k)
{
    cout << "Элементы, стоящие после максимального: ";
    for (int i = k + 1; i < N; i++)
    {
        cout << *(ptr+i) << " ";
    }
    cout << endl;
}

void Arr_After_Max(double *ptr, int N, int k)
{
    cout << "Элементы, стоящие перед максимальным: ";
    for (int i = 0; i < k; i++)
    {
        cout << *(ptr+i) << " ";
    }
    cout << endl;
}

void showMenu(int* e){
    cout<<endl;
    cout << "_____________МЕНЮ_____________" << endl;
    cout << " 1. Рандомный массив" << endl;
    cout << " 2. Самому заполнить массив" << endl;
    cout << " 3. Завершить" << endl;
    cout<<endl;
    cout << "Введите 1, 2 или 3" << endl;

    cin >> *(e);
}


int main()
{
    setlocale(LC_ALL, "rus");

    int e;
    do {
        showMenu(&e);
        switch (e)
        {
            case 1:
                cout << "Для типа int: " << endl;
                int *ptr1;
                ptr1=Rand<int, 6>();
                Output(ptr1, 6);
                int a;
                a=Element<int, 6>();
                Arr_After_Max(ptr1, 6,a);
                cout << endl;
                cout << endl;

                cout << "Для типа double: " << endl;
                double *ptr2;
                ptr2=Rand<double, 6>();
                Output(ptr2, 6);
                int b;
                b=Element<double, 6>();
                Arr_After_Max(ptr2, 6, b);
                break;

            case 2:
                cout << "Для типа int: " << endl;
                int *ptr3;
                ptr3=NoRand<int, 6>();
                cout << endl;
                Output(ptr3, 6);
                int c;
                c=Element<int, 6>();
                Arr_After_Max(ptr3, 6,c);
                cout << endl;
                cout << endl;

                cout << "Для типа double: " << endl;
                double *ptr4;
                ptr4=NoRand<double, 6>();
                cout << endl;
                Output(ptr4, 6);
                int d;
                d=Element<double, 6>();
                Arr_After_Max(ptr4, 6, d);
                break;

            case 3:
                cout << "До встречи!" << endl;
                break;

            default:
                cout<<"Нужно ввести 1, 2 ИЛИ 3"<<endl;
                break;
        }

    } while (e != 3);

    return 0;
}