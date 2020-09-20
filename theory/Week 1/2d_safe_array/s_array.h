class one_array{
    int* data;
    size_t size;
    public:
        one_array(){}
        one_array(size_t size):size(size){
            data = new int[size];
        }
        one_array(one_array& s):data(
                        new int[s.size]),
                        size(s.size) {
            copy(data, data+size, s.data);
        }
        one_array& operator=(one_array& s){
            size = s.size;
            int* newdata = new int[s.size];
            copy(s.data, s.data+s.size, newdata);
            delete [] data;
            data = newdata;
            return *this;
        }
        int& operator[](int i){
            return data[i];
        }
        ~one_array(){
            delete [] data;
        }
};
class two_array{
    one_array* data;
    size_t x,y;
    public:
        two_array(size_t x, size_t y):x(x),y(y){
            data = new one_array[y];
            for(int i=0; i<y; i++){
                one_array o(x);
                data[i] = o;
            }
        }
        two_array(two_array& t):
                            data( new one_array[t.y] ),
                            x(t.x),
                            y(t.y) {
            copy(data, data+y, t.data);
        }
        two_array& operator=(two_array& t){
            one_array* newdata = new one_array[t.y];
            copy(t.data, t.data+t.y, newdata);
            delete [] data;
            data = newdata;
            y = t.y;
            x = t.x;
            return *this;
        }
        one_array& operator[](int i){
            return data[i];
        }
        ~two_array(){
            delete [] data;
        }

};