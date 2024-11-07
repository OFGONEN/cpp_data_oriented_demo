struct Bullet // 28 Bytet
{
    float3 position;
    float3 direction;
    float speed;


    void move()
    {
        position = position + direction * speed;
    }
};