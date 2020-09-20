class Car{
    int horsepower;
    int top_speed;
    int fuel_capacity;
    string* models;
    public:
        Car(){
            models = new string[3];
            cout << "Car created\n";
        }
        Car(int h, int t, int f):horsepower(h),top_speed(t),fuel_capacity(f){
            models = new string[3];
            cout << "Car created\n";
        }
        void setModelNames(){
            for(int i=0;i<3;i++){
                cout << "#" << i+1 << ": ";
                cin >> models[i];
            }
        }
        Car(Car& c):
        fuel_capacity(c.fuel_capacity),
        top_speed(c.top_speed),
        horsepower(c.horsepower) {
            cout << "Car copy created\n";
          models = new string[3];
          copy(c.models, c.models+3, models);
        }
        Car& operator=(Car& c){
            horsepower = c.horsepower;
            top_speed = c.top_speed;
            fuel_capacity = c.fuel_capacity;
            models = new string[3];
            copy(c.models, c.models+3, models);
            return *this;
        }
        ~Car(){
            cout << "Car destroyed\n";
            delete [] models;
        }


};