# include<iostream>
using namespace std;
int main()
{
    int row,col;
    cout<<" enter the nmber of rows and columns";
    cin>>row>>col;
    for(int i=1;i<=row;i++)
    {
        

        if(i==1 || i==row)
        {
            for(int j=1; j<=col;j++)
            cout<<"*";
            cout<<endl;

        }
        else if (1<i<row)
        {
            for(int j=1; j<=col;j++)
            {
                if(j==1 || j==col)
                cout<<"*";
                else cout<<" ";
                
            }
            cout<<endl;


        }
        
    }

    return 0;

}