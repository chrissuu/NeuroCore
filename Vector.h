#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <Node.h>

using std::vector;
using std::sort;
template <typename T> 
#define V vector<T>


class Vector {
    private:
        V args__A;
        V args__B;
        V v;
        V normalizedV:
        Node ePoint;
        double norm;
        int sp;

    public:
    //lA__A = <a1,a2,a3...an>
    //lB__B = <b1,b2,b3...bn>
    //calculateVector should return v = <b1-a1,b2-a2,b3-a3,...bn-an>
        V calculateVector(V __listArgs__A, V __listArgs__B){
            int lenA = __listArgs__A.size();
            int lenB = __listArgs__B.size();

            if(lenA!=lenB) {
                return nullptr;
            }

            V v;
            for (int i = 0; i< lenA; ++i){ 
                v.push_back(__listArgs__B[i]-__listArgs__A[i]);
            }

            return v;
        }
        
        //calculates the norm of a Vector, vector
        double calculateNorm(V vector) {
            int norm = 0;
            
            for(int i = 0; i<vector.size(); ++i) {
                norm += pow(vector[i],2);
            }

            return pow(norm,0.5);
        }

        //returns normalized Vector, vector
        V normalizeVector(V vector) {
            double norm = calculateNorm(vector);
            
            for(int i = 0; i<vector.size(); ++i) {
                vector[i] /= norm;
            }
            return vector;
            

        }

        Vector(V __args__A, V __args__B) {
            args__A = __args__A;
            args__B = __args__B;
            
            v = calculateVector(__args__A, __args__B);
            norm = calculateNorm(v);
            normalizedV = normalizeVector(v);
            sp = v.size();

            Node<T> ePoint(v);
        }

        double getNorm() {
            return norm;
        }

        double getV() {
            return v;
        }

        Node<T> getEPoint() {
            return ePoint;
        }

};