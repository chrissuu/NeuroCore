#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <Neuron.h>
#include <Node.h>
#include <Vector.h>

using std::cout;
using std::vector;
using std::sort;


template <typename T> 
#define vD vector<double>


vD normListOfPopulatedVSpace(vector<Node<double>> __listNode__VSpace, Node<double> __node__currNode) {
    vD listOfVNorms;
    for (int i = 0; i<__listNode__VSpace.size(); i++) {
        Vector<double> v(__listNode__VSpace[i]->args, __node__currNode->args);
        listOfVNorms.push_back(v->norm);
    }
    sort(listOfVNorms);
    return listOfVNorms;
}

vD normListOfPopulatedVSpace(vector<Neuron<double>> __listNode__VSpace, Neuron<double> __Node__currNode) {
    vD listOfVNorms;
    for (int i = 0; i<__listNode__VSpace.size(); i++) {
        Vector<double> v(__listNode__VSpace[i].getNode().getArgs(), __Node__currNode.getNode().getArgs());
        listOfVNorms.push_back(v.getNorm());
    }
    sort(listOfVNorms.begin(), listOfVNorms.end());
    return listOfVNorms;
}

Node<double> nearestNode(vector<Node<double>> __listNode__VSpace, Node<double> __Node__currNode) {
    Vector<double> v(__listNode__VSpace[1].getArgs(), __Node__currNode.getArgs());
    
    double currNearestLen = v.getNorm();
    Node<double> currNearest = v.getEPoint();
    for(int i = 1; i<__listNode__VSpace.size(); i++) {
        Vector v(__listNode__VSpace[i].getArgs(), __Node__currNode.getArgs());
        if(v.getNorm() < currNearestLen) {
            currNearestLen = v.getNorm();
            currNearest = __listNode__VSpace[i];;
        }
    }
    return currNearest;
}

Neuron<double> nearestNeuron(vector<Neuron<double>> __listNode__VSpace, Neuron<double> __Node__currNode) {
    Vector<double> v(__listNode__VSpace[1].getNode().args, __Node__currNode.getNode().args);
    
    double currNearestLen = v.getNorm();
    Neuron<double> currNearest(v.getEPoint(),0);
    for(int i = 1; i<__listNode__VSpace.size(); i++) {
        Vector<double> v(__listNode__VSpace[i].getNode().args, __Node__currNode.getNode().args);
        if(v.getNorm() < currNearestLen) {
            currNearestLen = v.getNorm();
            currNearest = __listNode__VSpace[i];;
        }
    }
    return currNearest;
}

int main() {
    Node<double> a({3,4});
    Node<double> b({5,6});

    Node<double> tail({0,0});
    vector<double> res =nearestNode({a,b}, tail).getArgs();
    cout << res;


}

    
//Vspace: vector<*args>
//helper for nearestNode

//pass in nodes (points) and a central node. calculate norms from the vectors created by listNodeVectorSpace and currNode

// //get the nearestNode to currNode
// def nearestNode(__listNode__VSpace, currNode):
//     return normListOfPopulatedVSpace(__listNode__VSpace, currNode)[0]




