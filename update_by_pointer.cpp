#include <chrono>
#include <iostream>

#include "math.cpp"
#include "bullet.cpp"

void UpdateByPointer(uint count);

int main()
{
    UpdateByPointer(50000000);
    return 0;
}

void UpdateByPointer(uint count)
{
    std::vector<Bullet*> bullets(count);

    for (size_t i = 0; i < count; i++)
    {
        bullets[i] = new Bullet();
    }

    std::chrono::high_resolution_clock clock;

    auto start = clock.now();

    for (int i = 0; i < count; i++)
    {
        bullets[i]->move();
    }
    
    auto end = clock.now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time passed in UpdateByPointer: " << elapsed.count() << " millisecond" << std::endl;
}