#include <chrono>
#include <iostream>

#include "math.cpp"
#include "bullet.cpp"
#include <thread>

void UpdateByValue_Threaded(uint count, uint threadCount);

int main()
{
    UpdateByValue_Threaded(50000000, 4);
    return 0;
}

void UpdateByValue_Threaded(uint count, uint threadCount)
{
    std::vector<Bullet> bullets(count);
    
    std::chrono::high_resolution_clock clock;

    auto start = clock.now();

    std::vector<std::thread> threads;

    for (size_t i = 0; i < threadCount; i++)
    {
        uint start = i * count / threadCount;
        uint end = (i + 1) * count / threadCount;

        threads.emplace_back(std::thread([startIdx = start, endIdx = end, &bullets]()
        {
            for (int i = startIdx; i < endIdx; i++)
            {
                bullets[i].move();
            }
        }));
    }

    for (size_t i = 0; i < threadCount; i++)
    {
        threads[i].join();
    }
    
    auto end = clock.now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time passed in UpdateByValue_Threaded: " << elapsed.count() << " millisecond" << std::endl;
}