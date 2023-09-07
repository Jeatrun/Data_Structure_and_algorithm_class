#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
bool prime(int &n){
    bool is_prime=false;
    //判断n是否为素数
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            is_prime=true;//被整除，则为非素数
        }
    }
    //返回参数
    if (!is_prime){
        return true;
    }
    else{
        return false;
    }
}

//第一题
void q1()
{
    int n;
    int count;
    
    cout<<"请输入n的值: ";
    cin>>n;
    
    for(int i=2;i<=n;i++){
        if(prime(i)){
            cout<<i<<" ";
            count++;
        }
        
        //换行并刷新行数
        if(count==10){
            count=0;
            cout<<endl;
        }
    }
}

int Summation(int& n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;

}

int Gaussian(int &n){
    return n*(n+1)/2;
}

//第二题
void q2()
{
    int n;
    cout<<"请输入n的值:";
    cin>>n;

    clock_t start,end; 
    //累加法     
    start=clock();
    cout<<"累加法结果为："<<Summation(n)<<endl;
    end=clock();
    cout<<"使用累加法所使用的时间："<<double(end-start)/CLOCKS_PER_SEC<<" s"<<endl;

    //高斯法
    start=clock();
    cout<<"高斯法结果为："<<Gaussian(n)<<endl;
    end=clock();
    cout<<"使用高斯法所使用的时间："<<double(end-start)/CLOCKS_PER_SEC<<" s"<<endl;

}

int main(){
    q1(); //执行第一题的函数
    //q2(); //执行第二题的函数
    return 0;
}