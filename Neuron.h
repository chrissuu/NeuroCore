#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using std::vector;
using std::sort;
template <typename T> 
#define V vector<T>


class Neuron{
    private:
        Node node;
        double activationRadius;

    public:

        //translates to a point in euclidean space
        void translateTo(V __listArgs__Translate) {
            int thisNodeSize = (node->args).size();
            int translateSize = __listArgs__Translate.size();

            if(thisNodeSize != toNodeSize) return;

            node->args = __listArgs__Translate;
        }

        //adds a translation to current node in euclidean space
        void translateFrom(V __listArgs__Translate) {
            int thisNodeSize = (node->args).size();
            int translateSize = __listArgs__Translate.size();

            if(thisNodeSize != toNodeSize) return;

            for(int i = 0; i < toNodeSize; i++) {
                (node->args)[i] += __listArgs__Translate[i];
            }
        }

        Node getNode() {
            return node;
        }

        Neuron(Node<T> __Node__node, double activationRadius) {
            node = __Node__node;
            this->activationRadius = activationRadius;
        }


};
