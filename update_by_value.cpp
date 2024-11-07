#include <chrono>
#include <iostream>

#include "math.cpp"
#include "bullet.cpp"

void UpdateByValue(uint count);

int main()
{
    UpdateByValue(50000000);
    return 0;
}

void UpdateByValue(uint count)
{
    std::vector<Bullet> bullets(count);
    
    std::chrono::high_resolution_clock clock;

    auto start = clock.now();

    for (int i = 0; i < count; i++)
    {
        bullets[i].move();
    }
    
    auto end = clock.now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time passed in UpdateByValue: " << elapsed.count() << " millisecond" << std::endl;
}