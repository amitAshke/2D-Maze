#ifndef 2D_MAZE_CONVERTER_H
#define 2D_MAZE_CONVERTER_H

#include <string>

using namespace std;

template<class P, class S>
class Converter {
public:

    /*
     * convert string to problem
     */
    virtual P conVecStringToProblem(vector<string> pro) = 0;

    /*
    * convert problem to string
    */
    virtual string conVecProblemToString(P problem) = 0;


    /*
     * convert solve to string
     */
    virtual string conSolvToString(S solve) = 0;
    /*
   * convert string to solve
   */
    virtual S conStringToSol(string solve) = 0;


    virtual ~Converter() = default;;

};

#endif //2D_MAZE_CONVERTER_H
