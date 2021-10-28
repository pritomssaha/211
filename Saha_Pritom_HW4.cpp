#include <iostream>
#include<cmath>
using namespace std;

int main() {
 int q[8]={0};
 int c=0;
 int count=0;

 q[0]=0;

 nc:
  c++;
  if(c==8)
    goto print;

  q[c]=-1;
  nr:
   ++q[c];
   if(q[c]==8) 
    goto backtrack;
  for(int i=0;i<c;i++){
    if(q[i]==q[c]||(c-i)==abs(q[c]-q[i]))
      goto nr;
  }  
  goto nc;
  backtrack:
    c--;
    if(c==-1)
      return 0;
    goto nr;

    print:
    cout<<"solution# "<<++count<<endl;
    for(int i=0;i<8;i++){
      cout<<q[i]<<" ";
    }
    cout<<endl;
    goto backtrack;
  


}