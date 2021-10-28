
#include<iostream>
using namespace std;

int main()
{
	int q[8][8]={0};
	int r,c=0,count=0;
	q[0][0]=1;

	nc:c++;
	if(c==8)
		goto print;
	r=-1;

	nr:r++;
	if(r==8)
		goto backtrack;
	//row tests
	for(int i=0;i<c;i++)
	{
		if(q[r][i]==1)
			goto nr;
	}
	//upper diagonal
	for(int i=0;(r-i)>=0 && (c-i)>=0;i++)
	{
		if(q[r-i][c-i]==1)
			goto nr;
	}
	//lower diagonal
	for(int i=0;(r+i)<=7 && (c-i)>=0;i++)
	{
		if(q[r+i][c-i]==1)
			goto nr;
	}

	q[r][c]=1;
	goto nc;

	backtrack:c--;
	if(c==-1)
		return 0;
	r=0;

	while(q[r][c]!=1)
		r++;
	q[r][c]=0;
	goto nr;

	print:
	cout<<"Solution #"<<++count<<endl;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<q[i][j]<<" ";
		}
	cout<<endl;
	}

	goto backtrack;
}
