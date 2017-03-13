#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int indexs,data_length,train_times,trained_times=1;
double alpha;
vector<vector<double>> inp;
vector<double> w;
vector<double> y;
double corRate=0,corRate2=0;

void init(int len,int index){
  inp.resize(len);
  for(int i=0;i<len;i++)inp[i].resize(index);
  w.resize(index);
  y.resize(len);
}

void input(){
  cout<<"input testing data"<<endl;
  for(int i=0;i<data_length;i++){
    for(int j=0;j<indexs-1;j++) cin>>inp[i][j];
    inp[i][indexs-1]=1;
    cin>>y[i];
  }
}

void cntErr(vector<double> x,int k){
  double preY=0;
  for(int i=0;i<indexs;i++)preY+=w[i]*x[i];
  double er=abs(preY-y[k]);
  if( er < 0.5 )corRate++;
  if( er < 1.5 )corRate2++;
}

int main() {
  indexs=11;
  indexs++;
  data_length=800;
  init(data_length,indexs);
  cout<<"input w result"<<endl;  
  for(int i=0;i<indexs;i++)cin>>w[i];
  input();
  for(int i=0;i<data_length;i++)cntErr(inp[i],i);
  cout<<"corect rate:"<<corRate/data_length<<' '<<corRate2/data_length;
}