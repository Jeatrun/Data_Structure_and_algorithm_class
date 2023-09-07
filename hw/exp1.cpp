#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
bool prime(int &n){
    bool is_prime=false;
    //�ж�n�Ƿ�Ϊ����
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            is_prime=true;//����������Ϊ������
        }
    }
    //���ز���
    if (!is_prime){
        return true;
    }
    else{
        return false;
    }
}

//��һ��
void q1()
{
    int n;
    int count;
    
    cout<<"������n��ֵ: ";
    cin>>n;
    
    for(int i=2;i<=n;i++){
        if(prime(i)){
            cout<<i<<" ";
            count++;
        }
        
        //���в�ˢ������
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

//�ڶ���
void q2()
{
    int n;
    cout<<"������n��ֵ:";
    cin>>n;

    clock_t start,end; 
    //�ۼӷ�     
    start=clock();
    cout<<"�ۼӷ����Ϊ��"<<Summation(n)<<endl;
    end=clock();
    cout<<"ʹ���ۼӷ���ʹ�õ�ʱ�䣺"<<double(end-start)/CLOCKS_PER_SEC<<" s"<<endl;

    //��˹��
    start=clock();
    cout<<"��˹�����Ϊ��"<<Gaussian(n)<<endl;
    end=clock();
    cout<<"ʹ�ø�˹����ʹ�õ�ʱ�䣺"<<double(end-start)/CLOCKS_PER_SEC<<" s"<<endl;

}

int main(){
    q1(); //ִ�е�һ��ĺ���
    //q2(); //ִ�еڶ���ĺ���
    return 0;
}