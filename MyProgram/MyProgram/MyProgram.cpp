// MyProgram.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include "MetricRegister.cpp"
#include <cassert>


void TestCountMetric() {
    MetricRegister* first = new MetricRegister();
    first = first->getInstance();
    first->add_metr(10, 15, 1);
    first->add_metr(11, 10, 2);
    first->add_metr(12, 10, 3);
    first->add_metr(13, 10, 4);
    first->add_metr(14, 10, 5);
    first->add_metr(15, 10, 6);
    first->add_metr(16, 10, 7);
    first->add_metr(17, 10, 8);
    first->add_metr(18, 10, 9);
    first->add_metr(19, 10, 10);
    assert(first->count_cometr(1) == 25);
    assert(first->count_cometr(2) == 21);
    assert(first->count_cometr(3) == 22);
    assert(first->count_cometr(4) == 23);
    assert(first->count_cometr(5) == 24);
    assert(first->count_cometr(6) == 25);
    assert(first->count_cometr(7) == 26);
    assert(first->count_cometr(8) == 27);
    assert(first->count_cometr(9) == 28);
    assert(first->count_cometr(10) == 29);
    assert(first->count_cometr(0) == 0);
    std::cout << "Test is OK.\n";
}

int main()
{
    std::cout << "Hello\n";

    TestCountMetric();

    MetricRegister* metric = new MetricRegister();
    metric = metric->getInstance();

    int action = 0;

    while (true) {
        std::cout << "\nChoose command\n\n";

        std::cout << "1 - add a metric.\n"
            << "2 - show all metrics\n"
            << "3 - count metric\n"
            << "4 - exit\n\n";
        std::cin >> action;
        int resp_t = 0;
        int wait_t = 0;
        int key = 0;

        switch (action)
        {
        case 1:
        {
            std::cout << "Enter a key of metric:\n";
            std::cin >> key;
            std::cout << "Enter a resp_t of metric:\n";
            std::cin >> resp_t;
            std::cout << "Enter a wait_t of metric:\n";
            std::cin >> wait_t;
            metric->add_metr(resp_t, wait_t, key);
            break;
        }
        case 2:
        {
            std::cout << "Your all metrics:\n";
            metric->show_metr();
            break;
        }
        case 3:
        {
            std::cout << "Enter a key of metric:\n";
            std::cin >> key;
            std::cout << "Its your supporting metric:\n";
            std::cout << metric->count_cometr(key) << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Goodbye\n";
            return 0;
        }
        default:
            break;
        }


    }
}