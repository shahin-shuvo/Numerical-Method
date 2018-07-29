#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return exp(x) - 5*x*x;
}

// Prints root of func(x) with error of EPSILON
void bisection(double low, double uper)
{
    char filename[35] = "bisection.csv";
    FILE *fp;
    fp = fopen(filename,"w+");
    fprintf(fp,"Iteration, Relative Aproximate Error\n");


    if (func(low) * func(uper) >= 0)
    {
        cout << "Guess point is not correct\n";
        return;
    }

    double mid = low;
    double error=0.0,prevMid;
    double thrs = 0.05263;
    cout<<"Ite\tX(lo)\t X(Up)\tX(mid)\tf(mid) \tError  \n";
     std::cout << std::setprecision(4) << std::fixed;
    for(int i=1;; i++)
    {

        // Find middle point
        mid = (low+uper)/2;

        if(i>1)
        {
            error = abs((mid-prevMid)/mid);
            if(error<=thrs) break;
            cout<<i<<"\t"<<low<<"\t"<<uper<<"\t"<<mid<<"\t"<<func(mid)<<"\t"<<error*100<<"%"<<endl;
            fprintf(fp,"%d, %.20lf\n",i,error);

        }
        else
        {
            cout<<i<<"\t"<<low<<"\t"<<uper<<"\t"<<mid<<"\t"<<func(mid)<<"\t"<<"--"<<"%"<<endl;
        }


        // Check if middle point is root
        if (func(mid) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (func(mid) < 0)
            low = mid;
        else
            uper = mid;

        //calculate error

        prevMid=mid;


    }
    cout << "The value of root is : " << mid;
}


int main()
{
    double low,uper;
    //cin>>low>>uper;
    bisection(1, .5);
    return 0;
}
