class Maze{
    bool** arr;
    public:
    Maze(int x, int y){
        arr = new bool*[y];
        for(int i=0; i<y; i++)
            arr[i] = new bool[x];
    }

};