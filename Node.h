#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using std::vector;
using std::sort;
template <typename T> 
#define V vector<T>


class Node {
    //a point in euclidean space
    private:
        V args;
        int sp;

    public:
        Node(V __Args) {
            args = __Args;
            sp = __Args.size();
        }

        V getArgs() {
            return args;
        }
   
};
