#include <iomanip>
#include <iostream>

void AverageValue(int days, const int *temp)
{
    int summ{0};
    for (int i = 0; i < days; ++i)
    {
        summ += temp[i];
    }
    double aver{summ * 1.0 / days};
    std::cout << std::fixed << std::setprecision(1) << aver << '\n';
}

void MinAndMax(int days, const int *temp)
{
    int min_t{temp[0]};
    int max_t{temp[0]};
    for (int i = 0; i < days; ++i)
    {
        if (temp[i] < min_t)
        {
            min_t = temp[i];
        }
        if (temp[i] > max_t)
        {
            max_t = temp[i];
        }
    }
    std::cout << min_t << " " << max_t << "\n";
}

void FrozenDays(int days, const int *temp)
{
    int cnt{0};
    for (int i = 0; i < days; ++i)
    {
        if (temp[i] < 0)
        {
            ++cnt;
        }
    }
    std::cout << cnt << "\n";
}

int main()
{
    int days{0};
    std::cin >> days;
    int *temp = new int[days];
    for (int i = 0; i < days; ++i)
    {
        std::cin >> temp[i];
    }
    AverageValue(days, temp);
    MinAndMax(days, temp);
    FrozenDays(days, temp);
    delete[] temp;
    return 0;
}
