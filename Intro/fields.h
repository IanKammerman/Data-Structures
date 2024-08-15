// Header file
#ifndef fields_H
#define fields_H

class fields{

    public:
        fields(int count);
        void load();
        int search(int Key);
        void print();

    private:
        int* array;
        int array_size;

};

#endif