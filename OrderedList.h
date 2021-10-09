#pragma once
#include "BaseArray.h"

template<class T>
class OrderedList :
    public BaseArray<T>
{
public:
    OrderedList(int size, bool allow_Dup = false) : BaseArray<T>(size) {};
    ~OrderedList();

    void push(T val) { //come back to fix after finishing the seccond search
        assert(p_array != NULL);
        
        if (num_Elements > 0) {

            for (int i = 0; i < num_Elements; i++) {
                if (p_array[i] == val) {
                    //duplicate
                    if (allow_Dup == true) {
                        if (num_Elements >= maxSize) {
                            expand();
                        }

                        for (int k = num_Elements; k > i; k--) {
                            p_array[k] = p_array[k - 1];
                        }
                        //shift everything over 1 and put the number where the dupe is now
                        p_array[i] = val;
                        num_Elements++;
                        return;
                    }
                    else {
                        cout << "duplicate number not added to array." << endl;
                        return;
                        //output no dupes allowed
                    }
                }
            }

            //new number
            if (num_Elements >= maxSize) {
                expand(); //makes sure we have enough space
            }

            for (int i = 0; i < num_Elements; i++) {
                if (p_array[i] > val) {
                    //gone too far
                    for (int k = num_Elements; k > i; k--) {
                        p_array[k] = p_array[k - 1];
                    }

                    num_Elements++;
                    p_array[i] = val;

                    return;
                }
            }

            //newest number is biggest
            num_Elements++;
            p_array[num_Elements] = val;

            return;
        }
        else {
            p_array[num_Elements] = val;
            num_Elements++;
            return;
        }

        return;
    }

    void binarySearch(T val) {
        assert(p_array != NULL);

        int lowerBound = 0;
        int uppperBound = num_Elements - 1;
        int current = 0;

        while (1) {
            current = (lowerBound + uppperBound) >> 1;

            if (p_array[current] == val) {
                return current;
            }
            else if (lowerBound > uppperBound) {
                return -1;
            }
            else {
                if (p_array[current] < val) {
                    lowerBound = current + 1;
                }
                else {
                    uppperBound = current - 1;
                }
            }
        }

        return -1;
    }

private:
    bool allow_Dup;
};

