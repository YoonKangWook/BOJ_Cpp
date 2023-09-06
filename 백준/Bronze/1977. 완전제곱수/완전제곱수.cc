#include <iostream>
#include <cmath>

int main()
{
    int M, N, sum = 0, sqrt_num = 0;
    
    std::cin >> M;
    std::cin >> N;
    
    for(int i = N; i >= M; i--)
    {
        int temp = std::sqrt(i);
        
        if(i == pow(temp, 2))
        {
            sum += i;
            sqrt_num = i;
        }
    }
    
    if(sum == 0)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << sum << std::endl;
        std::cout << sqrt_num << std::endl;
    }
    
    return 0;
}