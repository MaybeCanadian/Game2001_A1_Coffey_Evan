#pragma once
#include "BaseArray.h"

template<class T>
class OrderedList :
    public BaseArray<T>
{
public:
    OrderedList(int size, bool flag) : BaseArray<T>(size), allow_Dup(true)
    {
        allow_Dup = flag;
    };

    void push(T val) { //come back to fix after finishing the seccond search

        assert(this->p_array != nullptr);

        if (this->num_Elements == 0) {
            this->p_array[0] = val;
            this->num_Elements++;
            return;
        }
        int temp = this->binarySearch(val);
        cout << temp << endl;
        if (temp != -1) {
            if (allow_Dup == false) {
                cout << "duplicates are not allowed" << endl;
                return;
            }

            //dupe
            for (int k = this->num_Elements; k > temp; k--) {
                this->p_array[k] = this->p_array[k - 1];
            }

            this->p_array[temp] = val;
            this->num_Elements++;

            return;
        }
        else
        {//not dupe
            int i, k;

            for (i = 0; i < this->num_Elements; i++) {
                if (this->p_array[i] > val) {
                    break;
                }
            }

            for (k = this->num_Elements; k > i; k--) {
                this->p_array[k] = this->p_array[k - 1];
            }

            this->p_array[i] = val;
            this->num_Elements++;

            return;
        }


    }

    int binarySearch(T val) {
        assert(this->p_array != NULL);

        int lowerBound = 0;
        int uppperBound = this->num_Elements - 1;
        int current = 0;

        while (1) {
            current = (lowerBound + uppperBound) >> 1;

            if (this->p_array[current] == val) {
                return current;
            }
            else if (lowerBound > uppperBound) {
                return -1;
            }
            else {
                if (this->p_array[current] < val) {
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

