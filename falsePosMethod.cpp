
#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x*x*x - 3*x + 1;
}

void falsePosMethod(double low, double uper)
{

    char filename[35] = "falsepos.csv";
    FILE *fp;
    fp = fopen(filename,"w+");
    fprintf(fp,"Iteration, Relative Aproximate Error\n");


    if (func(low) * func(uper) >= 0)
    {
        cout << "Guess point is not correct\n";
        return;
    }

    double error,prevMid,mid;
    double thrs = 0.00263;
     cout<<"Ite\tX(low)\tX(Up)\tX(mid)\tf(lo)\tf(up)\tf(mid) \tError  \n";
      std::cout << std::setprecision(4) << std::fixed;
    for(int i=1;;i++)
    {
        // Find middle point
        mid = uper - (func(uper)*(uper-low))/(func(uper)-func(low));
         //calculate error
        if(i>1){
            error = abs((mid-prevMid)/mid);
            if(error<=thrs) break;
             cout<<i<<"\t"<<low<<"\t"<<uper<<"\t"<<mid<<"\t"<<func(uper)<<"\t"<<func(low)<<"\t"<<func(mid)<<"\t"<<error*100<<"%"<<endl;
            fprintf(fp,"%d, %.20lf\n",i,error);

        }
        else
        {
             cout<<i<<"\t"<<low<<"\t"<<uper<<"\t"<<mid<<"\t"<<func(uper)<<"\t"<<func(low)<<"\t"<<func(mid)<<"\t--"<<"%"<<endl;
        }
        // Check if middle point is root
        if (func(mid) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (func(mid) < 0)
            low = mid;
        else
            uper = mid;


        prevMid=mid;

    }
    cout << "The value of root is : " << mid;
}


int main()
{
    double low,uper;
    //cin>>low>>uper;
    falsePosMethod(1,0);
    return 0;
}

