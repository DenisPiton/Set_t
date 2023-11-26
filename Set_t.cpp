#include <iostream>
using namespace std;

class Set {

public:
    unsigned loong{ 0 };
    Set(unsigned loonge) :loong{ loonge } {};
    int* numbers{ new int[loong] };


    bool in(int a)
    {
        bool buf = false;
        for (int i = 0; i < loong; i++)
        {
            if (a == numbers[i])
            {
                buf = true;
            }
        }
        return buf;
    }

    
    void add(int a)
    {
        numbers[loong] = a;
        loong++;
    }

    void minus(int b)
    {
        Set buf(1);
        for (int i = 0; i < loong; i++)
        {
            if (numbers[i] != b)
            {
                buf.numbers[buf.loong] = numbers[i];
                buf.loong++;
            }

        }
        numbers = buf.numbers;
        

    }

    void print()
    {
        for (int i = 0; i < loong; i++)
        {
            cout << numbers[i] << endl;
        }
    }

    Set add_set(Set b)
    {
        Set buf(loong);
        buf.numbers = numbers;
        for (int i = 0; i < b.loong; i++)
        {
            if (!in(b.numbers[i]))
            {
                buf.add(b.numbers[i]);
            }
        }
        return buf;

    }
    Set minus_set(Set b)
    {
        Set buf(loong);
        buf.numbers = numbers;
        for (int i = 0; i < b.loong; i++)
        {
            if (!in(b.numbers[i]))
            {
                buf.minus(b.numbers[i]);
            }
        }
        return buf;
    }
    
    void add_set_op(Set& b)
    {
        Set buf(loong);
        buf.numbers = numbers;
        for (int i = 0; i < b.loong; i++)
        {
            if (!in(b.numbers[i]))
            {
                buf.add(b.numbers[i]);
            }
        }
        numbers = buf.numbers;

    }
    
    void operator+=(int i) {
        add(i);
    }
    void operator=(Set a)
    {
        numbers = a.numbers;
        loong = a.loong;
    }
    friend bool operator==(Set a, Set b)
    {
        return a.numbers == b.numbers;
    }

    void operator-=(int i) {
        minus(i);
    }
    friend Set operator+(Set a, Set b) {
        return a.add_set(b);
    }
    friend Set operator-(Set a, Set b)
    {
        return a.minus_set(b);
    }
    int& operator [] (int i) {
        return numbers[i];
    }
    friend void operator+=(Set& a, Set b)
    {
        a = a + b;
    }
    friend void operator-=(Set& a, Set b)
    {
        a = a - b;
    }
    

    friend ostream& operator<< (ostream& output, Set a) {
        for (int i = 0; i < a.loong; i++)
        {
            output << a.numbers[i] << endl;
        }
        return output;
    }
   
};
int main()
{
    Set a(3);
    a.numbers[0] = 1;
    a.numbers[1] = 2;
    a.numbers[2] = 3;
    a += 5;
    

    Set b(3);
    b.numbers[0] = 9;
    b.numbers[1] = 2;
    b.numbers[2] = 7;
    a += b;
    
    cout << a;
    
    
    
    


}

