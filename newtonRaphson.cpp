#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return (x-4)*(x-4)*(x+2);
}

double derivFunc(double x)
{
    return 3*x*x - 12*x;
}

// Prints root of func(x) with error of EPSILON
void newtonRaphson(double point)
{
    char filename[35] = "newtonRaphson.csv";
    FILE *fp;
    fp = fopen(filename,"w+");
    fprintf(fp,"Iteration, Relative Aproximate Error\n");



    double error=0.0,prevPoint=0.0;
    double presentPoint = point;
    double thrs = 0.00001;
    cout<<"Ite\tX\t f(x)\tf'(x)\tError  \n";
     std::cout << std::setprecision(5) << std::fixed;
    for(int i=0;; i++)
    {

        if(i>0)
        {
            error = abs((presentPoint-prevPoint)/presentPoint);

             cout<<i<<"\t"<<presentPoint<<"\t"<<func(presentPoint)<<"\t"<<derivFunc(presentPoint)<<"\t"<<error*100<<"%"<<endl;
            fprintf(fp,"%d, %.20lf\n",i,error);
             if(error<=thrs) break;

        }
        else
        {
            cout<<i<<"\t"<<presentPoint<<"\t"<<func(presentPoint)<<"\t"<<derivFunc(presentPoint)<<"\t"<<"--"<<"%"<<endl;
        }



        prevPoint=presentPoint;
        presentPoint = prevPoint - func(prevPoint)/derivFunc(prevPoint);


    }
    cout << "The value of root is : " << presentPoint;
}


int main()
{
    newtonRaphson(-2.3);

    return 0;
}

