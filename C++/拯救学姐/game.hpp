class game{
public:
    game();
    void init();
    void mode();
    void input();
    int move();
private:
    int x=0, y=0,score=0,xfood,yfood,lenth;
    const int xmax = 20;
    const int ymax = 20;
    int tailx[100],taily[100];
    enum instruction
    {
        stop,
        A,
        D,
        W,
        S
    };
    instruction ins;
};