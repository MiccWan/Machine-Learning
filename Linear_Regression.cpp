#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int indexs,data_length,train_times,trained_times=1;
double alpha;
vector<vector<double>> inp;
vector<double> w;
vector<double> y;

void init(int len,int index){
  inp.resize(len);
  for(int i=0;i<len;i++)inp[i].resize(index);
  w.resize(index);
  y.resize(len);
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
  cout<<"trained "<<trained_times++<<" times"<<endl;
}
void input(){
  for(int i=0;i<data_length;i++){
    for(int j=0;j<indexs-1;j++) cin>>inp[i][j];
    inp[i][indexs-1]=1;
    cin>>y[i];
  }
}

int main() {
  cin>>data_length>>indexs>>train_times>>alpha;
  indexs++;
  init(data_length,indexs);
  input();
  for(int i=1;i<=train_times;i++) train();
  cout<<"result: ";
  for(int i=0;i<indexs;i++) cout<<w[i]<<' ';
}