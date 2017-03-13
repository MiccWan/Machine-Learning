#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int indexs,data_length,train_times,trained_times=1,w_trained=0;
double alpha;
vector<vector<double>> inp;
vector<double> w;
vector<double> y;
double corRate=0,corRate2=0;
vector<vector<double>> rate;

void init(int len,int index){
  inp.resize(len);
  for(int i=0;i<len;i++)inp[i].resize(index);
  w.resize(index);
  y.resize(len);
  rate.resize(2);
  rate[0].resize(train_times/100);
  rate[1].resize(train_times/100);
}

double getZ(vector<double> x,vector<double> w){
  double sum=0;
  for(int i=0;i<indexs;i++) sum+=x[i]*w[i];
  return sum;
}

double sumCalCost(int w_index){
  double result=0;
  for(int i=0;i<data_length;i++)result+=(y[i]-getZ(inp[i],w))*inp[i][w_index];
  return result;
}

void train(){
  for(int i=0;i<indexs;i++) w[i]=w[i]+alpha*sumCalCost(i);
  // for(int i=0;i<5;i++)cout<<w[i]<<' ';
  cout<<"trained "<<trained_times++<<" times"<<endl;
}

void input_w(){
  cout<<"input init w"<<endl;
  for(int i=0;i<indexs;i++)cin>>w[i];
  cin>>w_trained;
}

void input(){
  cout<<"input data"<<endl;
  for(int i=0;i<data_length;i++){
    for(int j=0;j<indexs-1;j++) cin>>inp[i][j];
    inp[i][indexs-1]=1;
    cin>>y[i];
  }
}

void cntErr(vector<double> x,int k){
  double preY=0;
  // cout<<"starting for loop"<<endl;
  for(int i=0;i<indexs;i++)preY+=w[i]*x[i];
  double er=abs(preY-y[k]);
  if( er < 0.5 )corRate++;
  if( er < 1.5 )corRate2++;
  // cout<<"cnt Func finished\n";
}

int main() {
  data_length=800;
  indexs=11;
  train_times=6000;
  alpha=0.0000001;
  // cin>>data_length>>indexs>>train_times>>alpha;
  indexs++;
  init(data_length,indexs);
  // input_w();
  input();
  for( int i=0; i < train_times/100 ; i++ ){
    for(int j=0;j<100;j++) train();
    cout<<"counting error..."<<endl;
    corRate=0,corRate2=0;
    for(int j=0;j<data_length;j++)cntErr(inp[j],j);
    cout<<corRate<<' '<<corRate2<<'\n'<<i<<endl;
    rate[0][i] = corRate/data_length;
    rate[1][i] = corRate2/data_length;
  }
  cout<<"result: ";
  for(int i=0;i<indexs;i++) cout<<w[i]<<' ';
  cout<<w_trained+train_times<<endl;
  for(int i=0;i<train_times/100;i++){
    cout<<rate[0][i]<<' '<<rate[1][i]<<endl;
  }
}