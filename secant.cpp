
#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return (x-4)*(x-4)*(x+2);
}


// Prints root of func(x) with error of EPSILON
void secant(double present, double prev)
{
    char filename[35] = "secant.csv";
    FILE *fp;
    fp = fopen(filename,"w+");
    fprintf(fp,"Iteration, Relative Aproximate Error\n");



    double error=0.0,oldPoint=0.0;
    double nextPoint = 0.0;
    double thrs = 0.00001;
    cout<<"Ite\tX(i-1)\t X(i)\tX(i+1)\tf(x)\tError\n";
     std::cout << std::setprecision(7) << std::fixed;
    for(int i=1;; i++)
    {
         nextPoint = present - func(present)*(present-prev)/(func(present)-func(prev));

        if(i>1)
        {
            error = abs((present-prev)/present);

             cout<<i<<"\t"<<prev<<"\t"<<present<<"\t"<<nextPoint<<"\t"<<"  "<<error<<endl;
            fprintf(fp,"%d, %.20lf\n",i,error);
             if(error<=thrs) break;

        }
        else
        {
             cout<<i<<"\t"<<prev<<"\t"<<present<<"\t"<<nextPoint<<"\t"<<" --"<<"%"<<endl;
        }


        prev = present;
        present = nextPoint;



    }
    cout << "The value of root is : " << present;
}


int main()
{
    secant(2.5,-1.0);

    return 0;
}

